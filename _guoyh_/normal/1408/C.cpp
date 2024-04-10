# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n, l;
double lc, rc;
int ld, rd;
int a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		ld = 0;
		rd = n + 1;
		lc = 0;
		rc = l;
		double ans = 0;
		while (ld < rd - 1){
			double t;
			if (fabs(lc - a[ld + 1]) * (n - rd + 2) < fabs(rc - a[rd - 1]) * (ld + 1)){
				t = fabs(lc - a[ld + 1]) / (ld + 1);
				rc -= t * (n - rd + 2);
				lc = a[ld + 1];
				ld++;
			} else {
				t = fabs(rc - a[rd - 1]) / (n - rd + 2);
				lc += t * (ld + 1);
				rc = a[rd - 1];
				rd--;
			}
			ans += t;
			// printf("%d %d %lf %lf %lf\n", ld, rd, lc, rc, ans);
		}
		ans += (rc - lc) / (n + 2);
		printf("%.7f\n", ans);
	}
	return 0;
}