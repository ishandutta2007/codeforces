# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 205;
int t, n;
char s[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (s[i] == 't') cnt++;
			else printf("%c", s[i]);
		}
		for (int i = 1; i <= cnt; i++) printf("t");
		putchar('\n');
	}
	return 0;
}