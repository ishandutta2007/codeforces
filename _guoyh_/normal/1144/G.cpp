# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n;
int a[MAXN];
int l0[MAXN], l1[MAXN];
bool f0[MAXN], f1[MAXN];
int pre[2][MAXN];
int q0[MAXN], ql0 = 1, qr0;
int q1[MAXN], ql1 = 1, qr1;
int ans[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	l0[1] = l1[1] = 1;
	for (int i = 2; i <= n; i++){
		l0[i] = a[i] > a[i - 1] ? l0[i - 1] : i;
		l1[i] = a[i] < a[i - 1] ? l1[i - 1] : i;
	}
	f0[0] = f1[0] = true;
	for (int i = 1; i <= n; i++){
		while (ql0 <= qr0 && q0[ql0] + 1 < l1[i]) ql0++;
		while (ql1 <= qr1 && q1[ql1] + 1 < l0[i]) ql1++;
		if (ql1 <= qr1) f0[i] = i == n || a[i + 1] < a[q1[ql1]];
		if (ql0 <= qr0) f1[i] = i == n || a[i + 1] > a[q0[ql0]];
		pre[0][i] = q1[ql1];
		pre[1][i] = q0[ql0];
		if (l0[i] == 1){
			f0[i] = true;
			pre[0][i] = 0;
		}
		if (l1[i] == 1){
			f1[i] = true;
			pre[1][i] = 0;
		}
		if (f0[i]){
			while (ql0 <= qr0 && a[q0[qr0]] >= a[i]) qr0--;
			q0[++qr0] = i;
		}
		if (f1[i]){
			while (ql1 <= qr1 && a[q1[qr1]] <= a[i]) qr1--;
			q1[++qr1] = i;
		}
	}
	if (!f0[n] && !f1[n]){
		printf("NO\n");
		return 0;
	}
	int nw;
	if (f0[n]) nw = 1;
	if (f1[n]) nw = 0;
	for (int i = n; i != 0; i = pre[nw][i]){
		nw ^= 1;
		for (int j = i; j > pre[nw][i]; j--) ans[j] = nw;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}