#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX_P = 35000;

int sieve [MAX_P];
vector<int> smallp;
vector<pair<int, int>> factors (int x) {
  vector<pair<int, int>> ans;
  for (int p : smallp) {
    if (x % p == 0) {
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        cnt++;
      }
      ans.push_back(make_pair(p, cnt));
    }
  }

  if (x != 1) {
    ans.push_back(make_pair(x, 1));
  }
  return ans;
}

const int MAX_N = 5005;
const int MAX_L = 10;
const int INF = 1e9 + 5;

int arr [MAX_N];

int bars [MAX_L][MAX_N];
int curmn [MAX_L];
bool isbad [MAX_L];

int warr [MAX_N];
int cwarr [MAX_N];
int dp [MAX_N];

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  set<int> bad;
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    
    bad.insert(p);
  }

  map<int, int> idx;
  {
    auto fcs = factors(arr[0]);
    for (auto pr : fcs) {
      int cur_idx = idx.size();
      idx[pr.first] = cur_idx;
      curmn[cur_idx] = pr.second;
      isbad[cur_idx] = bad.count(pr.first);
    }
  }

  int baseline = 0;
  for (int i = 0; i < n; i++) {
    auto fcs = factors(arr[i]);
    for (auto pr : fcs) {
      int prime = pr.first;
      int cnt = pr.second;

      if (idx.count(prime)) {
        int cur_idx = idx[prime];
        bars[cur_idx][i] = min(curmn[cur_idx], cnt);
        cnt -= bars[cur_idx][i];
      }

      if (bad.count(prime)) {
        baseline -= cnt;
      } else {
        baseline += cnt;
      }
    }

    for (int j = 0; j < MAX_L; j++) {
      curmn[j] = min(curmn[j], bars[j][i]);
    }
  }

  for (int k = 0; k < MAX_L; k++) {
    for (int i = 0; i < n; i++) {
      if (isbad[k]) {
        warr[i] -= bars[k][i];
      } else {
        warr[i] += bars[k][i];
      }
    }
  }

  cwarr[0] = warr[0];
  for (int i = 1; i <= n; i++) {
    cwarr[i] = cwarr[i - 1] + warr[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    dp[i] = -INF;
    for (int j = i + 1; j <= n; j++) {
      dp[i] = max(dp[i], dp[j] + cwarr[j] - cwarr[i] - (j - i) * warr[j]);
    }
  }

  int ans = -INF;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[i] + cwarr[i] - (i + 1) * warr[i]);
  }

  cout << ans + baseline << endl;
}