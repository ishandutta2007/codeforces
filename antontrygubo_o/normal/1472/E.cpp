#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define ll 				long long
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii               map<ll,ll>
#define pqi             priority_queue<ll>			//max pq
#define pqd             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define MOD             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pw(b,p)         pow(b,p) + 0.1
#define f(i,k,n)		for(ll i=k;i<n;i++)
#define fd(i,start,end)	for(ll i=start;i>=end;i--)

ll power(ll a, ll b, ll mod) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll power(ll a, ll b) {ll res = 1; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a ; a = a * a;} return res;}
ll min( ll a,  ll b) { return (a < b) ? a : b;}
ll max(ll a, ll b) {return (a > b) ? a : b;}
ll gcd (ll a, ll b) {if (a == 0) return  b; return gcd(b % a, a);}



void bwayne()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
}
// ll n;
// cin >> n;
// vi a(n);
// f(i, 0, n) {
// 	cin >> a[i];
// }

// vector<vi> a(n,vector<vi>(m,0));
// f(i,0,n){
// 	f(j,0,m){
// 		cin>>a[i][j];
// 	}
// }

struct node {
	int h, w, ind;
};
bool cmp(node a, node b) {
	if (a.w == b.w) {
		return a.h > b.h;
	}
	return a.w < b.w;
}


void solve() {
	ll n;
	cin >> n;
	vector<node> a(n);
	f(i, 0, n) {
		cin >> a[i].h >> a[i].w;
		if (a[i].h > a[i].w) {
			swap(a[i].h, a[i].w);
		}
		a[i].ind = i;

	}
	sort(a.begin(), a.end(), cmp);
	ll minht = inf;
	ll minind = -1;
	vector<int> ans(n, -1);
	for (int i = 0; i < n; i++) {
		if (minht < a[i].h) {
			ans[a[i].ind] = minind + 1;
		}
		if (a[i].h < minht) {
			minht = a[i].h;
			minind = a[i].ind;
		}
	}
	f(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;

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