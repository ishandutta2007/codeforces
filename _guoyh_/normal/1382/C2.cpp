# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n, asz;
int a[NR], b[NR], ans[NR << 2];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int lft = 1, rgt = n;
		bool inv = false;
		asz = 0;
		for (int i = 1; i <= n; i++) scanf("%1d", a + i);
		for (int i = 1; i <= n; i++) scanf("%1d", b + i);
		for (int i = 1; i <= n; i++){
			if (inv){
				if (a[rgt] != b[n - i + 1]) ans[++asz] = 1;
				ans[++asz] = n - i + 1;
				rgt--;
			} else {
				if (a[lft] == b[n - i + 1]) ans[++asz] = 1;
				ans[++asz] = n - i + 1;
				lft++;
			}
			inv ^= true;
		}
		printf("%d ", asz);
		for (int i = 1; i <= asz; i++) printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}