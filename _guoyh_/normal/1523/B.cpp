# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1051;
int t, n;
int a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("%d\n", 3 * n);
		for (int i = 1; i * 2 <= n; i++){
			int u = i * 2 - 1, v = i * 2;
			printf("2 %d %d\n", u, v);
			printf("1 %d %d\n", u, v);
			printf("2 %d %d\n", u, v);
			printf("2 %d %d\n", u, v);
			printf("1 %d %d\n", u, v);
			printf("2 %d %d\n", u, v);
		}
	}
	return 0;
}