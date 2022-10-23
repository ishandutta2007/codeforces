# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
int t, n;
int a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (a[i] != a[1]) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}