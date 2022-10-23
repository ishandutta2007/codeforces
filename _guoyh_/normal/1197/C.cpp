# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
int n, k;
int a[MAXN], b[MAXN];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		b[i] = a[i] - a[i - 1];
	}
	int ans = a[n] - a[1];
	sort(b + 2, b + n + 1);
	for (int i = 1; i <= k - 1; i++) ans -= b[n - i + 1];
	printf("%d\n", ans);
	return 0;
}