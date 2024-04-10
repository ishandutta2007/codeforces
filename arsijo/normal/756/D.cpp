#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define M_PI acos(-1)
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline ld sqr(ld t) {
	return (t * t);
}
inline void read(ll &n) {
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
bool ok[26];
bool go[26][26];
const int MAX = 5005;
int dp[2][MAX], nearest[MAX][26];
int INF = 1e9;

inline void upd(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int solve_long(string t) {
	set<string> s;
	queue<string> q;
	s.insert(t);
	q.push(t);
	while (!q.empty()) {
		string t = q.front();
		q.pop();
		for (int i = 1; i < (int) t.size(); i++) {
			string w = t;
			w[i] = w[i - 1];
			if (s.find(w) == s.end()) {
				s.insert(w);
				q.push(w);
			}
			w = t;
			w[i - 1] = w[i];
			if (s.find(w) == s.end()) {
				s.insert(w);
				q.push(w);
			}
		}
	}
	return s.size();
}

int last[26];
int dp3[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		s += char(rand() % 26 + 'a');
	}
	cin >> s;

	string t = "";
	for(int i = 0; i < (int) s.size(); i++) {
		if(i == 0 || s[i] != s[i - 1]) {
			t += s[i];
		}
	}
	int k = (int) t.size();
	for(int i = 0; i < 26; i++) {
		nearest[k + 1][i] = k + 1;
	}
	for(int i = k; i; i--) {
		for(int j = 0; j < 26; j++) {
			nearest[i][j] = nearest[i + 1][j];
		}
		nearest[i][t[i - 1] - 'a'] = i;
	}

	for(int i = 0; i < 26; i++) {
		if(nearest[1][i] < INF) {
			dp[1][nearest[1][i]] = 1;
		}
	}
	for(int i = 2; i <= n; i++) {
		int a = i & 1;
		int b = 1 - a;
		for(int j = 1; j <= k; j++) {
			dp[a][j] = dp[b][j];
			dp3[j] = dp[a][j];
		}
		ms(last);
		for(int j = 1; j <= k; j++) {
			int q = t[j - 1] - 'a';
			int val = dp3[j - 1] - dp3[last[q]];
			if(val < 0)
				val += MOD;
			upd(dp[a][j], val);
			//upd(dp3[j], val);
			upd(dp3[j], dp3[j - 1]);
			last[q] = j;
		}
	}

	int ans = 0;

	for(int j = 1; j <= k; j++) {
		upd(ans, dp[n & 1][j]);
	}

	cout << ans << endl;

}