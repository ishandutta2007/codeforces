# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int t, n, k;
int a[NR];
bool p[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		int ans = 0, cnt = 0, mn = 1;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		p[1] = false;
		for (int i = 2; i <= n; i++){
			if (i - k + 1 >= 1) cnt -= p[i - k + 1];
			cnt += p[i - 1];
			p[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]);
			if (i - k + 1 >= 1 && cnt > ans){
				mn = i - k + 1;
				ans = cnt;
			}
		}
		printf("%d %d\n", ans + 1, mn);
	}
	return 0;
}