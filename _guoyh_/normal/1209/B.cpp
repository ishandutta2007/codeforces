# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, ans;
int a[101], b[101];
char s[101];
bool flag[101];
int main(){
//	freopen("1.in", "r", stdin);
	scanf("%d", &n);
	scanf("%s", s);
	int sz = strlen(s);
	for (int i = 0; i < sz; i++)
		flag[i + 1] = s[i] == '1';
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i);
	for (int i = 0; i <= 10000; i++){
		int cnt = 0;
		for (int j = 1; j <= n; j++){
			if (i >= b[j] && (i - b[j]) % a[j] == 0) flag[j] ^= true;
			cnt += flag[j];
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}