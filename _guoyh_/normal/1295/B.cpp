# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n, x, s;
int a[NR], p[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++){
			scanf("%1d", a + i);
			p[i] = p[i - 1] + (a[i] == 0 ? 1 : -1);
		}
		s = p[n];
		int ans = 0;
		if (x == 0) ans = 1;
		if (s == 0){
			for (int i = 1; i <= n; i++)
				if (x == p[i]){
					ans++;
					break;
				}
			if (ans) printf("-1\n");
			else printf("0\n");
			continue;
		}
		for (int i = 1; i <= n; i++)
			if ((x - p[i]) % s == 0 && (x - p[i]) / s >= 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}