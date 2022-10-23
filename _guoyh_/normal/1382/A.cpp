# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1051;
int t, n, m;
int a[NR], b[NR];
int flag[NR];
int main(){
	scanf("%d", &t);
	memset(flag, 0x3f, sizeof(flag));
	while (t--){
		int ans = -1;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= m; i++) scanf("%d", b + i);
		for (int i = 1; i <= n; i++) flag[a[i]] = t;
		for (int i = 1; i <= m; i++){
			if (flag[b[i]] == t){
				ans = b[i];
				break;
			}
		}
		if (ans < 0) printf("NO\n");
		else printf("YES\n1 %d\n", ans);
	}
	return 0;
}