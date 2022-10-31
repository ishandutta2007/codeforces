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
#define N 200000
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
ll pd[N];
void pdc(ll v, ll p = -1){
	pd[v] = 1;
	for(auto i : d[v]){
		if(i == p) continue;
		pdc(i, v);
		pd[v] += pd[i];
	}
}
ll dfs(ll v, ll p = 1){
	ll res = 0;
	for(auto i : d[v]){
		if(i==p) continue;
		if(pd[i]%2 == 0) res++;
		res += dfs(i, v);
	}
	return res;
}
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n-1;i++){
		ll a, b;
		cin >> a >> b;
		d[a].pb(b);
		d[b].pb(a);
	}
	if(n%2 == 1){
		cout << -1;
		exit(0);
	}else{
		pdc(1);
		cout << dfs(1) << endl;
	}
}