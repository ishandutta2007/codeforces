#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , m , k , ptr , x[MAXN] , dp[MAXN];
vector<int> compress[MAXN] , ind[MAXN];
vector<pii> adj[MAXN];
vector<pair<pii , pair<pii , int>>> E;

int get(int x , int y){
	int pos = lower_bound(all(compress[x]) , y) - compress[x].begin();
	return ind[x][pos];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m >> k;
		E.clear(); ptr = 0;
		for(int i = 1 ; i <= n + 5 ; i++){
			compress[i].clear();
			ind[i].clear();
		}
		for(int i = 0 ; i <= 2 * k + 5 ; i++){
			dp[i] = INF;
			adj[i].clear();
		}
		for(int i = 1 ; i <= n ; i++)	cin >> x[i];
		for(int i = 0 ; i < k ; i++){
			int a , b , c , d , h;
			cin >> a >> b >> c >> d >> h;
			E.push_back({{a , b} , {{c , d} , h}});
			compress[a].push_back(b);
			compress[c].push_back(d);
		}
		compress[1].push_back(1);
		compress[n].push_back(m);
		for(int i = 1 ; i <= n ; i++){
			sort(all(compress[i]));
			compress[i].resize(unique(all(compress[i])) - compress[i].begin());
			for(int j = 0 ; j < SZ(compress[i]) ; j++){
				ind[i].push_back(ptr++);
			}
		}
		for(auto &i : E){
			int a = i.X.X , b = i.X.Y , c = i.Y.X.X , d = i.Y.X.Y , h = i.Y.Y;
			adj[get(c , d)].push_back({get(a , b) , h});
		}
		dp[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j : ind[i]){
				for(pii k : adj[j]){
					int u = k.X , w = k.Y;
					dp[j] = min(dp[j] , dp[u] - w);
				}
			}
			for(int j = 1 ; j < SZ(compress[i]) ; j++){
				dp[ind[i][j]] = min(dp[ind[i][j]] , dp[ind[i][j - 1]] + (compress[i][j] - compress[i][j - 1]) * x[i]);
			}
			for(int j = SZ(compress[i]) - 2 ; j >= 0 ; j--){
				dp[ind[i][j]] = min(dp[ind[i][j]] , dp[ind[i][j + 1]] + (compress[i][j + 1] - compress[i][j]) * x[i]);
			}
		}
		ll ans = dp[get(n , m)];
		if(ans >= INF / 10){
			cout << "NO ESCAPE" << endl;
		}
		else{
			cout << ans << endl;
		}
	}

    return 0;
}
/*

*/