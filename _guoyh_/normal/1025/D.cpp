# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 705;
int n;
int a[MAXN];
bool flag[MAXN][MAXN];
bool fl[MAXN][MAXN], fr[MAXN][MAXN];
int gcd(int u, int v){
	if (v == 0) return u;
	else return gcd(v, u % v);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	a[0] = a[n + 1] = 1;
	for (int i = 0; i <= n + 1; i++){
		for (int j = 0; j <= n + 1; j++){
			flag[i][j] = (gcd(a[i], a[j]) != 1 || i == 0 || i == n + 1 || j == 0 || j == n + 1);
		}
	}
	for (int l = n; l >= 1; l--){
		for (int r = l; r <= n; r++){
			for (int i = l; i <= r; i++){
				if (flag[l - 1][i]) fl[l][r] |= (i == l || fr[l][i - 1]) && (i == r || fl[i + 1][r]);
				if (flag[r + 1][i]) fr[l][r] |= (i == l || fr[l][i - 1]) && (i == r || fl[i + 1][r]);
			}
			// printf("f %d %d %d %d\n", l, r, fl[l][r], fr[l][r]);
		}
	}
	if (fl[1][n]) printf("Yes\n");
	else printf("No\n");
	return 0;
}