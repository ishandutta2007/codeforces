# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
int t, n;
int a[MAXN], b[MAXN], c[MAXN], p[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		p[1] = a[1];
		for (int i = 2; i < n; i++){
			if (a[i] != p[i - 1]) p[i] = a[i];
			else p[i] = b[i];
		}
		if (a[n] != p[n - 1] && a[n] != p[1]) p[n] = a[n];
		if (b[n] != p[n - 1] && b[n] != p[1]) p[n] = b[n];
		if (c[n] != p[n - 1] && c[n] != p[1]) p[n] = c[n];
		for (int i = 1; i <= n; i++) printf("%d ", p[i]);
		putchar('\n');
	}
	return 0;
}