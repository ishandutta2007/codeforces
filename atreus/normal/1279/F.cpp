#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 50;

int n, k, l;
int par[maxn], a[maxn];
ld dp[maxn];
int pd[maxn];

pair<ld,int> check(ld x){
	for (int i = 1; i < l; i++){
		dp[i] = par[i];
		pd[i] = 0;
		if (dp[i] > x){
			dp[i] = x;
			pd[i] = 1;
		}
	}
	for (int i = l; i <= n; i++){
		pair<ld, int> fi = {dp[i - 1] + a[i], pd[i - 1]};
		pair<ld, int> se = {dp[i - l] + x, pd[i - l] + 1};
		if (fi > se)
			swap(fi, se);
		dp[i] = fi.first, pd[i] = fi.second;
	}
	return make_pair(dp[n], pd[n]);
}

int solve(){
	for (int i = 1; i <= n; i++)
		par[i] = par[i - 1] + a[i];
	ld lo = 0, hi = n;
	int bs = 80;
	while (bs --){
		ld mid = .5 * (lo + hi);
		if (check(mid).second > k)
			lo = mid;
		else
			hi = mid;
	}
	return check(hi).first - hi * k + 0.5;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> l;
	string s;
	cin >> s;
	int ans = n;
	for (int i = 0; i < n; i++){
		int k = (int)(s[i] - 'A');
		if (k >= 0 and k < 26)
			a[i + 1] = 0;
		else
			a[i + 1] = 1;
	}
	ans = min(ans, solve());
	for (int i = 1; i <= n; i++)
		a[i] ^= 1;
	ans = min(ans, solve());
	cout << ans << endl;
}