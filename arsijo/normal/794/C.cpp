#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	string s1, s2;
	cin >> s1 >> s2;

	if((int) s1.size() == 1) {
		cout << s1 << endl;
		return 0;
	}

	deque<char> d1, d2;

	sort(s1.begin(), s1.end());
	for(char c : s1) {
		d1.push_back(c);
	}

	sort(s2.begin(), s2.end());
	for(char c : s2) {
		d2.push_back(c);
	}
	int n = (int) s1.size();

	int m = n / 2;

	while(m--){
		d1.pop_back();
	}

	m = (n + 1) / 2;

	while(m--){
		d2.pop_front();
	}

	int l = 0, r = (int) s1.size() - 1;
//	cout << s1 << endl << s2 << endl;
	string ans = string(r + 1, '0');

	bool first = true;

	while(l < r){
		if(first){
			if(d2.back() <= d1.front()){
				ans[r--] = d1.back();
				d1.pop_back();
			}else{
				ans[l++] = d1.front();
				d1.pop_front();
			}
		}else{
			if(d2.back() <= d1.front()){
				ans[r--] = d2.front();
				d2.pop_front();
			}else{
				ans[l++] = d2.back();
				d2.pop_back();
			}
		}
		first = !first;
	}

	ans[l] = (d1.empty() ? d2.back() : d1.back());

	cout << ans << endl;

}