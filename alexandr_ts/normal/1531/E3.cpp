#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 16;

class Solver {
public:
  Solver(int n): g(n), blocks(n + 10), block_ptr(n),used(n) {
  }

  void dfs(int v) {
    used[v] = true;
    for (auto u: g[v]) {
      if (!used[u]) {
        dfs(u);
      }
    }
    top_sort.push_back(v);
  }

  void my_sort(vector<int>& perm, int l, int r, int level) {
    if (r - l <= 1) {
      return;
    }
    int m = (l + r) / 2;
    my_sort(perm, l, m, level + 1);
    my_sort(perm, m, r, level + 1);
    //blocks[level][num];
    vector<int> tmp;
    int p1 = l;
    int p2 = m;
    for (auto c: blocks[level][block_ptr[level]]) {
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
    block_ptr[level]++;
    while (p1 < m) {
      tmp.push_back(perm[p1++]);
    }
    while (p2 < r) {
      tmp.push_back(perm[p2++]);
    }
    copy(tmp.begin(), tmp.end(), perm.begin() + l);
  }

  bool process(int l, int r, int& ptr, string& s, int level) {
    if (r - l <= 1) return true;
    int m = (l + r) / 2;
    if (!process(l, m, ptr, s, level + 1)) return false;
    if (!process(m, r, ptr, s, level + 1)) return false;
    int goal_0 = m - l;
    int goal_1 = r - m;

    int init_ptr = ptr;
    int cnt0 = 0, cnt1 = 0;
    while (cnt0 < goal_0 && cnt1 < goal_1) {
      if (ptr >= (int)s.size()) return false;
      if (s[ptr] == '0') cnt0++; else cnt1++;
      ptr++;
    }
    blocks[level].push_back(s.substr(init_ptr, ptr - init_ptr));
    return true;
  }

  vector<int> solve_one(string s, int n) {
    int ptr = 0;
    bool ok = process(0, n, ptr, s, 0);
    if (!ok) return {};
    if (ptr != (int)s.size()) return {};

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    my_sort(perm, 0, n, 0);

    int root = -1;

    vector<int> pow_in(n);
    for (int i = 0; i < n; ++i) {
      for (auto u: g[i]) {
        pow_in[u]++;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!pow_in[i]) {
        root = i;
        break;
      }
    }
    assert(root != -1);
    dfs(root);
    reverse(top_sort.begin(), top_sort.end());
    vector<int> ans(n);
    assert((int)top_sort.size() == n);
    for (int i = 0; i < n; ++i) {
      ans[top_sort[i]] = i + 1;
    }
    return ans;
  }

private:
  vector<vector<int>> g;
  vector<vector<string>> blocks;
  vector<int> block_ptr;

  vector<int> top_sort;
  vector<int> used;
};

string my_sort(vector<int>& perm, int l, int r) {
  if (r - l <= 1) {
    return "";
  }
  int m = (l + r) / 2;
  string ans = my_sort(perm, l, m);
  ans += my_sort(perm, m, r);
  vector<int> tmp;
  int p1 = l;
  int p2 = m;
  while (p1 < m && p2 < r) {
    if (perm[p1] < perm[p2]) {
      tmp.push_back(perm[p1]);
      ans += '0';
      p1++;
    } else {
      tmp.push_back(perm[p2]);
      ans += '1';
      p2++;
    }
  }
  while (p1 < m) {
    tmp.push_back(perm[p1++]);
  }
  while (p2 < r) {
    tmp.push_back(perm[p2++]);
  }
  copy(tmp.begin(), tmp.end(), perm.begin() + l);
  return ans;
}

bool validate(int n, vector<int> ans, string& s) {
  if (n != (int)ans.size()) return false;
  if (my_sort(ans, 0, n) != s) return false;
  set<int> ss;
  for (auto x: ans) {
    ss.insert(x);
  }
  if ((int)ss.size() != n) return false;
  return true;
}

int try_process(int l, int r, int& ptr, string& s, int level) {
  if (r - l <= 1) return 0;
  int m = (l + r) / 2;
  int rez1 = try_process(l, m, ptr, s, level + 1);
  if (rez1) {
    return rez1;
  }
  int rez2 = try_process(m, r, ptr, s, level + 1);
  if (rez2) {
    return rez2;
  }
  int goal_0 = m - l;
  int goal_1 = r - m;

  int cnt0 = 0, cnt1 = 0;
  while (cnt0 < goal_0 && cnt1 < goal_1) {
    if (ptr >= (int)s.size()) {
      return 1;
    }
    if (s[ptr] == '0') cnt0++; else cnt1++;
    ptr++;
  }
  return 0;
}

void solve() {
  string s;
  cin >> s;

  int tl = 1, tr = 1e5 + 2;
  while (tr - tl > 1) {
    int tm = (tl + tr) / 2;
    int ptr = 0;
    int rez = try_process(0, tm, ptr, s, 0);
    if (ptr < (int)s.size()) {
      rez = -1;
    }
    if (!rez) {
      tl = tr = tm;
    }
    if (rez == 1) {
      tr = tm;
    } else {
      tl = tm;
    }
  }
  int ptr = 0;
  int rez = try_process(0, tl, ptr, s, 0);
  assert(!rez && ptr == (int)s.size());

  Solver solver(tl);
  auto ans = solver.solve_one(s, tl);
  assert(!ans.empty());
  assert(validate(tl, ans, s));
  cout << tl << endl;
  for (auto x: ans) cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}