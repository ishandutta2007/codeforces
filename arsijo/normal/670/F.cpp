#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
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
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int ar[10];

void add(int n, int val) {
	while (n) {
		ar[n % 10] += val;
		n /= 10;
	}
}

bool check() {
	for (int i = 0; i < 10; i++)
		if (ar[i] < 0)
			return false;
	return true;
}

bool has_no_zero() {
	for (int i = 1; i < 10; i++)
		if (ar[i] > 0)
			return true;
	return false;
}

bool check(string& a, string& b) {
	if(b.empty())
		return true;
	return a + b < string(1, b[0]) + a + b.substr(1, b.size() - 1);
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(0);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	string s;
	cin >> s;

	if(s.size() == 2) {
		char c = (s[0] == '1' ? s[1] : s[0]);
		cout << c << endl;
		return 0;
	}

	for(int i = 0; i < (int) s.size(); i++) {
		ar[s[i] - '0']++;
	}

	string t;
	cin >> t;
	for(int i = 0; i < (int) t.size(); i++) {
		ar[t[i] - '0']--;
	}

	int n = (int) s.size();

	int size = 0;
	for(int i = 1, w = 1, next = 10; i < n; i++) {
		if(i == next) {
			w++;
			next *= 10;
		}
		if(i + w == n) {
			add(i, -1);
			bool ok = check() && (t[0] != '0' || has_no_zero());
			add(i, +1);
			if(ok) {
				size = i;
				break;
			}
		}
	}

	add(size, -1);

	if(!has_no_zero()) {
		cout << t;
		for(int i = 0; i < ar[0]; i++)
		cout << 0;
		cout << endl;
		return 0;
	}

	string q;
	for(int i = 1; i <= 9; i++) {
		if(ar[i]) {
			q += char(i + '0');
			ar[i]--;
			break;
		}
	}

	for(int i = 0; i <= 9; i++) {
		if(ar[i])
		q += string(ar[i], i + '0');
	}

	ar[q[0] - '0']++;

	string e;
	int l = (t[0] == '0'), r = (int) q.size();
	while(l < r){
		int i = (l + r) >> 1;
		e = q.substr(i, (int) q.size() - i);
		if(check(t, e))
			r = i;
		else
			l = i + 1;
	}

	string ans;

	for(int i = 0; i < l; i++)
		ans += q[i];
	ans += t;
	for(int i = l; i < (int) q.size(); i++)
		ans += q[i];



	if(t[0] == '0'){
		cout << ans << endl;
		return 0;
	}

	string ans2 = t;
	for(int i = 0; i < 10; i++){
		ans2 += string(ar[i], i + '0');
	}

	cout << (ans < ans2 ? ans : ans2) << endl;

}