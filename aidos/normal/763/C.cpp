//Solution by Zhusupov Nurlan
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define endl '\n'
#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define mp make_pair

LL a[sz], mx, mi, d, sum, c, n, m, x;
unordered_map <int, int> cnt;

LL bin_pow(LL x, LL y) {
  LL res = 1;
  while (y) {
    if (y & 1) res = res * x % m;
    y >>= 1;
    x = x * x % m;
  }
  return res;
}

int main()
{
//    freopen(fname"in", "r", stdin);
//    freopen(fname"out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    sum += a[i];
  }

  if (cnt.size() == 1) {
    cout << a[1] << " " << 0;
    return 0;
  }
  random_shuffle(a + 1, a + 1 + n);

  if (n == m) {
    cout << 0 << " " << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    d = (sum - a[i] * 1ll * n + m) % m * bin_pow(((n - 1) * 1ll * n / 2) % m, m - 2) % m;
    d = (d + m) % m;
    if (d == 0) continue;
    x = a[i];
    c = 0;
    
    if(cnt.count((x-d + m) % m)) continue;
    while (c < n) {
      if (!cnt.count(x)) break;
      x += d;
      if (x >= m) x-= m;
      c++;
    }
    if (c == n) {
      cout << a[i] << " " << d;
      return 0;
    }
  }

  cout << -1;

}