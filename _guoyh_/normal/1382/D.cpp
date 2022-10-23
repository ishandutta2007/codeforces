# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 2051;
int t, n, wsz;
bool f[NR];
int p[NR << 1], w[NR << 1];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) f[i] = false;
		f[0] = true;
		int mn = 1;
		wsz = 0;
		for (int i = 1; i <= 2 * n; i++){
			scanf("%d", p + i);
		}
		for (int i = 2; i <= 2 * n; i++){
			if (p[i] > p[mn]){
				w[++wsz] = i - mn;
				mn = i;
			}
		}
		w[++wsz] = 2 * n - mn + 1;
		for (int i = 1; i <= wsz; i++){
			for (int j = n; j >= w[i]; j--){
				f[j] |= f[j - w[i]];
				// printf("ijf %d %d %d\n", i, j, f[j]);
			}
		}
		if (f[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}