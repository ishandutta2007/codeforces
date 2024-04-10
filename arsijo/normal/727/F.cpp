#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 2012;
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
#define prev asdklhsdireufhdashj
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

const int MAX = 753;

int n, m;

ll ar[MAX];

int check(ll now) {
	priority_queue<int> s;
	for (int i = 1; i <= n; i++) {
		now += ar[i];
		s.push(-ar[i]);
		while (now < 0) {
			now += s.top();
			s.pop();
		}
	}
	return (int) s.size();
}

int check2(ll now) {
	multiset<int> s;
	for (int i = 1; i <= n; i++) {
		now += ar[i];
		s.insert(ar[i]);
		cout << now << " " << i << endl;
		if(0) while (now < 0) {
			cout << i << " " << "$ " << now << " " << *s.begin() << endl;
			now -= *s.begin();
			s.erase(s.begin());
		}
	}
	return (int) s.size();
}

ll need[MAX];

void solve(int l, int r, ll L, ll R){
	if(l > r)
		return;
	if(L == R){
		for(int i = l; i <= r; i++)
			need[i] = L;
		return;
	}
	ll x = (L + R) >> 1;
	int f = check(x);
	solve(l, f, L, x);
	solve(f + 1, r, x + 1, R);
}

const int MAX_Q = 2E5;
int ans[MAX_Q];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	read(n);
	read(m);
	for(int i = 1; i <= n; i++) {
		read(ar[i]);
	}

	solve(0, n, 0, 1e12);

	vector<ii> vec(m);
	for(int i = 0; i < m; i++){
		read(vec[i].first);
		vec[i].second = i;
	}

	sort(vec.rbegin(), vec.rend());

	int l = 0;
	for(int i = n; i >= 0; i--){
		while(l < (int) vec.size() && need[i] <= vec[l].first){
			ans[vec[l].second] = n - i;
			l++;
		}
	}


	for(int i = 0; i < m; i++){
		write(ans[i]);
		putchar('\n');
	}

}