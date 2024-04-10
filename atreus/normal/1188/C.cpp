#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 10;
const int maxA = 1e5 + 10;
const int mod = 998244353;

int a[maxn], dp[maxn], par[maxn], pnt[maxn], pd[maxA];
int n, k;
int mp[maxA];

int cal(int x){
	if (mp[x] != -1)
		return mp[x];
	int ptr = 0;
	for (int i = 1; i <= n; i++){
		while (ptr < i - 1 and a[i] - a[ptr + 1] >= x)
			ptr ++;
		pnt[i] = ptr;
	}
	for (int i = 0; i <= n; i++)
		dp[i] = 1;
	for (int i = 1; i <= k; i++){
		for (int j = n; j >= 1; j--)
			dp[j] = dp[pnt[j]];
		dp[0] = 0;
		for (int j = 1; j <= n; j++){
			dp[j] += dp[j - 1];
			if (dp[j] >= mod)
				dp[j] -= mod;
		}
	}
	return mp[x] = dp[n];
}

int main(){
	memset(mp, -1, sizeof mp);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = -a[n];
	sort(a + 1, a + n + 1);
	int now = 0;
	vector<pair<int, int> > v;
	while (now <= a[n]){
		int t = cal(now);
		int lo = now, hi = a[n] + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (cal(mid) == t)
				lo = mid;
			else
				hi = mid;
		}
		v.push_back({lo, t});
		now = hi;
	}
	int m = v.size();
	int answer = 0;
	for (int i = 0; i < m; i++){
		int t = v[i].second;
		if (i < m - 1)
			t = (t - v[i + 1].second + mod) % mod;
		answer = (answer + 1ll * t * v[i].first % mod) % mod;
	}
	printf("%d\n", answer);
}