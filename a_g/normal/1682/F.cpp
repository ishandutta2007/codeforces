#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+5;
long long b[N];
int a[N], ad[N], dp[N], s[N];

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n-1; i >= 1; i--) {
    ad[i] = (a[i]-a[i-1])%MOD;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += b[i-1];
  }

  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 1);
  sort(indices.begin(), indices.end(), [&] (int x, int y) {return b[x] > b[y];});
  for (int i = 1; i <= n; i++) {
    b[i] %= MOD;
  }

  for (int i = 1; i <= n; i++) {
    s[i] = (s[i-1]+1LL*ad[i]*b[i])%MOD;
  }

  fenwick<int> seen(n);
  fenwick<long long> z(n);

  for (int j: indices) {
    dp[j] = (1LL*(a[j-1]-2*seen.query(j))*b[j]%MOD + z.query(j) - s[j-1]) % MOD;
    z.add(j, 2LL*ad[j]*b[j] % MOD);
    seen.add(j, ad[j]);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    assert(b[l-1]==b[r]);
    cout << (0LL+dp[r]-dp[l-1]+2*MOD)%MOD << '\n';
  }
}