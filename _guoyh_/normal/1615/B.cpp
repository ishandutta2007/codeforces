# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t;
int s[MAXN][21];
int main(){
	for (int i = 1; i < MAXN; i++){
		for (int j = 0; j <= 20; j++){
			s[i][j] = s[i - 1][j] + ((i >> j) & 1);
		}
	}
	scanf("%d", &t);
	while (t--){
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 1e9;
		for (int i = 0; i <= 20; i++){
			ans = min(ans, r - l + 1 - (s[r][i] - s[l - 1][i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}