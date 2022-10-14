#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 17, K = 500;

int mu[N];
vector <int> f[N];

void build() {
  fop (i,1,N) for (int j = i; j < N; j += i) f[j].pb(i);
  fop (i,1,N) {
    int tmp = i;
    mu[i] = 1;
    for (int j = 2; j * j <= i; ++j) if (tmp % j == 0) {
      mu[i] *= -1;
      tmp /= j;
      while (tmp % j == 0) mu[i] = 0, tmp /= j;
    }
    if (tmp > 1) mu[i] *= -1;
  }
}

int get(int a, int n) {
  int ans = 0;
  for (int i : f[a]) {
    ans += (n / i) * mu[i];
  }
  return ans;
}

lli modpow(lli a, int b) {
  lli ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  build();
  int n;
  cin >> n;
  lli dp[n + 1];
  dp[1] = 0;
  fop (i,2,n + 1) {
    dp[i] = 1;
    for (int j : f[i]) if (j ^ i) {
      int g = get(i / j, n / j);
      //cout << g << ' ' << i << ' ' << j << endl;
      dp[i] = (dp[i] + dp[j] * g % mod * modpow(n, mod - 2) % mod) % mod;
    }
    dp[i] = dp[i] * n % mod * modpow(n - n / i, mod - 2) % mod;
  }
  lli ans = 0;
  fop (i,1,n + 1) ans = (ans + dp[i]) % mod;
  ans = ans * modpow(n, mod - 2);
  cout << (ans + 1) % mod << endl;
}