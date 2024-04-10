# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 505;
int n;
char s[MAXN];
int f[MAXN][MAXN];
int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	memset(f, 0x3e, sizeof(f));
	for (int len = 1; len <= n; len++){
		for (int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			if (l == r){
				f[l][r] = 1;
				// printf("f %d %d %d\n", l, r, f[l][r]);
				continue;
			}
			for (int mid = l; mid < r; mid++){
				f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r]);
			}
			if (s[l] == s[r]) f[l][r] = f[l + 1][r];
			// printf("f %d %d %d\n", l, r, f[l][r]);
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}