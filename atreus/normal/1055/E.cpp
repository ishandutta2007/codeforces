#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 37;

int n, s, m;
int a[maxn], l[maxn], r[maxn], b[maxn], mn[maxn];
pair<int,int> dp[maxn];

pair<int,int> get(int x){
	for (int i = 1; i <= n; i++)
		mn[i] = i;
	for (int i = 1; i <= s; i++)
		mn[r[i]] = min(mn[r[i]], l[i] - 1);
	for (int i = n - 1; i >= 1; i--)
		mn[i] = min(mn[i], mn[i + 1]);
	dp[0] = {0, 0};
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		if (mn[i] == i)
			continue;
		int A = dp[mn[i]].first + b[i] - b[mn[i]] - x;
		int B = dp[mn[i]].second + 1;
		dp[i] = max(dp[i], {A, B});
			continue;
		if (A > dp[i].first or (A == dp[i].first and B < dp[i].second))
			dp[i] = {A, B};
	}
	return dp[n];
}

int check(int x){
	for (int i = 1; i <= n; i++){
		b[i] = (a[i] <= x);
		b[i] += b[i - 1];
	}
	int lo = 0, hi = n;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (get(mid).second >= m)
			lo = mid;
		else
			hi = mid;
	}
	auto it = get(lo);
//	cout << it.first << " " << hi << " * " << it.second << endl;
	return it.first + lo * min(m, it.second);
}

int p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin >> n >> s >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= s; i++){
		cin >> l[i] >> r[i];
		p[l[i]] ++;
		p[r[i]+1] --;
	}
	int lo = 0, hi = 1e9 + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid) < k)
			lo = mid;
		else
			hi = mid;
	}
	if (hi == 1e9 + 1)
		return cout << -1 << endl, 0;
	cout << hi << '\n';
}