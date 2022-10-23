# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 10051;
int n, ans;
int a[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int mxn = 0;
	for (int i = 1; i <= n; i++){
		mxn = max(mxn, a[i]);
		if (i >= mxn) ans++;
	}
	printf("%d\n", ans);
	return 0;
}