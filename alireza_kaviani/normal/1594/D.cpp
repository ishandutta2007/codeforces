#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , flag , H[MAXN] , mark[MAXN] , cnt[2];
vector<pii> adj[MAXN];

void DFS(int v){
	mark[v] = 1;
	cnt[H[v]]++;
	for(pii i : adj[v]){
		int u = i.X , w = i.Y;
		if(mark[u]){
			if((H[v] + H[u] + w) % 2 != 0){
				flag = 1;
			}
			continue;
		}
		H[u] = (H[v] ^ w);
		DFS(u);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m; flag = 0;
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear(); H[i] = mark[i] = 0;
		}
		for(int i = 0 ; i < m ; i++){
			int v , u , w = 0;
			string s;
			cin >> v >> u >> s;
			if(s[0] == 'i')	w = 1;
			adj[v].push_back({u , w});
			adj[u].push_back({v , w});
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			if(mark[i])	continue;
			cnt[0] = cnt[1] = 0;
			DFS(i);
			ans += max(cnt[0] , cnt[1]);
		}
		cout << (flag ? -1 : ans) << endl;
	}

    return 0;
}
/*

*/