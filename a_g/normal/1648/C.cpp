#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5+5;
int inv[N];
int fact[N];
int invfact[N];

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

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  fenwick<int> fenw(N);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    fenw.add(s[i], 1);
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  int denom = 1;
  for (int i = 1; i < N; i++) {
    int u = fenw.query(i)-fenw.query(i-1);
    denom = 1LL * denom * invfact[u] % MOD;
  }

  int ans = 0;
  for (int i = 0; i < min(m, n+1); i++) {
    // first i letters match
    // n-i letters of s to choose
    if (i == n) {
      ans = (ans+1) % MOD;
      break;
    }
    int smaller_letters = fenw.query(t[i]-1);
    int term = 1;
    for (int j: {smaller_letters, denom, fact[n-i-1]}) {
      term = 1LL * j * term % MOD;
    }
    ans = (ans + term) % MOD;
    int u = fenw.query(t[i]) - fenw.query(t[i]-1);
    if (!u) break;
    denom = 1LL * u * denom % MOD;
    fenw.add(t[i], -1);
  }
  cout << ans << '\n';
}