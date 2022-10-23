# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int T, sz1, sz2;
char s[NR], t[NR];
int f[NR][31];
int find(int x, char y){
	if (f[x][y - 'a']) return f[x][y - 'a'];
	if (s[x] == y || x == sz1 + 1) return x;
	return f[x][y - 'a'] = find(x + 1, y);
}
int main(){
	scanf("%d", &T);
	while (T--){
		memset(f, 0, sizeof(f));
		scanf("%s%s", s + 1, t + 1);
		sz1 = strlen(s + 1);
		sz2 = strlen(t + 1);
		int p = 0, ans = 1;
		for (int i = 1; i <= sz2; i++){
			if (find(1, t[i]) == sz1 + 1){
				ans = -1;
				break;
			}
			p = find(p + 1, t[i]);
			if (p == sz1 + 1){
				ans++;
				p = find(1, t[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}