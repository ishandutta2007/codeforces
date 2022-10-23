# include <bits/stdc++.h>
# define ll long long
using namespace std;
int T, n, s, t;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &s, &t);
		printf("%d\n", max(n - s + 1, n - t + 1));
	}
	return 0;
}