#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll solve(int n, bool ok = false) {
	int ans = 0;
	while (n) {
		int s = pow(n, 1. / 3) + E;
		while ((s + 1) * (s + 1) * (s + 1) <= n)
			s++;
		if (ok)
			cout << (s + 1) * (s + 1) * (s + 1) << " " << n << endl;
		n -= s * s * s;
		if (ok)
			cout << s << endl;
		ans++;
	}
	return ans;
}

ii solve_long(int n) {
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		int res = solve(i);
		if (res >= ans1) {
			ans1 = res;
			ans2 = i;
		}
	}
	//solve(ans2, true);
	return make_pair(ans1, ans2);
}

ll S(ll m) {
	return m * m * m;
}

bool check(vector<ll> vec, ll n) {
	ll sum = 0;
	for (int i = 0; i < (int) vec.size(); i++) {
		ll q = S(vec[i]);
		sum += q;
	}
	if (sum > n)
		return false;
	n = sum;
	while (n) {
		ll s = pow(n, 1.0 / 3) + E;
		while (S(s) > n)
			s--;
		while (S(s + 1) <= n)
			s++;
		n -= S(s);
		if (vec.empty() || vec.back() != s)
			return false;
		vec.pop_back();
	}
	return vec.empty();
}

ll max_ans = 0;

ll S(vector<ll> vec) {
	ll ans = 0;
	for (int i = 0; i < (int) vec.size(); i++)
		ans += S(vec[i]);
	return ans;
}

vector<ll> v;
void dfs(vector<ll> vec, ll n, int pos) {
	if (check(vec, n)) {
		max_ans = max(max_ans, S(vec));
		for (int i = pos; i < (int) vec.size(); i++) {
			if (i + 1 == (int) vec.size() || vec[i] != vec[i + 1]) {
				vector<ll> v;
				v.insert(v.end(), vec.begin(), vec.end());
				v[i]++;
				dfs(v, n, max(i - 1, 0));
			}
		}
	}
}

ii solve_quick(ll n) {
	max_ans = 0;
	ll next = 8, t = 2;
	ll now = 1;
	ll ans = 0;
	v.clear();
	for (ll i = 0; i < n;) {
		while (i + now >= next) {
			now = next;
			t++;
			next = t * t * t;
		}
		if (now > n || i + now > n) {
			break;
		}
		ans++;
		v.push_back(t - 1);
		i += now;
	}
	for (int i = (int) v.size() - 1; i >= 0; i--) {
		do {
			v[i]++;
		} while (check(v, n));
		v[i]--;
	}
	ll sum = 0;
	for (int i = 0; i < (int) v.size(); i++) {
		sum += S(v[i]);
	}
	return make_pair(ans, sum);

}

int main() {

#ifdef LOCAL
	input;
	//output;
#else

#endif

	ll n;
	cin >> n;

	ii res = solve_quick(n);
	cout << res.first << " " << res.second << endl;

}