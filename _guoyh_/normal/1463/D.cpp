# include <stack>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t, n;
bool flag[MAXN * 2], flag2[MAXN * 2];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(flag2, false, sizeof(flag2));
		memset(flag, false, sizeof(flag));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			int u;
			scanf("%d", &u);
			flag[u] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++){
			if (!flag[i]) cnt++;
			else if (cnt > 0){
				cnt--;
				flag2[i] = true;
			}
		}
		int ans = 1;
		cnt = 0;
		for (int i = 2 * n; i >= 1; i--){
			if (!flag[i]) cnt++;
			else if (flag2[i] && cnt > 0){
				ans++;
				cnt--;
			}
			if (flag[i] && !flag2[i]) cnt--;
		}
		printf("%d\n", ans);
	}
	return 0;
}