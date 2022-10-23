# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, m, cnt;
int ans1[MAXN], ans2[MAXN];
int gcd(int u, int v){
	if (v == 0) return u;
	else return gcd(v, u % v);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (gcd(i, j) == 1){
				cnt++;
				ans1[cnt] = i;
				ans2[cnt] = j;
				if (cnt >= m) break;
			}
		}
		if (cnt >= m) break;
	}
	if (cnt < m || cnt < n - 1) printf("Impossible\n");
	else {
		printf("Possible\n");
		for (int i = 1; i <= m; i++) printf("%d %d\n", ans1[i], ans2[i]);
	}
	return 0;
}