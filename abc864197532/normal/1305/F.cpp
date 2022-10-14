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
#define pli pair<lli,int> 
#define X first
#define Y second

set <lli> prime;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void frac (lli k) {
	if (k <= 1) return;
	for (lli i = 2; i * i <= k; ++i) {
		if (k % i == 0) {
			prime.insert(i);
			while (k % i == 0) k /= i;
		}
	}
	if (k > 1) prime.insert(k);
}

int main () {
	int n;
	cin >> n;
	vector <lli> input(n);
	fop (i,0,n) cin >> input[i];
	int t = 25;
	while (t--) {
		int k = uniform_int_distribution<int>(0, n - 1)(rng);
		frac(input[k] + 1);
		frac(input[k]);
		frac(input[k] - 1);
	}
	lli ans = n;
	for (lli p : prime) {
		lli tmp = 0;
		fop (i,0,n) tmp += 1ll * min(p - input[i] % p, input[i] >= p ? input[i] % p : 864197532);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}