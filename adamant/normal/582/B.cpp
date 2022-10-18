#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, T;
	cin >> n >> T;
	const int k = 342;
	int K = min(k, T);
	int N = n * K;
	int a[N];
	map<int, int> cnt;
	for(int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;
	for(int i = n; i < N; i++)
		a[i] = a[i % n];
	int pr[N + 1][k], sf[N + 1][k];
	memset(pr, 0, sizeof(pr));
	memset(sf, 0, sizeof(sf));
	for(int i = 0; i < N; i++)
	{
		memcpy(pr[i + 1], pr[i], sizeof(pr[i]));
		memcpy(sf[i + 1], sf[i], sizeof(sf[i]));
		int mx;
		mx = 0;
		for(int j = 0; j <= a[i]; j++)
			mx = max(mx, pr[i][j]);
		pr[i + 1][a[i]] = mx + 1;
		mx = 0;
		for(int j = a[N - i - 1]; j < k; j++)
			mx = max(mx, sf[i][j]);
		sf[i + 1][a[N - i - 1]] = mx + 1;
	}
	int ans = 0;
	for(int i = 1; i < k; i++)
	{
		int cur = pr[N][i];
		int S = min(K, T - K);
		int end_ind = n * S;
		cur += sf[end_ind][i];
		cur += (T - S - K) * cnt[i];
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}