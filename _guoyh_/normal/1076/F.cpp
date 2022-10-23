# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
int n, k;
int x[MAXN], y[MAXN];
int fx[MAXN], fy[MAXN];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", x + i);
	for (int i = 1; i <= n; i++) scanf("%d", y + i);
	for (int i = 1; i <= n; i++){
		fx[i] = max(0ll, fx[i - 1] + x[i] - 1ll * k * y[i]);
		fy[i] = max(0ll, fy[i - 1] + y[i] - 1ll * k * x[i]);
		// printf("fxy %d %d %d\n", i, fx[i], fy[i]);
		if (fx[i] > k || fy[i] > k){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}