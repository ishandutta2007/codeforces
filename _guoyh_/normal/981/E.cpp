# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 10051;
const int P = 19190817;
int n, q;
int f[MAXN];
bool ans[MAXN];
vector <int> adj0[MAXN], adj1[MAXN];
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		adj0[l].push_back(k);
		adj1[r].push_back(k);
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < adj0[i].size(); j++){
			for (int k = n; k >= 0; k--){
				if (k >= adj0[i][j]) f[k] = (f[k] + f[k - adj0[i][j]]) % P;
				ans[k] |= f[k];
			}
		}
		for (int j = 0; j < adj1[i].size(); j++){
			for (int k = adj1[i][j]; k <= n; k++) f[k] = (f[k] - f[k - adj1[i][j]]) % P;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += ans[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}