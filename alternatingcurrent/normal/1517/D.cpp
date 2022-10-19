#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}

int n, m, k;
ll dist_h[555][555], dist_v[555][555];
ll dist[555][555][12];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	rep(i, n) rep(j, m - 1) cin >> dist_h[i][j];
	rep(i, n - 1) rep(j, m) cin >> dist_v[i][j];
	if(k % 2 == 1){
		rep(i, n){
			rep(j, m) cout << "-1 ";
			cout << endl;
		}
		return 0;
	}
	memset(dist, 0x3f, sizeof(dist));
	rep(i, n) rep(j, m) dist[i][j][0] = 0;
	for(int nk = 1; nk <= k / 2; nk++){
		rep(i, n){
			rep(j, m){
				if(i > 0) dist[i][j][nk] = qmin(dist[i][j][nk], dist[i - 1][j][nk - 1] + dist_v[i - 1][j]);
				if(i < n-1) dist[i][j][nk] = qmin(dist[i][j][nk], dist[i + 1][j][nk - 1] + dist_v[i][j]);
				if(j > 0) dist[i][j][nk] = qmin(dist[i][j][nk], dist[i][j - 1][nk - 1] + dist_h[i][j - 1]);
				if(j < m-1) dist[i][j][nk] = qmin(dist[i][j][nk], dist[i][j + 1][nk - 1] + dist_h[i][j]);
			}
		}
/*		rep(i, n){
			rep(j, m) cout << dist[i][j][nk] << " ";
			cout << endl;
		}
		cout << endl;*/
	}
	rep(i, n){
		rep(j, m) cout << dist[i][j][k / 2] * 2LL << " ";
		cout << endl;
	}
	return 0;
}