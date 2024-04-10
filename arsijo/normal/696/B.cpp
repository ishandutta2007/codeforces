#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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
char wwww[19];
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

const int MAX = 1e5 + 1;
vector<int> vec[MAX];
int down[MAX];
int n;
ld ans[MAX];

void dfs_1(int pos) {
	down[pos] = 1;
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		dfs_1(vec[pos][i]);
		down[pos] += down[vec[pos][i]];
	}
}

ld get(int n) {
	ld ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (ld) 1 / (ld) i / (ld) n;
	}
	return ans;
}

void dfs(int pos) {
	ld now = ans[pos];
	ll sum = down[pos] - 1;
	if (vec[pos].size() == 1) {
		ans[vec[pos][0]] = now + 1;
		dfs(vec[pos][0]);
		return;
	}
	ld q = 0;
	for (int i = 1; i < (int) vec[pos].size(); i++) {
		q += (ld) 1 * i / (ld) (vec[pos].size() - 1) / (ld) vec[pos].size();
	}
	//cout << vec[pos].size() << " " << q << endl;
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		ld res = now + 1;
		ld e = (sum - down[vec[pos][i]]) * q;
		ans[vec[pos][i]] = res + (ld) e;
		dfs(vec[pos][i]);
	}
}

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
	for(int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		vec[a].push_back(i);
	}
	dfs_1(1);
	ans[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++)
	cout << ans[i] << " ";

}