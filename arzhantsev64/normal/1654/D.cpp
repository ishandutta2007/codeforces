#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct edge {
	int v, to;
	ll x, y;
};

int n;
vector<vector<edge>> G;

const int mod = 998244353;
long long ans = 0;

ll qpow(ll x, ll a) {
    if (a == 0)
        return 1;
    else if (a % 2 == 1)
        return (x * qpow(x, a - 1)) % mod;
    else {
        ll h = qpow(x, a / 2);
        return (h * h) % mod;
    }
}

ll inv(int x) {
    return qpow(x, mod - 2);
}

unordered_map<int, int> pows;
unordered_map<int, int> min_pows;

#define rep(i,a,n) for(auto i=a;i<=n;i++)
using LL = __int128;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000;
const int inf = 0x3f3f3f3f;

ll mul(ll a, ll b, ll mod) {
    ll q = (ldb) a * b / mod;
    ll r = a * b - mod * q;
    while (r < 0) r += mod;
    while (r >= mod) r -= mod;
    return r;
}
 
ll powerLL(ll a, ll n, ll mod) {
    if (!n) return 1;
    ll b = powerLL(a, n / 2, mod);
    b = (__int128)b * b % mod;
    return n & 1 ? ((__int128)a * b % mod) : b; 
}
 
bool test(ll n,int a)
{
    if(n==a) return 1;
    if(n%2==0) return 0;
    ll d = (n-1)>>__builtin_ctzll(n-1);
    ll r = powerLL(a,d,n);
    while(d<n-1 && r!=1 && r!=n-1)
    {
        d <<= 1;
        r = mul(r,r,n);
    }
    return r==n-1 || d%2;
}
bool miller(ll x)
{
    if(x==2) return 1;
    vi b({2,3,5,7,11,13});
    for(auto p: b) if(test(x,p)==0) return 0;
    return 1;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myrand(ll l,ll r) {return l+rng()%(r-l+1);}
ll pollard(ll n) 
{ // return some nontrivial factor of n
    auto f = [n](ll x) { return ((LL)x * x + 1) % n; };
    ll x = 0, y = 0, t = 30, prd = 2;
    while (t++ % 40 || __gcd(prd, n) == 1) 
    { /// speedup: don't take gcd every it
        if (x==y) x = myrand(2,n-1), y = f(x);
        ll tmp = mul(prd, abs(x-y), n);
        if (tmp) prd = tmp;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

vector<ll> w;
void factorization(ll n)
{
    if(n==1) return;
    if(miller(n)) w.push_back(n);
    else
    {
        ll x=pollard(n);
        factorization(x); factorization(n/x);
    }
}

vector<ll> factors(ll n) {
    w.clear();
    factorization(n);
    return w;
}

void dfs(int v, int p, ll cur, edge e) {
	auto factors_y = factors(e.y);
	auto factors_x = factors(e.x);
	for (int i : factors_y) {
		if (pows.find(i) == pows.end()) {
			min_pows[i] = 0;
			pows[i] = 0;
		}
		pows[i]++;
	}
	for (int i : factors_x) {
		if (pows.find(i) == pows.end()) {
			min_pows[i] = 0;
			pows[i] = 0;
		}
		pows[i]--;
		if (min_pows[i] > pows[i])
			min_pows[i] = pows[i];
	}
	// for (auto p : pows)
		// cout << p.first << '^' << p.second << ' ';
	// cout << endl;
	cur = (cur * e.y) % mod;
	cur = (cur * inv(e.x)) % mod;
	// cout << (cur * 60) % mod << endl;
	ans = (ans + cur) % mod;
	for (auto e : G[v]) {
		if (e.to != p)
			dfs(e.to, v, cur, e);
	}
	for (int i : factors_y)
		pows[i]--;
	for (int i : factors_x)
		pows[i]++;
}

void solve() {
	cin >> n;
	ans = 0;
	G.clear();
	pows.clear();
	min_pows.clear();
	G.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		u--; v--;
		G[u].push_back({u, v, x, y});
		G[v].push_back({v, u, y, x});
	}
	dfs(0, -1, 1, {-1, -1, 1, 1});
	// cout << (ans * 60) % mod<< '\n';
	for (auto p : min_pows) {
		if (p.second < 0) {
			ans = (ans * qpow(p.first, -p.second)) % mod;
			// cout << p.first << ' ' << -p.second << endl;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}