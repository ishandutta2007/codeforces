#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int T, n, X[N], Y[N];
int pmxx[N], pmnx[N], pmxy[N], pmny[N];
int smxx[N], smnx[N], smxy[N], smny[N];
char s[N];
long long ans;
long long calc(int mxx, int mnx, int mxy, int mny){
	return 1ll * (mxx - mnx + 1) * (mxy - mny + 1);
}
void solve(){
	scanf("%s", s + 1), n = strlen(s + 1), ans = 1e18;
	int mnx = 0, mxx = 0, mny = 0, mxy = 0, x = 0, y = 0;
	X[0] = Y[0] = pmxx[0] = pmnx[0] = pmxy[0] = pmny[0] = 0;
	for (register int i = 1; i <= n; ++i){
		if (s[i] == 'W') --x, mnx = std :: min(mnx, x);
		if (s[i] == 'S') ++x, mxx = std :: max(mxx, x);
		if (s[i] == 'A') --y, mny = std :: min(mny, y);
		if (s[i] == 'D') ++y, mxy = std :: max(mxy, y);
		X[i] = x, Y[i] = y, pmxx[i] = mxx, pmnx[i] = mnx, pmxy[i] = mxy, pmny[i] = mny;
	}
	smxx[n + 1] = smnx[n + 1] = x, smxy[n + 1] = smny[n + 1] = y;
	for (register int i = n; i; --i){
		smxx[i] = std :: max(smxx[i + 1], X[i - 1]), smnx[i] = std :: min(smnx[i + 1], X[i - 1]);
		smxy[i] = std :: max(smxy[i + 1], Y[i - 1]), smny[i] = std :: min(smny[i + 1], Y[i - 1]);
	}
	for (register int i = 1; i <= n + 1; ++i)
		ans = std :: min(ans, calc(std :: max(pmxx[i - 1], smxx[i] + 1), std :: min(pmnx[i - 1], smnx[i] + 1), mxy, mny));
	for (register int i = 1; i <= n + 1; ++i)
		ans = std :: min(ans, calc(std :: max(pmxx[i - 1], smxx[i] - 1), std :: min(pmnx[i - 1], smnx[i] - 1), mxy, mny));
	for (register int i = 1; i <= n + 1; ++i)
		ans = std :: min(ans, calc(mxx, mnx, std :: max(pmxy[i - 1], smxy[i] + 1), std :: min(pmny[i - 1], smny[i] + 1)));
	for (register int i = 1; i <= n + 1; ++i)
		ans = std :: min(ans, calc(mxx, mnx, std :: max(pmxy[i - 1], smxy[i] - 1), std :: min(pmny[i - 1], smny[i] - 1)));
	printf("%lld\n", ans);
}
int main(){
	scanf("%d", &T);
	while (T--) solve();
}