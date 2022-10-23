# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 151;
int t, n;
char s[MAXN];
bool f[MAXN][2][2];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		f[0][0][0] = true;
		for (int i = 1; i <= n; i++){
			f[i][0][0] = (s[i] == '0') ? f[i - 1][0][0] || f[i - 1][0][1] : false;
			f[i][0][1] = f[i - 1][0][0];
			f[i][1][0] = (s[i] == '1') ? f[i - 1][1][0] || f[i - 1][1][1] : false;
			f[i][1][1] = f[i - 1][1][0] || f[i - 1][0][0];
		}
		if (f[n][0][0] || f[n][0][1] || f[n][1][0] || f[n][1][1]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}