#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

map<str, ll> mp;

vector<pll> V;
vector<ll> G[N];
vector<str> A;
ll mk[N];
void DFS(ll u){
	mk[u] = 1;
	for(auto adj : G[u]){
		if(!mk[adj]) DFS(adj);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	for(int i = 0; i < 6; i++) V.pb({i + 1, s[i]});
	ll cnt = 0;
	do {
		str t = "";
		for(auto x : V) t += x.S;
		if(mp[t] == 0){
			mp[t] = cnt + 1;
			cnt ++;
			A.pb(t);
		}
	} while(next_permutation(all(V)));
	str nx;
	for(auto y : A){
		nx = y;
		swap(nx[0], nx[2]);
		swap(nx[2], nx[1]);
		swap(nx[1], nx[3]);
		G[mp[y]].pb(mp[nx]);
		G[mp[nx]].pb(mp[y]);
		//cerr << nx << ' ' << y << '\n';
		nx = y;
		swap(nx[0], nx[4]);
		swap(nx[4], nx[1]);
		swap(nx[1], nx[5]);
		G[mp[y]].pb(mp[nx]);
		G[mp[nx]].pb(mp[y]);
		
		nx = y;
		swap(nx[3], nx[4]);
		swap(nx[4], nx[2]);
		swap(nx[2], nx[5]);
		G[mp[y]].pb(mp[nx]);
		G[mp[nx]].pb(mp[y]);
	}
	ll ans =0 ;
	for(int i = 1; i <= cnt; i++) if(!mk[i]){
		DFS(i);
		ans ++;
	}
	cout << ans << '\n';
	return 0;
}