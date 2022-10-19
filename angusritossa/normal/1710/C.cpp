#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
const ll MOD = 998244353;
#define MAXN 200010
int input[MAXN], n;
char inp[MAXN];
int dp[MAXN][2][2][2][2][2][2];
int main() {
	scanf(" %s", inp);
	n = strlen(inp);
	for (int i = 1; i <= n; i++) {
		input[i] = inp[i-1] == '1';
	}
	reverse(input+1, input+n+1);

	for (int upto = 0; upto <= n; upto++) {
	for (int matchinga = 0; matchinga <= 1; matchinga++) {
	for (int matchingb = 0; matchingb <= 1; matchingb++) {
	for (int matchingc = 0; matchingc <= 1; matchingc++) {
	for (int has1 = 0; has1 <= 1; has1++) {
	for (int abunique = 0; abunique <= 1; abunique++) {
	for (int acunique = 0; acunique <= 1; acunique++) {
		if (upto == 0) {
			if (has1 && abunique && acunique) {
				dp[upto][matchinga][matchingb][matchingc][has1][abunique][acunique] = 3;
			} else {
				dp[upto][matchinga][matchingb][matchingc][has1][abunique][acunique] = 0;
			}
			continue;
		}
		int mxa = 1, mxb = 1, mxc = 1;
		if (matchinga) mxa = input[upto];
		if (matchingb) mxb = input[upto];
		if (matchingc) mxc = input[upto];
		ll ans = 0;
		for (int a = 0; a <= mxa; a++) {
			int newMatchinga = matchinga;
			if (a < mxa) newMatchinga = 0;
			for (int b = 0; b <= mxb; b++) {
				int newMatchingb = matchingb;
				if (b < mxb) newMatchingb = 0;
				int ab = a^b;

				for (int c = 0; c <= mxc; c++) {
					int newMatchingc = matchingc;
					if (c < mxc) newMatchingc = 0;

					int ac = a^c;
					if (!has1 && ab != ac) continue;
					int newHas1 = has1;
					if (ab+ac) newHas1 = 1;
					int newabunique = abunique;
					if (ab > ac) newabunique = 1;
					int newacunique = acunique;
					if (ac > ab) newacunique = 1;

					ans += dp[upto-1][newMatchinga][newMatchingb][newMatchingc][newHas1][newabunique][newacunique];
				}
			}
		}
		dp[upto][matchinga][matchingb][matchingc][has1][abunique][acunique] = ans%MOD;
	} } } } } } }

	ll ans = dp[n][true][true][true][false][false][false];

	printf("%lld\n", ans);
}