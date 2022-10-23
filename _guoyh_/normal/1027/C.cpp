# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1000051;
int t, n;
int a[NR];
int bx[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		ll ans1 = 1, ans2 = 0;
		int ans3 = -1, ans4 = -1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			bx[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		int sz = unique(a + 1, a + n + 1) - a - 1;
		int l = -1;
		for (int i = 1; i <= sz; i++){
			if (bx[a[i]] >= 4){
				l = a[i];
				ans1 = 16;
				ans2 = 1;
				ans3 = ans4 = a[i];
			} else if (bx[a[i]] >= 2){
				if (l != -1){
					// printf("li %d %d\n", l, a[i]);
					ll p = 2 * (a[i] + l);
					ll s = a[i] * l;
					if (p * p * ans2 < ans1 * s){
						ans1 = p * p;
						ans2 = s;
						ans3 = l;
						ans4 = a[i];
					}
				}
				l = a[i];
			}
			bx[a[i]] = 0;
		}
		printf("%d %d %d %d\n", ans3, ans3, ans4, ans4);
	}
	return 0;
}