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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[N];
ll a[N], p[N];
queue<ll> q;
ll dis[N];


ll X[2];
pll fac(ll x){
	ll po = 0;
	X[0] = 1;
	X[1] = 1;
	while(x > 1){
		if(x % (p[x] * p[x]) == 0) x /= (p[x] * p[x]);
		else {
			X[po ++] = p[x];
			x /= p[x];
		}
	}
	return pll(X[0], X[1]);
}
vector<ll> A;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = N - 1; i >= 2; i--){
		for(int j = i; j < N; j += i) p[j] = i;
	}
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(fac(a[i]) == pll(1, 1)) return cout << "1\n", 0;
	}
	for(int i = 1; i <= n; i++){
		pll res = fac(a[i]);
		G[res.F].pb(res.S);
		G[res.S].pb(res.F);
		A.pb(res.F);
		A.pb(res.S);
		//cerr << res.F << " " << res.S << '\n';
	}
	sort(all(A));
	A.resize(unique(all(A)) - A.begin());
	ll ans = Inf;
	for(auto sc : A){
		if(sc > 1000) break;
		for(auto nd : A) dis[nd] = Inf;
		dis[sc] = 0;
		q.push(sc);
		while(!q.empty()){
			ll fr = q.front(); q.pop();
			for(auto adj : G[fr]){
				if(dis[adj] > dis[fr] + 1){
					dis[adj] = dis[fr] + 1;
					q.push(adj);
				} else {
					if(dis[adj] >= dis[fr]){
						ans = min(ans, 1 + dis[adj] + dis[fr]);
				//		cerr << dis[adj] << " " << dis[fr] << " " << sc << '\n';
					}
				}
			}
		}
	}
	cout << (ans == Inf ? -1 : ans);
	return 0;
}