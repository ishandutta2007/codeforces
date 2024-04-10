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

int q , n , inDeg[MAXN] , ans[MAXN];
vector<int> adj[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		queue<int> Q; int cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
			ans[i] = 0;
		}
		for(int i = 1 ; i <= n ; i++){
			cin >> inDeg[i];
			for(int j = 0 ; j < inDeg[i] ; j++){
				int x; cin >> x;
				adj[x].push_back(i);
			}
		}
		for(int i = 1 ; i <= n ; i++){
			if(inDeg[i] == 0){
				Q.push(i);
			}
		}
		int res = 0;
		while(!Q.empty()){
			int v = Q.front(); Q.pop();
			cnt++; res = max(res , ans[v]);
			for(int u : adj[v]){
				inDeg[u]--;
				ans[u] = max(ans[u] , ans[v] + (v > u));
				if(inDeg[u] == 0)	Q.push(u);
			}
		}
		if(cnt != n){
			cout << -1 << endl;
			continue;
		}
		cout << res + 1 << endl;
	}

    return 0;
}
/*

*/