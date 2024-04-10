# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 500051;
int n, c;
int a[MAXN], s[MAXN], f[MAXN];
int main(){
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		s[i] = s[i - 1] + (a[i] == c);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		f[a[i]]++;
		f[a[i]] = max(f[a[i]], s[i - 1] + 1);
		ans = max(ans, f[a[i]] + s[n] - s[i]);
	}
	printf("%d\n", ans);
	return 0;
}