# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n;
ll b[NR], a[NR];
int main(){
	scanf("%d", &n);
	a[n + 1] = 1e18;
	for (int i = 1; i + i <= n; i++){
		scanf("%lld", b + i);
		a[i] = max(a[i - 1], b[i] - a[n - i + 2]);
		a[n - i + 1] = b[i] - a[i];
	}
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	putchar('\n');
	return 0;
}