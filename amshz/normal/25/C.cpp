# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e3+10;
const int SQ = 450;
 
ll dis[xn][xn], n, qq;


 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> dis[i][j];
	
	cin >> qq;
	while (qq--){
		ll v, u, w;
		cin >> v >> u >> w;
		dis[v][u] = min(dis[v][u], w);
		for (int i = 1; i <= n; i++) dis[i][v] = dis[v][i] = min(dis[i][v], dis[i][u] + dis[v][u]), dis[i][u] = dis[u][i] = min(dis[i][u], dis[i][v] + dis[v][u]);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = dis[j][i] = min(dis[i][j], min(dis[i][v] + dis[j][u] + dis[v][u], dis[i][u] + dis[j][v] + dis[v][u]));
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) ans += dis[i][j];
		
		cout << ans << sep;
	}
 
	return 0;
}