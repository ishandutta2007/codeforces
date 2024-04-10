#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
#define MAXN 200087
int MOD = 1e9 + 7;
lli frac[MAXN], fracp[MAXN];

lli C (int a, int b) {
	return frac[a] * fracp[b] % MOD * fracp[a-b] % MOD;
}

lli modinv (int b) {
	int a1 = b, a2 = MOD, a3 = 1, a4 = 0;
	while (a2 != 0) {
		tie(a3, a4) = make_pair(a4, a3 - a1 / a2 * a4);
		tie(a1, a2) = make_pair(a2, a1 % a2);
	}
	return a3;
}

int main () {
	int n, r, c, x, y;
	cin >> r >> c >> n;
	pii p[n+1];
	lli dp[n];
	fop (i,0,n) cin >> p[i].first >> p[i].second;
	p[n] = mp(r,c);
	sort(p, p + n+1);
	frac[0] = 1;
	fop (i,1,MAXN) frac[i] = frac[i-1] * i % MOD;
	fop (i,0,MAXN) fracp[i] = modinv(frac[i]);
	fop (i,0,n+1) {
		tie(x, y) = p[i];
		dp[i] = C(x + y - 2, x - 1);
		fop (j,0,i) {
			if (p[j].first <= x and p[j].second <= y) {
				dp[i] -= (dp[j] * C(x + y - p[j].first - p[j].second, x - p[j].first));
				dp[i] %= MOD;
			}
		}
	}
	if (dp[n] < 0) dp[n] += MOD;
	cout << dp[n] << endl;
}