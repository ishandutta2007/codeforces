#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, m;
ll b[111][111];
vector< pair< ll, pair<int, int> > > v;
bool used[111][111];
vector<int> ans[111];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n) rep(j, m) cin >> b[i][j];
		v.clear();
		rep(i, n) rep(j, m) v.push_back(make_pair(b[i][j], make_pair(i, j)));
		sort(v.begin(), v.end());
		rep(i, n) rep(j, m) used[i][j] = 0;
		rep(i, m) used[v[i].second.first][v[i].second.second] = 1;
		rep(i, m) ans[i].clear();
		rep(i, m){
			int x = v[i].second.first, y = v[i].second.second;
			rep(nx, x){
				int ny = 0;
				while(used[nx][ny]) ny++;
				ans[i].push_back(b[nx][ny]);
				used[nx][ny] = 1;
			}
			ans[i].push_back(b[x][y]);
			for(int nx = x + 1; nx < n; nx++){
				int ny = 0;
				while(used[nx][ny]) ny++;
				ans[i].push_back(b[nx][ny]);
				used[nx][ny] = 1;
			}
		}
		rep(i, n){
			rep(j, m) cout << ans[j][i] << " ";
			cout << endl;
		}
	}
	return 0;
}