#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
// source: medium_waxberry (https://codeforces.com/problemset/submission/1586/132239647)

// range add, point query
class fenwick {
  public:
    vector<int> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, int val) {
      for (; index > 0; index -= (index & (-index))) {
        arr[index] += val;
        arr[index] %= MOD;
      }
    }
    int query(int index) {
      int sum = 0;
      for (; index < arr.size(); index += (index & (-index))) {
        sum += arr[index];
        sum %= MOD;
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, bool>> tasks(n);
  for (int i = 0; i < n; i++) {
    cin >> get<1>(tasks[i]) >> get<0>(tasks[i]);
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int s;
    cin >> s;
    get<2>(tasks[s-1]) = 1;
  }
  sort(tasks.begin(), tasks.end());

  fenwick ft(2*n);
  vector<int> dp(n);
  ft.add(2*n, 1);
  for (int i = 0; i < n; i++) {
    int u = get<1>(tasks[i]);
    dp[i] = ft.query(u);
    ft.add(u, dp[i]);
  }
  int ans = 0;
  int prev = 1;
  for (int i = n-1; i >= 0; i--) {
    int u = get<1>(tasks[i]);
    ft.add(u, -dp[i]);
    if (get<2>(tasks[i]) && u >= prev) {
      ans += ft.query(prev);
      prev = u;
      ans %= MOD;
    }
  }
  cout << (ans+MOD)%MOD << endl;
}