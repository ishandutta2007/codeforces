#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int a[maxn], p[maxn];
pair<int,int> dp[maxn];

pair<int,int> update(pair<int,int> x, int k){
	if (k < x.second)
		return x;
	if (k < x.first)
		return {x.first, k};
	return {k, x.first};
}

int get(int x){
	if (x == 2)
		return 1;
	for (int i = 1; i <= x; i++)
		dp[i] = {0, 0};
	for (int i = x; i >= 2; i--){
		dp[i].second ++;
		dp[p[i]] = update(dp[p[i]], max(dp[i].first, dp[i].second));
	}
	return dp[1].first;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n + 1; i++)
		cin >> p[i];
	int now = 2;
	while (now <= n + 1){
		int lo = now, hi = n + 2;
		int k = get(now);
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (get(mid) > k)
				hi = mid;
			else
				lo = mid;
		}
		while (now < hi)
			a[now ++] = k;
	}
	for (int i = 2; i <= n + 1; i++)
		cout << a[i] << " \n"[i == n + 1];
}