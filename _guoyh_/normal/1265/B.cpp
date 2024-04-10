# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int t, n;
int pos[NR], a[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			pos[a[i]] = i;
		}
		int l = 1e9, r = 0;
		for (int i = 1; i <= n; i++){
			l = min(l, pos[i]);
			r = max(r, pos[i]);
			if (r - l + 1 == i) printf("1");
			else printf("0");
		}
		putchar('\n');
	}
	return 0;
}