# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 505;
int n;
int a[MAXN];
int f[MAXN][MAXN];
void upd(int &a, int b){
	a = min(a, b);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	memset(f, 0x3f, sizeof(f));
	for (int l = n; l >= 1; l--){
		f[l][l] = 1;
		f[l + 1][l] = 1;
		for (int r = l + 1; r <= n; r++){
			if (a[l] == a[r]) upd(f[l][r], f[l + 1][r - 1]);
			for (int md = l; md < r; md++) upd(f[l][r], f[l][md] + f[md + 1][r]);
			// printf("f %d %d %d\n", l, r, f[l][r]);
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}