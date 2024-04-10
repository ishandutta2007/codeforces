# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
int a[MAXN], b[MAXN];
int f[MAXN][2][2];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%1d", a + i);
		for (int i = 1; i <= n; i++) scanf("%1d", b + i);
		int ans = 1e9;
		for (int j = 0; j < 2; j++){
			int cnt0 = 0, cnt1 = 0;
			for (int i = 1; i <= n; i++){
				if ((a[i] ^ j) == b[i]) continue;
				if (a[i] == 0) cnt0++;
				else cnt1++;
			}
			if (((cnt0 + cnt1) & 1) == j && (cnt1 == cnt0 || cnt1 == cnt0 + 1)) ans = min(ans, cnt0 + cnt1);
		}
		if (ans <= n) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}