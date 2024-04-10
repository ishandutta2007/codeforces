#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
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
const ld E = 1e-10;
const ll MOD = 51123987;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 1e6 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

ll sum(ll n){
	return n * (n + 1) / 2;
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;

#ifdef LOCAL
	input;
#endif

	int n;
	cin >> n;

	vector<ii> vec(n);
	for(int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	n = 2002;
	int m = n * 2 + 10;
	int a[m], b[m];
	ms(a, 0);
	ms(b, 0);

	for(int i = 0; i < (int) vec.size(); i++){
		a[vec[i].first + vec[i].second]++;
		b[vec[i].first - vec[i].second + n + 1]++;
	}

	ll ans = 0;
	for(int i = 0; i < m; i++){
		if(a[i])
			ans += sum(a[i] - 1);
		if(b[i])
			ans += sum(b[i] - 1);
	}

	cout << ans;

}