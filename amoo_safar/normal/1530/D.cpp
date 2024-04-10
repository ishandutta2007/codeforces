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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N], b[N];

vector<int> G[N];
int mk[N], vis[N];

int DFS(int u){
	vis[u] = 1;
	int rm = u;
	for(auto adj : G[u]){
		if(vis[adj]) continue;
		b[adj] = rm;
		rm = DFS(adj);
	}
	return rm;
}

int Main(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++) G[i].clear();
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(G[a[i]].empty()) ans ++;

		G[a[i]].pb(i);
	}
	fill(mk, mk + n + 2, 0);
	fill(vis, vis + n + 2, 0);
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		int nw = i;
		mk[nw] = 1;
		int rt = -1;
		while(rt == -1){
			nw = a[nw];
			if(mk[nw]) rt = nw;
			mk[nw] = 1;
		}
		vector<int> P;
		nw = rt;
		while(true){
			P.pb(nw);
			nw = a[nw];
			if(nw == rt) break;
		}
		// int fl = 0;
		int la = P.back();
		for(auto x : P){
			if((int) G[x].size() > 1){
				rt = la;
			}
			la = x;
		}
		// debug(rt);
		b[rt] = DFS(rt);
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) cout << b[i] << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		Main();
	}
	return 0;
}