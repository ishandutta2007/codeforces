// nemibinam invara kasi mesle khodemono !
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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 522133279;
const ll Log = 20;

int n, m;
int dis[Log][N];
typedef pair<int, int> pii;
vector<int> O[N], I[N];


pii Q[Log * N];
int l = 0, r = 0;

//////////////////
pii ds[2][N];
set< pair<pii, pii> > st;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		O[u].pb(v);
		I[v].pb(u);
	}
	memset(dis, 31, sizeof dis);
	//debug(dis[0][0]);
	//debug(      Inf);
	dis[0][1] = 0;
	Q[0] = {0, 1};
	r = 1;
	
	pii fr;
	while(l < r){
		fr = Q[l]; l++;
		//cerr << "! " << fr.F << ' ' << fr.S << '\n';
		if((fr.F + 1 < Log) && (dis[fr.F][fr.S] + 1 < dis[fr.F + 1][fr.S]) ){
			Q[r ++] = {fr.F + 1, fr.S};
			dis[fr.F + 1][fr.S] = dis[fr.F][fr.S] + 1;
		}
		if(fr.F % 2 == 0){
			for(auto adj : O[fr.S]){
				if(dis[fr.F][adj] > dis[fr.F][fr.S] + 1){
					Q[r ++] = {fr.F, adj};
					dis[fr.F][adj] = dis[fr.F][fr.S] + 1;
				}
			}
		} else {
			for(auto adj : I[fr.S]){
				if(dis[fr.F][adj] > dis[fr.F][fr.S] + 1){
					Q[r ++] = {fr.F, adj};
					dis[fr.F][adj] = dis[fr.F][fr.S] + 1;
				}
			}
		}
	}
	ll ans = Inf;
	for(int i = 0; i < Log; i++){
		ans = min(ans, (ll)(dis[i][n]-i) + ((1 << i) - 1));
	}
	if(ans != Inf){
		cout << ans << endl;
		return 0;
	}

	////////////////////
	fill(ds[0], ds[0] + N, pii(Inf, Inf));
	fill(ds[1], ds[1] + N, pii(Inf, Inf));
	ds[0][1] = {0, 0};
	st.insert({ds[0][1], {0, 1}});

	while(!st.empty()){
		fr = st.begin() -> S;
		st.erase(st.begin());
		pii D = ds[fr.F][fr.S];
	
		if((ds[fr.F ^ 1][fr.S] > pii(D.F + 1, D.S)) ){
			st.erase({ds[fr.F ^ 1][fr.S], {fr.F ^ 1, fr.S}});
			ds[fr.F ^ 1][fr.S] = pii(D.F + 1, D.S);
			st.insert({ds[fr.F ^ 1][fr.S], {fr.F ^ 1, fr.S}});
		}
		if(fr.F == 0){
			for(auto adj : O[fr.S]){
				if(ds[fr.F][adj] > pii(D.F, D.S + 1)){
					st.erase({ds[fr.F][adj], {fr.F, adj}});
					ds[fr.F][adj] = pii(D.F, D.S + 1);
					st.insert({ds[fr.F][adj], {fr.F, adj}});
				}
			}
		} else {
			for(auto adj : I[fr.S]){
				if(ds[fr.F][adj] > pii(D.F, D.S + 1)){
					st.erase({ds[fr.F][adj], {fr.F, adj}});
					ds[fr.F][adj] = pii(D.F, D.S + 1);
					st.insert({ds[fr.F][adj], {fr.F, adj}});
				}
			}
		}
	}
	pii res = min(ds[0][n], ds[1][n]);
	ll ANS = 1;
	assert(res != pii(Inf, Inf));
	for(int i = 0; i < res.F; i++) ANS = (ANS + ANS) % Mod;
	ANS -= 1;
	ANS += res.S;
	cout << ANS % Mod << '\n';
	return 0;
}