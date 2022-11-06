#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

typedef vector< pair<int, int> > options; 

const int maxN = 14;
const int maxM = 2022;
const int maxK = 500;

int t, n, m, k, confs;
int v[maxN][maxM];
int simp[1 << maxN], id[1 << maxN];
vector<int> patterns;
vector< pair<int, int> > best[maxK];
options worth[maxM];
int local[maxK];
vector<int> rots[maxK][maxK];
int sums[1 << maxN];

void remove_duplicates(vector<int> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

int rot(int conf, int i) {
  int upper = (conf << i) & (confs - 1);
  int lower = (conf >> (n - i)) & ((1 << i) - 1);
  return lower | upper;
}

int simplify(int conf) {
  int answer = conf;

  for (int i = 1; i < n; i++) 
    answer = min(answer, rot(conf, i));

  return answer;
}

void preproc() {
  confs = 1 << n;
  patterns.clear();

  for (int conf = 0; conf < confs; conf++) {
    simp[conf] = simplify(conf);
    patterns.push_back(simp[conf]);
  }  

  remove_duplicates(patterns);

  k = patterns.size();
  for (int i = 0; i < k; i++)
    id[patterns[i]] = i;

  for (int i = 0; i < k; i++)
    best[i].clear();

  for (int j = 0; j < m; j++) {
    memset(local, 0, sizeof(local));

    for (int conf = 0; conf < confs; conf++) {
      int sum = 0;

      if (conf > 0) {
        int i = 0;
        while (((conf >> i) & 1) == 0) i++;
        sum = sums[conf ^ (1 << i)] + v[i][j];
      }
      sums[conf] = sum;
      
      int curr = id[simp[conf]];
      local[curr] = max(local[curr], sum);
    }

    for (int i = 0; i < k; i++)
      best[i].pb(mp(local[i], j));
  }

  for (int i = 0; i < k; i++) {
    int c1 = patterns[i];
    for (int j = 0; j < k; j++) {
      int c2 = patterns[j];

      rots[i][j].clear();

      for (int bits = 0; bits < n; bits++) {
        int cc2 = rot(c2, bits);
        if (c1 & cc2) continue;
        rots[i][j].pb(id[simp[c1 | cc2]]);
      }

      remove_duplicates(rots[i][j]);
    }
  }

  for (int i = 0; i < m; i++)
    worth[i].clear();

  for (int i = 0; i < k; i++) {
    if (best[i].size() > n) {
      nth_element(best[i].begin(), best[i].end() - n, best[i].end());
      //sort(best[i].begin(), best[i].end());
      reverse(best[i].begin(), best[i].end());
      best[i].resize(n);
    }

    for (auto e: best[i])
      worth[e.second].pb(mp(i, e.first));
  }
}

options combine(options as, options bs) {
  memset(local, 0, sizeof(local));

  for (auto e: as)
    local[e.first] = max(local[e.first], e.second);

  for (auto e: bs)
    local[e.first] = max(local[e.first], e.second);

  for (auto a: as) {
    int c1 = a.first;
    int v1 = a.second;

    for (auto b: bs) {
      int c2 = b.first;
      int v2 = b.second;
      
      for (auto dest: rots[c1][c2]) {
        local[dest] = max(local[dest], v1 + v2);
      }
    }
  }

  options answer = {};
  for (int i = 0; i < k; i++)
    if (local[i])
      answer.pb(mp(i, local[i]));

  return answer;
}

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    cin >> n >> m;
   
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++)
        cin >> v[i][j]; 

    preproc();
    
    options curr = {};
    curr.push_back(mp(0, 0));

    for (int j = 0; j < m; j++)
      if (worth[j].size() > 0)
        curr = combine(curr, worth[j]);

    int ans = 0;
    for (auto e: curr)
      ans = max(ans, e.second);

    cout << ans << '\n';
  }


  return 0;
}