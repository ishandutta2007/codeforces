#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class fenwick {
  public:
    vector<int> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, int val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
        arr[index] %= MOD;
      }
    }
    int query(int index) {
      if (!index) return 0;
      int sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
        sum %= MOD;
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> compressor;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      compressor[a[i]].push_back(i);
    }
    int id = 0;
    for (auto &p: compressor) {
      while (p.second.size()) {
        a[p.second.back()] = id++;
        p.second.pop_back();
      }
    }

    vector<int> b(n);
    vector<int> ainv(n);
    vector<int> binv(n);
    for (int i = 0; i < n; i++) {
      b[i] = n-1-a[n-1-i];
      ainv[a[i]] = i;
      binv[b[i]] = i;
    }

    fenwick ft(n);
    vector<int> dp(n);

    fenwick ft2(n);
    vector<int> dp2(n);
    for (int i = 0; i < n; i++) {
      dp[ainv[i]] = ft.query(ainv[i]) + 1;
      ft.add(ainv[i]+1, dp[ainv[i]]);
      dp2[binv[i]] = ft2.query(binv[i]) + 1;
      ft2.add(binv[i]+1, dp2[binv[i]]);
    }

    fenwick ft3(n);
    vector<int> dp3(n);
    int prev = n;
    for (int i = 0; i < n; i++) {
      if (b[i] < prev) {
        for (int j = b[i]; j < prev; j++) {
          dp3[binv[j]] = ft3.query(binv[j]) + (j == b[i] ? 1 : 0);
          ft3.add(binv[j]+1, dp3[binv[j]]);
        }
        for (int j = prev-1; j >= b[i]; j--) {
          ft3.add(binv[j]+1, -dp3[binv[j]]);
        }
        prev = b[i];
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += 1LL * dp[i] * (dp2[n-1-i]-dp3[n-1-i]) % MOD;
      ans %= MOD;
    }
    cout << (ans+MOD)%MOD << '\n';
  }
}