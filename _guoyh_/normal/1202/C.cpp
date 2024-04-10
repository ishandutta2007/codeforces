# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int mv[5][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}, {0, 0}};
const int ch[4] = {'W', 'A', 'S', 'D'};
int t, n;
char s[MAXN];
int mxu1[MAXN], miu1[MAXN], mxv1[MAXN], miv1[MAXN];
int mxu2[MAXN], miu2[MAXN], mxv2[MAXN], miv2[MAXN];
ll calc(int u){
	ll ans = 1e18;
	for (int i = 0; i <= 4; i++){
		ans = min(ans, 1ll * (max(mxu1[u], mxu2[u + 1] + mv[i][0]) - min(miu1[u], miu2[u + 1] + mv[i][0]) + 1)
						   * (max(mxv1[u], mxv2[u + 1] + mv[i][1]) - min(miv1[u], miv2[u + 1] + mv[i][1]) + 1));
	}
	// printf("calc %d %lld\n", u, ans);
	return ans;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < 4; j++){
				if (s[i] == ch[j]){
					mxu1[i] = mxu1[i - 1] - mv[j][0];
					miu1[i] = miu1[i - 1] - mv[j][0];
					mxv1[i] = mxv1[i - 1] - mv[j][1];
					miv1[i] = miv1[i - 1] - mv[j][1];
				}
			}
			mxu1[i] = max(mxu1[i], 0);
			miu1[i] = min(miu1[i], 0);
			mxv1[i] = max(mxv1[i], 0);
			miv1[i] = min(miv1[i], 0);
		}
		mxu2[n + 1] = miu2[n + 1] = mxv2[n + 1] = miv2[n + 1] = 0;
		for (int i = n; i >= 1; i--){
			for (int j = 0; j < 4; j++){
				if (s[i] == ch[j]){
					mxu2[i] = mxu2[i + 1] + mv[j][0];
					miu2[i] = miu2[i + 1] + mv[j][0];
					mxv2[i] = mxv2[i + 1] + mv[j][1];
					miv2[i] = miv2[i + 1] + mv[j][1];
				}
			}
			mxu2[i] = max(mxu2[i], 0);
			miu2[i] = min(miu2[i], 0);
			mxv2[i] = max(mxv2[i], 0);
			miv2[i] = min(miv2[i], 0);
		}
		// for (int i = 1; i <= n; i++){
		// 	printf("f %d %d %d %d %d\n", i, mxu1[i], miu1[i], mxv1[i], miv1[i]);
		// }
		// for (int i = 1; i <= n; i++){
		// 	printf("g %d %d %d %d %d\n", i, mxu2[i], miu2[i], mxv2[i], miv2[i]);
		// }
		ll ans = 1e18;
		for (int i = 0; i <= n; i++) ans = min(ans, calc(i));
		printf("%lld\n", ans);
	}
	return 0;
}