# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 2000051;
int n, csz;
int p[MAXN];
int a[MAXN], b[MAXN];
int c[MAXN];
bool flag[MAXN];
int findroot(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = findroot(p[nw]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", a + i, b + i);
		c[++csz] = a[i];
		c[++csz] = b[i];
	}
	sort(c + 1, c + csz + 1);
	csz = unique(c + 1, c + csz + 1) - c - 1;
	for (int i = 1; i <= csz; i++) p[i] = i;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		a[i] = lower_bound(c + 1, c + csz + 1, a[i]) - c;
		b[i] = lower_bound(c + 1, c + csz + 1, b[i]) - c;
		if (flag[findroot(a[i])] && flag[findroot(b[i])]){
			printf("-1\n");
			return 0;
		}
		if (findroot(a[i]) > findroot(b[i]) || flag[findroot(a[i])]) swap(a[i], b[i]);
		int ra = findroot(a[i]), rb = findroot(b[i]);
		ans = max(ans, c[ra]);
		if (ra == rb) flag[ra] = true;
		else p[ra] = rb;
	}
	printf("%d\n", ans);
	return 0;
}