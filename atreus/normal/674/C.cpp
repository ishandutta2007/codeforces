#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const ld inf = 1e18;

ll t[maxn];
ll sum[maxn];
ld dp[52][maxn], pre[maxn], rev[maxn];

ld get(int L, int R, int k){
	L --;
	ld ret = dp[k][L] + (pre[R] - pre[L]) - 1. * (rev[R] - rev[L]) * sum[L];
	return ret;
}

void find(int L, int R, int l, int r, int k){
	if (L > R)
		return;
	int mid = (L + R) >> 1;
	int mn = l;
	ld now = get(l, mid, k - 1);
	for (int i = l + 1; i <= min(r, mid); i++){
		if (get(i, mid, k - 1) < now){
			now = get(i, mid, k - 1);
			mn = i;
		}
	}
	dp[k][mid] = now;
	find(L, mid-1, l, mn, k);
	find(mid+1, R, mn, r, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++){
		sum[i] = t[i] + sum[i - 1];
		rev[i] = 1. / t[i] + rev[i - 1];
	}
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + 1. * sum[i] / t[i];
	for (int i = 1; i <= n; i++)
		dp[0][i] = inf;
	for (int i = 1; i <= k; i++)
		find(i, n, i, n, i);
	cout << fixed << setprecision(6) << dp[k][n] << '\n';	
}