#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int T, n;
char a[N], c[N];
std :: vector<int> pos[10];
void solve(){
	for (register int i = 0; i <= 9; ++i) pos[i].clear();
	for (register int i = 1; i <= n; ++i) pos[a[i] - '0'].push_back(i), c[i] = 0;
	int lp = 0;
	char now = '1';
	for (register int i = 0; i <= 9; ++i)
		if (pos[i].size()){
			if (pos[i][0] > lp) for (int j : pos[i]) c[j] = now, lp = j;
			else{
				if (now == '2') return puts("-"), void(0);
				for (int j : pos[i]) if (j > lp) c[j] = now, lp = j;
				++now;
				for (int j : pos[i]) if (!c[j]) c[j] = now, lp = j;
			}
		}
	for (register int i = 1; i <= n; ++i) putchar(c[i]); putchar('\n');
}
int main(){
	T = read();
	while (T--){
		n = read(), scanf("%s", a + 1);
		solve();
	}
}