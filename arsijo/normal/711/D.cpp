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
#ifndef LLONG_MAX
#define LLONG_MAX LONG_LONG_MAX
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

const int MAX = 2e5 + 1;
int to[MAX];
vector<int> vec[MAX];
int used[MAX];
int size;

int dfs(int pos){
	int ans = 1;
	used[pos] = size;
	for(int i = 0; i < (int) vec[pos].size(); i++){
		if(used[vec[pos][i]] != size)
		ans += dfs(vec[pos][i]);
	}
	return ans;
}

ll _pow(ll n, ll m){
	return (m == 0 ? 1 : m & 1 ? n * _pow(n, m - 1) : sqr(_pow(n, m >> 1))) % MOD;
}

int main() {
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> to[i];
		vec[to[i]].push_back(i);
	}
	size = 0;

	ll ans = 1;
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			size++;
			int a = 0;
			int b = 0;
			vector<int> v;
			int pos = i;
			do{
				used[pos] = size;
				v.push_back(pos);
				pos = to[pos];
			}while(used[pos] != size);
			size++;
			vector<int> vv;
			while(v.back() != pos){
				vv.push_back(v.back());
				v.pop_back();
			}
			vv.push_back(pos);
			a = (int) vv.size();
			for(int i = 0; i < (int) vv.size(); i++){
				used[vv[i]] = size;
			}
			for(int i = 0; i < (int) vv.size(); i++){
				b += dfs(vv[i]) - 1;
			}
			ll f = _pow(2, a) - 2;
			if(f < 0)
				f += MOD;
			f = (f * _pow(2, b)) % MOD;
			ans = (ans * f) % MOD;
		}
	}

	cout << ans << endl;

}