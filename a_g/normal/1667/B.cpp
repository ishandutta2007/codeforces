#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3, -INF);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] = max(arr[index], val);
      }
    }
    T query(int index) {
      T sum = -INF;
      for (; index > 0; index -= (index & (-index))) {
        sum = max(sum, arr[index]);
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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> sums(n+1);
    for (int i = 0; i < n; i++) {
      sums[i+1] = sums[i] + a[i];
    }
    vector<long long> compressor = sums;
    sort(compressor.begin(), compressor.end());
    compressor.resize(unique(compressor.begin(), compressor.end())-compressor.begin());
    for (long long& s: sums) {
      s = lower_bound(compressor.begin(), compressor.end(), s)-compressor.begin()+2;
    }
    vector<int> dp(n+1);
    fenwick<int> fenw(n);
    dp[0] = 0;
    fenw.add(sums[0], 0);
    for (int i = 1; i <= n; i++) {
      dp[i] = max(dp[i-1]-(sums[i-1] > sums[i] ? 1 : 0), fenw.query(sums[i]-1)+i);
      fenw.add(sums[i], dp[i]-i);
    }
    cout << dp[n] << '\n';
  }
}