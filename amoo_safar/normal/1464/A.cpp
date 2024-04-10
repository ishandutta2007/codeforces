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
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int mk[N], T = 1;
vector<int> V, G[N];
void DFS(int u){
	mk[u] = T;
	for(auto adj : G[u]){
		if(T != mk[adj])
			DFS(adj);
	}
	V.pb(u);
}

int Main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) G[i].clear();
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	T ++;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(mk[i] == T) continue;
		V.clear();
		DFS(i);
		if(V.size() == 1) continue;
		int sig =0;
		for(auto x : V) sig += G[x].size();
		ans += V.size() - 1;
		if(sig / 2 == V.size()){
			ans += 2;
		}
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}