#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, m;
vector< pair<int, int> > v[555];
void bfs(int s, int *dis){
	memset(dis, 0x3f, n<<2);
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now = q.front(); q.pop();
		rep(i, (int)v[now].size()){
			int t = v[now][i].first;
			if(dis[now] + 1 < dis[t]){
				dis[t] = dis[now] + 1;
				q.push(t);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		
		cin >> n >> m;
		rep(i, n)
			v[i].clear();
		rep(i, m){
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			v[a].emplace_back(b, c);
			v[b].emplace_back(a, c);
		}
		
		static int dis[555][555];
		rep(i, n)
			bfs(i, dis[i]);
		
		ll ans = 0x3f3f3f3f3f3f3f3fll;
		rep(i, n) rep(j, (int)v[i].size()){
			ans = min(ans, 1ll * (dis[0][i] + dis[n-1][v[i][j].first] + 1) * v[i][j].second);
			rep(k, n)
				ans = min(ans, 1ll * (dis[0][k] + dis[n-1][k] + dis[i][k] + 2) * v[i][j].second);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}