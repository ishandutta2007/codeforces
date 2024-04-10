# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int MAXB = 451;
int t, n, e;
int a[MAXN];
int pre[MAXN], nxt[MAXN];
bool isPrime(int x){
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &e);
		int B = int(sqrt(n));
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++){
			if (i - e >= 1 && a[i - e] == 1) pre[i] = pre[i - e] + 1;
			else pre[i] = 1;
		}
		for (int i = n; i >= 1; i--){
			if (i + e <= n && a[i + e] == 1) nxt[i] = nxt[i + e] + 1;
			else nxt[i] = 1;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			if (!isPrime(a[i])) continue;
			ans = (ans + 1ll * pre[i] * nxt[i] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}