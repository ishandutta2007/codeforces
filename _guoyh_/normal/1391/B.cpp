# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n, m;
char p[NR][NR];
int main(){
	scanf("%d", &t);
	while (t--){
		int ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf("%s", p[i] + 1);
			if (i < n) ans += (p[i][m] == 'R');
		}
		for (int i = 1; i <= m; i++) ans += (p[n][i] == 'D');
		printf("%d\n", ans);
	}
	return 0;
}