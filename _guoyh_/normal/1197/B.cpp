# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n;
int a[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 2; i <= n - 1; i++){
		if (a[i] < a[i - 1] && a[i] < a[i + 1]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}