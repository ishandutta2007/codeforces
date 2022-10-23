# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3005;
int n, k;
int c[MAXN];
vector <ll> a[MAXN], s[MAXN];
ll f[MAXN], f1[21][MAXN];
ll solve(int lft, int rgt, int dpt){
	ll ans = 0;
	if (lft == rgt){
		for (int i = 0; i <= c[lft] && i <= k; i++) ans = max(ans, f[k - i] + s[lft][i]);
		return ans;
	}
	int mid = (lft + rgt) >> 1;
	memcpy(f1[dpt], f, sizeof(f));
	for (int i = mid + 1; i <= rgt; i++){
		for (int j = k; j >= c[i]; j--){
			f[j] = max(f[j], f[j - c[i]] + s[i][c[i]]);
		}
	}
	ans = max(ans, solve(lft, mid, dpt + 1));
	memcpy(f, f1[dpt], sizeof(f));
	for (int i = lft; i <= mid; i++){
		for (int j = k; j >= c[i]; j--){
			f[j] = max(f[j], f[j - c[i]] + s[i][c[i]]);
		}
	}
	ans = max(ans, solve(mid + 1, rgt, dpt + 1));
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		ll ns = 0;
		s[i].push_back(0);
		a[i].push_back(0);
		for (int j = 1; j <= c[i]; j++){
			ll u;
			cin >> u;
			a[i].push_back(u);
			s[i].push_back(ns += u);
		}
	}
	cout << solve(1, n, 0) << '\n';
	return 0;
}