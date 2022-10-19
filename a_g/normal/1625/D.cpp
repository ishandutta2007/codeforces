#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int a[N];
int n, k;

vector<vector<int>> split(vector<int>&p, int i) {
  vector<vector<int>> ans(2);
  for (int index: p) {
    if (a[index]&(1<<i)) ans[1].push_back(index);
    else ans[0].push_back(index);
  }
  return ans;
}

vector<int> solve2(vector<int>& p, vector<int>& q, int i) {
  // pick at most one index from p and one index from q with XOR exceeding k
  if (!p.size() && !q.size()) return {};
  if (!p.size()) return {q[0]};
  if (!q.size()) return {p[0]};
  if (i == -1) {
    return {p[0], q[0]};
  }

  vector<vector<int>> pparts = split(p, i);
  vector<vector<int>> qparts = split(q, i);
  if (k&(1<<i)) {
    vector<int> ans1 = solve2(pparts[0], qparts[1], i-1);
    vector<int> ans2 = solve2(pparts[1], qparts[0], i-1);
    if (ans1.size() >= ans2.size()) return ans1;
    return ans2;
  }
  if (pparts[0].size() && qparts[1].size()) return {pparts[0][0], qparts[1][0]};
  if (pparts[1].size() && qparts[0].size()) return {pparts[1][0], qparts[0][0]};
  return solve2(p, q, i-1);
}

vector<int> solve1(vector<int>& p, int i) {
  if (!p.size()) return {};
  if (i == -1) {
    return p;
  }

  vector<vector<int>> parts = split(p, i);
  if (k&(1<<i)) {
    return solve2(parts[0], parts[1], i-1);
  }
  vector<int> ans;
  for (int j = 0; j < 2; j++) {
    for (int val: solve1(parts[j], i-1)) ans.push_back(val);
  }
  return ans;
}

vector<int> solve_naive() {
  vector<int> ans;
  for (int mask = 0; mask < (1<<n); mask++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
      if (mask&(1<<i)) subset.push_back(i+1);
    }
    int m = subset.size();
    bool good = 1;
    for (int i = 0; good && i < m; i++) {
      for (int j = i+1; good && j < m; j++) {
        if ((a[subset[i]]^a[subset[j]]) < k) {
          good = 0;
        }
      }
    }
    if (good && m > ans.size()) ans = subset;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  vector<int> ans = solve1(p, 30);
  if (ans.size() <= 1) {
    cout << "-1\n";
    return 0;
  }
  cout << ans.size() << '\n';
  for (int val: ans) cout << val << ' ';
  cout << '\n';

  /*
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int trials = 20000;
  while (trials--) {
    for (int i = 1; i <= n; i++) {
      a[i] = rng()%16;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    vector<int> ans = solve1(p, 30);

    vector<int> ans2 = solve_naive();
    if (ans.size() != ans2.size()) {
      cout << ans.size() << " " << ans2.size() << '\n';
      for (int i = 1; i <= n; i++) cout << a[i] << ' ';
      cout << '\n';
    }
  }
  */
}