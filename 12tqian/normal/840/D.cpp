#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
 #pragma GCC optimization ("O3")
 #pragma GCC target ("sse4")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
 
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
}
 
using namespace modop;
 
 
 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
vi cols[300005];
pii nc[300005];
bool vis[300005];
int mk[300005];
int cnt = 0;
const int C = 500;
 
int bins(int x, int c) {
  int l = 0, r = cols[c].size();
  while (l < r) {
    int m = (l + r) / 2;
    if (cols[c][m] >= x) r = m;
    else l = m + 1;
  }
 
  return l;
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 scanf("%d %d", &n, &Q);
//  cin >> n >> Q;
//  ai(a, n);
//  for (int ele = 0; ele < n; ele++) cin >> a[ele];
  for(int ele = 0; ele<n; ele++){
      scanf("%d", &a[ele]);
  }
  f0r(i, n) cols[--a[i]].pb(i);
  f0r(i, n) nc[i].s = i;
  f0r(i, n) ++nc[a[i]].f;
  sort(nc, nc + n);
  reverse(nc, nc + n);
  ms(vis, 0);
 
  f0r(i, Q) {
      scanf("%d %d %d", &l, &r, &x);
  //  cin >> l >> r >> x;
    --l; --r;
    int v = (r - l + 1) / x + 1;
 
    int res = -1;
 
    if (v >= C) {
      int pt = -1;
      while (nc[++pt].f >= v) {
        int col = nc[pt].s;
 
        int val = bins(r + 1, col) - bins(l, col);
        if (val >= v) {
          if (res == -1) res = col + 1;
          else res = min(res, col + 1);
        }
      }
    } else {
      cnt = 0;
      for (int j = l; j <= r; j++) {
        int col = a[j];
        if (vis[col]) continue;
        vis[col] = 1;
        mk[cnt++] = col;
 
        int val = bins(r + 1, col) - bins(l, col);
        if (val >= v) {
          if (res == -1) res = col + 1;
          else res = min(res, col + 1);
        }
      }
 
      for (int j = 0; j < cnt; j++) vis[mk[j]] = 0;
    }
 
    cout << res << '\n';
  }
}