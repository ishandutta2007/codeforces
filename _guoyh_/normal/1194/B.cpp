# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 400051;
int q, n, m;
char s[MAXN];
int fr[MAXN], fc[MAXN];
int main(){
	scanf("%d", &q);
	while (q--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", s + (i - 1) * m + 1);
		memset(fr, 0, sizeof(int) * (n + 1));
		memset(fc, 0, sizeof(int) * (m + 1));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (s[(i - 1) * m + j] == '.'){
					fr[i]++;
					fc[j]++;
				}
			}
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				ans = min(ans, fr[i] + fc[j] - (s[(i - 1) * m + j] == '.'));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}