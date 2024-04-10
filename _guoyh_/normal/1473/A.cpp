# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
int t, n, d;
int a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		bool flag = true;
		for (int i = 1; i <= n; i++){
			if (a[i] > d && a[1] + a[2] > d){
				flag = false;
				break;
			}
		}
		if (flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}//