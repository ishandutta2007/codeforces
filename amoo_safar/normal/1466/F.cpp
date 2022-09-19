// vaziat meshki-ghermeze !
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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 60;


int mk[N];
int par[N];
int Find(int u){
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}
void Unite(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return ;
	par[u] = v;
	mk[v] |= mk[u];
}
int Main(){
	int n, m;
	cin >> n >> m;
	fill(mk + 1, mk + m + 1, 0);
	iota(par + 1, par + m + 1, 1);
	
	int k, u, v;
	vector<int> A;
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		cin >> k;
		if(k == 1){
			cin >> u;
			if(!mk[Find(u)]){
				ans = (2 * ans) % Mod;
				A.pb(i);
				mk[Find(u)] = 1;
			}
		} else {
			cin >> u >> v;
			u = Find(u); v = Find(v);
			if(u == v) continue;
			if(mk[u] && mk[v]) continue;
			Unite(u, v);
			A.pb(i);
			ans = (2 * ans) % Mod;
		}
	}
	cout << ans << ' ';
	cout << A.size() << '\n';
	for(auto x : A) cout << x << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}