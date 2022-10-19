#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}
ll qmax(ll a, ll b){
	return (a > b) ? a : b;
}

int n[3];
ll a[3][300300];
ll mn[3], sum[3];

int main(){
	ios::sync_with_stdio(false);
	rep(i, 3) cin >> n[i];
	rep(i, 3) rep(j, n[i]) cin >> a[i][j];
	rep(i, 3){
		mn[i] = a[i][0], sum[i] = 0;
		rep(j, n[i]) mn[i] = qmin(mn[i], a[i][j]), sum[i] += a[i][j];
	}
	ll ans = sum[0] + sum[1] + sum[2];
	ll res = qmax(sum[1] + sum[2] - sum[0], qmax(sum[0] + sum[2] - sum[1], sum[0] + sum[1] - sum[2]));
	sort(mn, mn+3);
	res = qmax(res, ans - mn[0] - mn[1] - mn[0] - mn[1]);
	cout << res << endl;
	return 0;
}