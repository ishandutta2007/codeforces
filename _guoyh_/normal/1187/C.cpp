# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1051;
int n, m, qsz;
int a[MAXN];
int ql[MAXN], qr[MAXN];
int p[MAXN];
int findroot(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = findroot(p[nw]);
}
bool check(){
	for (int i = 1; i <= qsz; i++) if (findroot(ql[i]) == findroot(qr[i])) return false;
	return true;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++){
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1){
			for (int j = findroot(l); j < r; j = findroot(j + 1)) p[j] = findroot(j + 1);
		} else {
			qsz++;
			ql[qsz] = l;
			qr[qsz] = r;
		}
	}
	if (!check()) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i <= n; i++){
			if (!a[findroot(i)]) a[findroot(i)] = n - i + 1;
			printf("%d ", a[findroot(i)]);
		}
		putchar('\n');
	}
	return 0;
}