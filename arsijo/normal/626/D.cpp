#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> inline T sqr(T a) {
	return a * a;
}
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-15;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

ll sum(ll n) {
	return n * (n + 1) / 2;
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int MAX = 1e4 + 10;

	sort(ar, ar + n);

	int d[MAX];
	ms(d, 0);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d[ar[j] - ar[i]]++;
		}
	}

	ll r[MAX];
	ms(r, 0);

	for (int i = 0; i <= MAX / 2; i++) {
		for (int j = 0; j <= MAX / 2; j++) {
			r[i + j] += d[i] * 1LL * d[j];
		}
	}

	ll t[MAX];
	ms(t, 0);
	for (int i = 0; i < n; i++)
		t[ar[i]]++;
	for (int i = 1; i < MAX; i++)
		t[i] += t[i - 1];

	ld ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX; j++) {
			if (!r[j])
				continue;
			ll now = ar[i] - j - 1;
			//cout << now << " " << ar[i] << " " << j << " " << r[j] << endl;
			if (now > 0)
				ans += t[now] * r[j];
		}
	}

	//cout << ans << endl;

	for (int i = 0; i < 3; i++) {
		ans /= (ld) sum(n - 1);
	}

	cout << ans << endl;

}