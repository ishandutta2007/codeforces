# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
int a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		printf("%d\n", min(a[n - 1] - 1, n - 2));
	}
	return 0;
}