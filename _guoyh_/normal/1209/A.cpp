# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, ans;
int a[105];
bool flag[105];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		if (flag[i]) continue;
		ans++;
		for (int j = i + 1; j <= n; j++)
			if (a[j] % a[i] == 0) flag[j] = true;
	}
	printf("%d\n", ans);
	return 0;
}