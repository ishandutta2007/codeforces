#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
#define remove tipa_remove
#define next tipa_next
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
const int MAX = 5000;
vector<int> vec[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	int s = 0;
	for(int i = 0; i < n; i++) {
		int k;
		ll a, x, y, m;
		cin >> k >> a >> x >> y >> m;
		vec[i].push_back(a);
		while((int) vec[i].size() < k) {
			a = (a * x + y) % m;
			vec[i].push_back(a);
		}
		s += k;
		reverse(vec[i].begin(), vec[i].end());
	}

	bool ok = true;

	vector<ii> ans;
	int _ans = -1;
	bool T = true;
	const int MAX_SIZE = 2e5;
	while(ok) {
		_ans++;
		vector<ii> res;
		ok = false;
		for(int i = 0; i < n; i++) {
			if(!vec[i].empty()) {
				int val = vec[i].back();
				if(T)
				res.push_back(make_pair(val, i + 1));
				vec[i].pop_back();
				while(!vec[i].empty() && vec[i].back() >= val) {
					val = vec[i].back();
					vec[i].pop_back();
					if(T) {
						res.push_back(make_pair(val, i + 1));
						if((int) res.size() > MAX_SIZE) {
							T = false;
						}
					}
				}
				if(!vec[i].empty())
				ok = true;
			}
		}
		if(T) {
			sort(res.begin(), res.end());
			ans.insert(ans.end(), res.begin(), res.end());
			if((int) ans.size() > MAX_SIZE)
				T = false;
		}
	}

	cout << _ans << endl;
	if(T)
	for(ii a : ans) {
		cout << a.first << " " << a.second << endl;
	}

}