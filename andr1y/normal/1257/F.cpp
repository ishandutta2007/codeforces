#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 103
#define INF 101111111111111
using namespace std;
ll a[N];
map<vector<ll>, pair<bool, ll>> mp;
vector<ll> invert(vector<ll> a){
	vector<ll> b;
	for(auto i : a) b.pb(-i);
	return b;
}
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++) cin >> a[i];
	for(ll i = 0;i<(1<<15);i++){
		ll cnt[n] = {0};
		for(ll j =0;j<n;j++) cnt[j] = __builtin_popcountll((a[j]>>15)^i);
		vector<ll> x;
		for(ll j =1;j<n;j++) x.pb(cnt[0]-cnt[j]);
		mp[x] = {true, i};
	}

	for(ll i = 0;i<(1<<15);i++){
		ll cnt[n] = {0};
		for(ll j =0;j<n;j++) cnt[j] = __builtin_popcountll((a[j]&((1<<15)-1))^i);
		vector<ll> x;
		for(ll j =1;j<n;j++) x.pb(cnt[j]-cnt[0]);
		if(mp[x].x){
			cout << (mp[x].y<<15)+i << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
}