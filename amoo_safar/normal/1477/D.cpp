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
const ll Log = 30;

int p[N], q[N];

vector<int> A, B, td[N], C[N], G[N];

int mk[N], T = 1;
int m2[N], T2 = 1;

int DFS(int u, int rt){ // 1 rem 0 off
	B.clear(); 
	td[u].clear();
	C[u].clear();


	mk[u] = T;

	T2 ++;
	for(auto adj : G[u]) m2[adj] = T2;
	for(auto adj : A){
		if(m2[adj] == T2) B.pb(adj);
		else {
			if(mk[adj] != T)
				td[u].pb(adj);
		}
	}
	A = B;
	int la = -1;
	for(auto adj : td[u]){
		int res = DFS(adj, 0);
		if(res == 1 && C[u].empty()) C[u].pb(u);
		if(res == 1) C[u].pb(adj);
		else la = adj;
	}
	if(!C[u].empty()) return 0;
	if(rt == 1){
		if(la == -1){
			C[u].pb(u);
			return 1;
		}
		// cerr << ""
		C[la].pb(u);
		return 0;
	}
	return 1;
}

int Main(){
	int n, m;
	cin >> n >> m;
	////////////////////
	for(int i = 1; i <= n; i++)
		G[i].clear();
	////////////////////

	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	A.clear(); B.clear();
	for(int i = 1; i <= n; i++) A.pb(i);
	T ++;
	for(int i = 1; i <= n; i++){
		if(mk[i] != T){
			DFS(i, 1);
		}
	}
	int nw = 1;
	for(int i = 1; i <= n; i++){
		if(C[i].empty()) continue;
		int sz = C[i].size();
		// cerr << "!! " << i << " -> ";
		for(int j = 0; j < sz; j++){
			p[C[i][j]] = nw;
			q[C[i][(j + 1) % sz]] = nw;
			// cerr << C[i][j] << ' ';
			// debug(nw);
			nw ++;
		}
		// cerr << '\n';
	}
	for(int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
	for(int i = 1; i <= n; i++) cout << q[i] << " \n"[i == n];
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}