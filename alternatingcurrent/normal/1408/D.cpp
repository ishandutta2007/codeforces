#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define int long long
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int n, m;
int a[2020], b[2020], c[2020], d[2020];
pair<int, int> g[4004000];

signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, m) cin >> c[i] >> d[i];
	rep(i, n){
		rep(j, m){
			g[i * m + j] = make_pair(0, 0);
			if(d[j] >= b[i]) g[i * m + j].first = qmax(g[i * m + j].first, c[j] - a[i] + 1);
			if(c[j] >= a[i]) g[i * m + j].second = qmax(g[i * m + j].second, d[j] - b[i] + 1);
		}
	}
	sort(g, g + n*m);
	int mx_up = 0;
	int ans = 0x3f3f3f3f;
	for(int i = n*m-1; i >= 0; i--){
		ans = qmin(ans, g[i].first + mx_up);
		mx_up = qmax(mx_up, g[i].second);
	}
	ans = qmin(ans, mx_up);
	cout << ans << endl;
	return 0;
}