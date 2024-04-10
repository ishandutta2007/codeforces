# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t, n, sz;
int ans[MAXN];
int main(){
	for (int a = 3; a * a <= 2000000051; a += 2){
		int b = (a * a - 1) / 2;
		if (b < a) continue;
		ans[++sz] = b + 1;
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int fnl = upper_bound(ans + 1, ans + sz + 1, n) - ans - 1;
		printf("%d\n", fnl);
	}
	return 0;
}