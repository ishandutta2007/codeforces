#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
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
inline void write(ll y) {
	long long x = y;
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct str {
	map<int, ii> m;
	bool has(int val) {
		return m.find(val) != m.end();
	}
	ii get(int val) {
		return m[val];
	}
	void set(int val, ii res) {
		//cout << "+ " << val << " " << res.first << " " << res.second << endl;
		m[val] = res;
	}
	void del(int val) {
		//cout << "del " << val << endl;
		m.erase(val);
	}
};

int operator&(ii a, ii b) {
	if (a.second < b.first || b.second < a.first)
		return 0;
	//cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
	int ans = abs(max(a.first, b.first) - min(a.second, b.second)) + 1;
	//cout << "! " << ans << endl;
	return ans;
}

str t1, t2;

ll get(int val) {
	if (t1.has(val) && t2.has(val))
		return t1.get(val) & t2.get(val);
	return 0;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	ll res = 0;
	ll ans = 0;
	stack<ii> s1, s2;
	s1.push(make_pair(INT_MAX, -1));
	s2.push(make_pair(INT_MIN, -1));

	for(int i = 0; i < n; i++) {
		set<int> to_delete;
		set<int> to_add;
		int l1 = i;
		while(s1.top().first <= a[i]) {
			l1 = s1.top().second;
			res -= get(s1.top().first);
			t1.del(s1.top().first);
			s1.pop();
		}
		if(s1.top().first != a[i]) {
			t1.set(a[i], make_pair(l1, i));
			s1.push(make_pair(a[i], l1));
			res += get(s1.top().first);
		}
		int l2 = i;
		while(s2.top().first >= b[i]) {
			l2 = s2.top().second;
			res -= get(s2.top().first);
			t2.del(s2.top().first);
			s2.pop();
		}
		if(s2.top().first != b[i]) {
			t2.set(b[i], make_pair(l2, i));
			s2.push(make_pair(b[i], l2));
			res += get(s2.top().first);
		}
		//cout << res << endl;
		ans += res;
	}

	cout << ans << endl;

}