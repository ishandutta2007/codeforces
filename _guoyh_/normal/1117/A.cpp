# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n, nw, ans, mx;
int a[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= n; i++){
		if (a[i] != mx) nw = 0;
		else nw++;
		ans = max(ans, nw);
	}
	printf("%d\n", ans);
	return 0;
}