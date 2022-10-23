# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t, n, m;
char s[MAXN];
int pl[MAXN], pr[MAXN], sl[MAXN], sr[MAXN], sum[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		scanf("%s", s + 1);
		int nw = 0;
		pl[0] = pr[0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++){
			if (s[i] == '+') nw++;
			else nw--;
			pl[i] = min(pl[i - 1], nw);
			pr[i] = max(pr[i - 1], nw);
			sum[i] = nw;
		}
		sl[n + 1] = sr[n + 1] = nw = 0;
		for (int i = n; i >= 1; i--){
			if (s[i] == '+') nw++;
			else nw--;
			sl[i] = min(sl[i + 1], nw);
			sr[i] = max(sr[i + 1], nw);
		}
		for (int i = 1; i <= m; i++){
			int l, r;
			scanf("%d%d", &l, &r);
			int lft1 = pl[l - 1], rgt1 = pr[l - 1];
			int lft2 = sum[n] - sum[r] + sum[l - 1] - sr[r + 1], rgt2 = sum[n] - sum[r] + sum[l - 1] - sl[r + 1];
			if (lft1 > rgt2 || lft2 > rgt1) printf("%d\n", (rgt1 - lft1 + 1) + (rgt2 - lft2 + 1));
			else printf("%d\n", max(rgt1, rgt2) - min(lft1, lft2) + 1);
		}
	}
	return 0;
}