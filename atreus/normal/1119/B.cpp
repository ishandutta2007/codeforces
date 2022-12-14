#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e3 + 10;

ll a[maxn], b[maxn], dp[maxn];
ll n, h;

bool check(int k){
	if (k == 0)
		return (a[0] <= h);
	if (k == 1)
		return (max(a[0], a[1]) <= h);
	for (int i = 0; i < k; i++)
		b[i] = a[i];
	sort(b, b + k);
	dp[0] = b[0];
	dp[1] = b[1];
	for (int i = 2; i < k; i++)
		dp[i] = min(dp[i - 2] + b[i], dp[i - 1] + b[i]);
	return (dp[k - 1] <= h);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int lo = 0, hi = n + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}