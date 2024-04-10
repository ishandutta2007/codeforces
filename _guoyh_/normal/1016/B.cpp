# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1051;
int n, m, q;
int nxt[NR];
char s[NR], t[NR];
int main(){
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s%s", s + 1, t + 1);
	nxt[0] = -1;
	for (int i = 1; i <= m; i++){
		int p = nxt[i - 1];
		while (p != -1 && t[p + 1] != t[i]) p = nxt[p];
		nxt[i] = p + 1;
	}
	while (q--){
		int lft, rgt;
		scanf("%d%d", &lft, &rgt);
		int nw = 0, ans = 0;
		for (int i = lft; i <= rgt; i++){
			while (nw != -1 && t[nw + 1] != s[i]) nw = nxt[nw];
			if (++nw == m){
				ans++;
				nw = nxt[nw];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}