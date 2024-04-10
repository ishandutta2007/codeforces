# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 2000051;
const int INF = 0x3f3f3f3f;
int n;
char s[MAXN];
int cnt[10][10];
int f[10][10];
int solve(int u, int v){
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i < 10; i++) f[i][(i + u) % 10] = f[i][(i + v) % 10] = 1;
	for (int k = 0; k < 10; k++){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (f[i][j] == INF && cnt[i][j] > 0) return -1;
			ans += (f[i][j] - 1) * cnt[i][j];
		}
	}
	return ans;
}
int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 2; i <= n; i++) cnt[s[i - 1] - '0'][s[i] - '0']++;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) printf("%d ", solve(i, j));
		putchar('\n');
	}
	return 0;
}