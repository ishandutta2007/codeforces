#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int maxn = 2e5 + 100;
int dp[maxn], best[maxn];
pair <int, int> p[maxn];

int main (){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].F >> p[i].S;
	memset (best, 63, sizeof best);
	sort (p, p + n);
	dp[0] = 0;
	best[0] = p[0].F + p[0].S;
	for (int i = 1; i < n; i++){
		int X = p[i].F - p[i].S;
		int idx = upper_bound(best, best + n, X) - best - 1;
		dp[i] = idx + 1;
		best[idx + 1] = min(best[idx + 1], p[i].F + p[i].S);
	}
	int mxx = 0;
	for (int i = 0; i < n; i++)
		mxx = max(mxx, dp[i]);
	cout << mxx + 1 << endl;
}