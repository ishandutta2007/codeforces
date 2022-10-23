# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, l, w, asz, bsz;
int a[MAXN], b[MAXN];
ll ans;
bool check(int x, int y){
	long double nx = (long double)(a[x] + b[y] + l) / 2;
	long double ny = (nx - a[x]);
	return ny >= 0 && ny * w > nx && ny * w > -nx;
}
int main(){
	scanf("%d%d%d", &n, &l, &w);
	for (int i = 1; i <= n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if (v > 0) a[++asz] = u;
		else b[++bsz] = u;
	}
	sort(b + 1, b + bsz + 1);
	sort(a + 1, a + asz + 1);
	// printf("%d\n", check(2, 2));
	// return 0;
	for (int i = 1; i <= asz; i++){
		int lft = 1, rgt = bsz + 1, pos = bsz + 1;
		while (lft <= rgt){
			int mid = (lft + rgt) >> 1;
			if (check(i, mid)){
				pos = mid;
				rgt = mid - 1;
			} else lft = mid + 1;
		}
		ans += bsz - pos + 1;
		// printf("ip %d %d\n", i, pos);
	}
	printf("%lld\n", ans);
	return 0;
}