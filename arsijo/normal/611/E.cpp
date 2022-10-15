#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
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

multiset<int> s;

bool take(int v) {
	multiset<int>::iterator it = s.lower_bound(-v);
	if (it == s.end())
		return false;
	s.erase(it);
	return true;
}

int top() {
	return (s.empty() ? 0 : -(*s.begin()));
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	//rand_test();
	input;
#else

#endif

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		s.insert(-d);
	}

	if (a > b)
		swap(a, b);
	if (c < b)
		swap(c, b);
	if (a > b)
		swap(a, b);

	int ans = 0;

	if (top() > a + b + c) {
		cout << -1;
		return 0;
	}

	while (top() > b + c) {
		take(a + b + c);
		ans++;
	}

	while (top() > a + c) {
		take(b + c);
		take(a);
		ans++;
	}

	while (top() > a + b && top() > c) {
		take(a + c);
		take(b);
		ans++;
	}

	while (a + b > c && top() > c) {
		take(a + b);
		take(c);
		ans++;
	}

	while(take(b)){
		take(a);
		take(c);
		ans++;
	}

	while(!s.empty()){
		take(a + b);
		take(c);
		ans++;
	}

	cout << ans;

}