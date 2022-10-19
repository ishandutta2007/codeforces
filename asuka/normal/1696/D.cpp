#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int t, n, p[250015], dp[250015];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		rep(i, 1, n) scanf("%d", p + i);

		fill(dp + 1, dp + n + 1, inf);
		vector<int> mx(1, 1), mn(1, 1);
		dp[1] = 0;

		rep(i, 2, n) {
			while (!mx.empty() && p[mx.back()] < p[i]) mx.pop_back();

			while (!mn.empty() && p[mn.back()] > p[i]) mn.pop_back();

			if (p[i - 1] > p[i]) {
				int o = mn.empty() ? 0 : mn.back();
				dp[i] = dp[*lower_bound(all(mx), o)] + 1;

			} else {
				int o = mx.empty() ? 0 : mx.back();
				dp[i] = dp[*lower_bound(all(mn), o)] + 1;
			}

			while (!mx.empty() && dp[mx.back()] >= dp[i])
				mx.pop_back();

			mx.push_back(i);

			while (!mn.empty() && (dp[mn.back()] >= dp[i]))
				mn.pop_back();

			mn.push_back(i);

		}

		printf("%d\n", dp[n]);
	}

	return 0;
}