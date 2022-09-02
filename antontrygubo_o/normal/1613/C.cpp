

#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define ll 				long long
#define ld 				long double
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii               map<ll,ll>
#define pqi             priority_queue<ll>			//max pq
#define pqd             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define MOD             1000000007
#define inf             2e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pw(b,p)         pow(b,p) + 0.1
#define f(i,k,n)		for(ll i=k;i<n;i++)
#define fd(i,start,end)	for(ll i=start;i>=end;i--)
#define LSOne(S) (S & (-S))

ll power(ll a, ll b, ll mod) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll power(ll a, ll b) {ll res = 1; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a ; a = a * a;} return res;}
ll min( ll a,  ll b) { return (a < b) ? a : b;}
ll max(ll a, ll b) {return (a > b) ? a : b;}
ll gcd (ll a, ll b) {if (a == 0) return  b; return gcd(b % a, a);}


ll mul(ll a, ll b) {
	return (1LL * a * b) % MOD;
}

ll add(ll a, ll b) {
	ll s = (a + b);
	if (s >= MOD) s -= MOD;
	return s;
}

ll sub(ll a, ll b) {
	ll s = (a + MOD - b);
	if (s >= MOD) s -= MOD;
	return s;
}


void bwayne()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


// ll n;
// cin >> n;
// vi a(n);
// f(i, 0, n) {
// 	cin >> a[i];
// }

// vector<vi> a(n,vector<ll>(m,0));
// f(i,0,n){
// 	f(j,0,m){
// 		cin>>a[i][j];
// 	}
// }

bool poss(vi &a, ll val, ll h) {
	ll ans = 0;
	ll n = a.size();
	fd(i, n - 1, 0) {
		ll maxx = inf;
		if (i + 1 < n) {
			maxx = a[i + 1] - 1;
		}
		ans += min(a[i] + val - 1, maxx) - a[i] + 1;
		if (ans >= h) return true;
	}
	if (ans >= h) return true;
	return false;
}

void solve() {






	ll n, h;
	cin >> n >> h;
	vi a(n);
	f(i, 0, n) {
		cin >> a[i];
	}

	ll low = 0, high = 1e18, ans = inf;
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		if (poss(a, mid, h)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans << endl;



}

int main()
{
	bwayne();// remember
	ll t = 1;
	cin >> t;

	for (ll tt = 1; tt <= t; tt++)
	{
		// cout << "Case #" << tt << ": ";
		solve();
	}

	return 0;
}