# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
struct Seg{
	int lft, rgt, id;
} a[NR];
int t;
int n;
int ans[NR];
bool cmp(Seg x, Seg y){
	return x.lft < y.lft;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d%d", &a[i].lft, &a[i].rgt);
			a[i].id = i;
		}
		sort(a + 1, a + n + 1, cmp);
		int mxr = 0, p = -1;
		for (int i = 1; i < n; i++){
			mxr = max(mxr, a[i].rgt);
			if (mxr < a[i + 1].lft){
				p = i;
				break;
			}
		}
		if (p == -1){
			printf("-1\n");
			continue;
		}
		for (int i = 1; i <= p; i++) ans[a[i].id] = 1;
		for (int i = p + 1; i <= n; i++) ans[a[i].id] = 2;
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}