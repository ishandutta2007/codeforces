#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 10007;
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

int n;
const int MAX = 2e5 + 1;
vector<int> vec[MAX];
int a[MAX];

vector<int> ans;
bool has_down[MAX];

void go(int pos){
	ans.push_back(pos);
	a[pos] = !a[pos];
}

bool pre_calc(int pos, int prev = -1){
	has_down[pos] = !a[pos];
	for(int i = 0; i < (int) vec[pos].size(); i++){
		int to = vec[pos][i];
		if(to != prev){
			has_down[pos] |= pre_calc(to, pos);
		}
	}
	return has_down[pos];
}

void dfs(int pos, int prev = -1){
	if(pos == 1){
		ans.push_back(1);
	}else{
		go(pos);
	}
	for(int i = 0; i < (int) vec[pos].size(); i++){
		int to = vec[pos][i];
		if(to != prev && has_down[to]){
			dfs(to, pos);
			go(pos);
		}
	}
	if(!a[pos]){
		if(pos == 1){
			go(vec[pos][0]);
			go(1);
			go(vec[pos][0]);
		}else{
			go(prev);
			go(pos);
		}
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
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == -1)
			a[i] = 0;
	}

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	pre_calc(1);

	dfs(1);
	for(int i = 0; i < (int) ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++){
		assert(a[i] == 1);
	}

}