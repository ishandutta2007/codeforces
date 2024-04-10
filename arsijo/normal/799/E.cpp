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

int n, m, k;

const int MAX = 2e5 + 10;

int c[MAX];
bool ok1[MAX], ok2[MAX];

ll ans;
const ll INF = 1e18;
struct str {
	multiset<int> m1, m2;
	ll sum = 0;
	str() {
		sum = 0;
	}
	void upd() {
		while (!m1.empty() && !m2.empty() && *m1.rbegin() > *m2.begin()) {
			int a = *m1.rbegin();
			m1.erase(m1.find(a));
			int b = *m2.begin();
			m2.erase(m2.begin());
			m1.insert(b);
			m2.insert(a);
			sum -= a;
			sum += b;
		}
	}
	ll get(int size) {
		upd();
		if ((int) m1.size() + (int) m2.size() < size)
			return INF;
		while ((int) m1.size() < size) {
			m1.insert(*m2.begin());
			sum += *m2.begin();
			m2.erase(m2.begin());
		}
		while ((int) m1.size() > size) {
			int a = *m1.rbegin();
			m1.erase(m1.find(a));
			sum -= a;
			m2.insert(a);
		}
		return sum;
	}
	void insert(int val) {
		m2.insert(val);
	}
	void erase(int a) {
		if (m1.find(a) != m1.end()) {
			sum -= a;
			m1.erase(m1.find(a));
		} else {
			m2.erase(m2.find(a));
		}
	}
};

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	ans = INF;

	cin >> n >> m >> k;

	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	int a;
	cin >> a;

	while(a--) {
		int t;
		cin >> t;
		ok1[t] = true;
	}

	cin >> a;

	while(a--) {
		int t;
		cin >> t;
		ok2[t] = true;
	}

	vector<int> v[2][2];
	for(int i = 1; i <= n; i++) {
		v[ok1[i]][ok2[i]].push_back(c[i]);
	}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			sort(v[i][j].begin(), v[i][j].end());
		}
	}

	str t;

	for(int a : v[0][0]) {
		t.insert(a);
	}

	ll sum1 = 0, sum2 = 0;
	for(int a : v[1][0]) {
		sum1 += a;
	}
	for(int a : v[0][1]) {
		sum2 += a;
	}

	for(int a : v[1][1]) {
		t.insert(a);
	}
	ll sum = 0;
	for(int i = 0; i <= (int) v[1][1].size(); i++) {
		if(i){
		t.erase(v[1][1][i - 1]);
		sum += v[1][1][i - 1];
		}
		int used = i + (k - i) * 2;
		if(used > m)
		continue;
		int need = k - i;
		if(need < 0)
		continue;
		if((int) min(v[0][1].size(), v[1][0].size()) < need)
		continue;
		while((int) v[1][0].size() > need) {
			sum1 -= v[1][0].back();
			t.insert(v[1][0].back());
			v[1][0].pop_back();
		}
		while((int) v[0][1].size() > need) {
			sum2 -= v[0][1].back();
			t.insert(v[0][1].back());
			v[0][1].pop_back();
		}
		ans = min(ans, sum + sum1 + sum2 + t.get(m - used));
	}

	if(ans == INF){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}

}