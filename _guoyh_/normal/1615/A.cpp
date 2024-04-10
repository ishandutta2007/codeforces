# include <bits/stdc++.h>
# define ll long long
using namespace std;
int t, n;
int a[10005];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		ll s = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			s += a[i];
		}
		if (s % n == 0) printf("0\n");
		else printf("1\n");
	}
	return 0;
}