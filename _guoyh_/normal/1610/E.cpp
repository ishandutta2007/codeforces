# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 200051;
int t, n;
int a[MAXN];
int nxt[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		nxt[n] = n + 1;
		for (int i = n - 1; i >= 1; i--){
			if (a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
			else nxt[i] = i + 1;
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i++){
			int nw = nxt[i];
			int cnt = nxt[i] - i;
			while (nw <= n){
				cnt++;
				nw = lower_bound(a + nw + 1, a + n + 1, a[nw] - a[i] + a[nw]) - a;
			}
			ans = min(ans, n - cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}