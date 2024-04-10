# include <bits/stdc++.h>
# define ll long long
using namespace std;
typedef pair <int, int> pii;
const int MAXN = 200051;
int t, n;
int a[MAXN];
int nxt[MAXN], lst[MAXN];
int flag[MAXN];
int ans[MAXN];
pii fd(){
	int mx = 0;
	for (int i = 0; i <= n; i++){
		if (!flag[i]) return pii(i, mx);
		else mx = max(mx, flag[i]);
	}
	return pii(-1, -1);
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			if (lst[a[i]]) nxt[lst[a[i]]] = i;
			lst[a[i]] = i;
			if (!flag[a[i]]) flag[a[i]] = i;
		}
		int p = 1;
		int cnt = 0;
		while (p <= n){
			pii nm = fd();
			int mx = nm.first;
			int np = max(p, nm.second);
			for (int i = p; i <= np; i++) flag[a[i]] = nxt[i];
			ans[++cnt] = mx;
			p = np + 1;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
		putchar('\n');
		for (int i = 1; i <= n; i++) flag[a[i]] = lst[a[i]] = nxt[i] = 0;
	}
	return 0;
}