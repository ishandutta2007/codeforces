#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 16;

vector<int> g[N];
vector<string> blocks[N];

vector<int> top_sort;
bool used[N];
void dfs(int v) {
  used[v] = true;
  for (auto u: g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  top_sort.push_back(v);
}

void my_sort(vector<int>& perm, int l, int r, int level, int num) {
  if (l == r) {
    return;
  }
  int m = (l + r) / 2;
  my_sort(perm, l, m, level + 1, num * 2);
  my_sort(perm, m + 1, r, level + 1, num * 2 + 1);
  //blocks[level][num];
  vector<int> tmp;
  int p1 = l;
  int p2 = m + 1;
  for (auto c: blocks[level][num]) {
    if (c == '0') {
      g[perm[p1]].push_back(perm[p2]);
      tmp.push_back(perm[p1]);
      p1++;
    } else {
      g[perm[p2]].push_back(perm[p1]);
      tmp.push_back(perm[p2]);
      p2++;
    }
  }
  while (p1 <= m) {
    tmp.push_back(perm[p1++]);
  }
  while (p2 <= r) {
    tmp.push_back(perm[p2++]);
  }
  copy(tmp.begin(), tmp.end(), perm.begin() + l);
}

void process(int l, int r, int& ptr, string& s, int level) {
  if (l == r) return;
  int m = (l + r) / 2;
  process(l, m, ptr, s, level + 1);
  process(l, m, ptr, s, level + 1);
  int goal_0 = m - l + 1;
  int goal_1 = r - (m + 1) + 1;

  int init_ptr = ptr;
  int cnt0 = 0, cnt1 = 0;
  while (cnt0 < goal_0 && cnt1 < goal_1) {
    if (s[ptr] == '0') cnt0++; else cnt1++;
    ptr++;
  }
  blocks[level].push_back(s.substr(init_ptr, ptr - init_ptr));
}

void solve() {
  string s;
  cin >> s;
  int ptr = 0;
  process(0, N - 1, ptr, s, 0);

  /*
  int ptr = 0;
  for (int j = 0; j <= 3; ++j) {
    int cnt = (1 << j);
    int blcks = N / 2 / cnt;
    for (int i = 0; i < blcks; ++i) {
      int init_ptr = ptr;
      int cnt0 = 0, cnt1 = 0;
      while (cnt0 < cnt && cnt1 < cnt) {
        if (s[ptr] == '0') cnt0++; else cnt1++;
        ptr++;
      }
      blocks[j].push_back(s.substr(init_ptr, ptr - init_ptr));
    }
  }
  */

  /*
  for (int i = 0; i <= 3; ++i) {
    cout << "i: " << i << endl;
    for (auto x: blocks[i]) cout << x << " ";cout << endl << endl;
  }
  */

  vector<int> perm(N);
  iota(perm.begin(), perm.end(), 0);
  my_sort(perm, 0, N - 1, 0, 0);

  int root = -1;
  for (int i = 0; i < N; ++i) {
    bool fnd = false;
    for (int v = 0; v < N; ++v) {
      for (auto u: g[v]) {
        if (u == i) {
          fnd = true;
          break;
        }
      }
    }
    if (!fnd) {
      root = i;
      break;
    }
  }
  assert(root != -1);
  dfs(root);
  reverse(top_sort.begin(), top_sort.end());
  vector<int> ans(N);
  assert((int)top_sort.size() == N);
  for (int i = 0; i < N; ++i) {
    ans[top_sort[i]] = i + 1;
  }
  cout << ans.size() << endl;
  for (auto x: ans) {
    cout << x << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}