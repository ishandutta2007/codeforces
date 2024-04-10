#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
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

const int MAX = 1e5 + 10;
int t[MAX << 2];
int ar[MAX];
vector<int> vec[MAX];
vector<int> v[MAX];
int ans[MAX];
int n;

void upd(int v, int l, int r, int pos, int val){
	t[v] += val;
	if(l == r)
		return;
	int x = (l + r) >> 1;
	if(pos <= x){
		upd(v << 1, l, x, pos, val);
	}else{
		upd(v << 1 | 1, x + 1, r, pos, val);
	}
}

void upd(int pos, int val){
	upd(1, 1, n + 1, pos, val);
}

void solve(int v, int l, int r, int &has, int &ans){
	if(t[v] < has){
		has -= t[v];
		return;
	}
	if(has == 0)
		return;
	if(l == r){
		has = 0;
		ans = r;
		return;
	}
	int x = (l + r) >> 1;
	solve(v << 1, l, x, has, ans);
	solve(v << 1 | 1, x + 1, r, has, ans);
}

int solve(int has){
	int ans = n + 1;
	solve(1, 1, n + 1, has, ans);
	return ans;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> ar[i];
		vec[ar[i]].push_back(i);
	}

	for(int i = 1; i <= n; i++){
		reverse(vec[i].begin(), vec[i].end());
		if(!vec[i].empty()){
			upd(vec[i].back(), +1);
		}
	}

	upd(n + 1, +1);

	for(int i = 1; i <= n; i++){
		v[1].push_back(i);
	}

	for(int i = 1; i <= n; i++){
		for(int a : v[i]){
			ans[a]++;
			v[solve(a + 1)].push_back(a);
		}
		int val = ar[i];
		upd(i, -1);
		vec[val].pop_back();
		if(!vec[val].empty()){
			upd(vec[val].back(), +1);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}

}