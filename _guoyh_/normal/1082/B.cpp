# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n, cnt, ans;
char a[NR];
int s1[NR], s2[NR];
int main(){
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++){
		s1[i] = (a[i] == 'G') ? s1[i - 1] + 1 : 0;
		ans = max(ans, s1[i]);
	}
	for (int i = n; i >= 1; i--) s2[i] = (a[i] == 'G') ? s2[i + 1] + 1 : 0;
	for (int i = 1; i <= n; i++) cnt += (a[i] == 'G');
	for (int i = 1; i <= n; i++){
		if (a[i] == 'G') continue;
		if (s1[i - 1] + s2[i + 1] == cnt){
			ans = max(ans, s1[i - 1] + s2[i + 1]);
		} else ans = max(ans, s1[i - 1] + s2[i + 1] + 1);
	}
	printf("%d\n", ans);
	return 0;
}