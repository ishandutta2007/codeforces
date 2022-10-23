# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
const int PR = 998244353;
ll n;
char lc, rc;
char s[NR];
int main(){
	scanf("%lld", &n);
	scanf("%s", s + 1);
	lc = s[1];
	rc = s[n];
	ll lnm = 1, rnm = 1;
	while (s[lnm] == lc) lnm++;
	while (s[n - rnm + 1] == rc) rnm++;
	ll ans;
	if (lnm == n + 1) ans = n * (n + 1) / 2;
	else if (lc == rc) ans = lnm * rnm;
	else ans = lnm + rnm - 1;
	printf("%lld\n", ans % PR);
	return 0;
}