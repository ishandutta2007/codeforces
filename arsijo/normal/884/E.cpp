#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 10;
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

const int MAX_N = (1 << 12);
const int MAX_M = (1 << 14);

int t[MAX_M + MAX_M];

int get(int pos){
	return (t[pos] == pos ? pos : t[pos] = get(t[pos]));
}

bool one[2][MAX_M];

bool unite(int a, int b){
	a = get(a);
	b = get(b);
	if(a != b){
		t[a] = b;
		return true;
	}else{
		return false;
	}
}

int to[MAX_M + MAX_M];
int val[MAX_M];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	read(n);
	read(m);
	char c;
	int ind = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j += 4) {
			c = getchar();
			ind = ('0' <= c && c <= '9' ? c - '0' : c - 'A' + 10);
			one[1][j] = ((ind & 8) ? 1 : 0);
			one[1][j + 1] = ((ind & 4) ? 1 : 0);
			one[1][j + 2] = ((ind & 2) ? 1 : 0);
			one[1][j + 3] = ((ind & 1) ? 1 : 0);
		}
		dbg { for(int i = 0; i < m; i++){
			cout << one[1][i];
		}
		cout << endl;
		for(int i = 0; i < m; i++){
			cout << t[i] << " ";
		}
		cout << endl; }
		getchar();
		for(int j = 0; j < m; j++){
			t[MAX_M + j] = j + MAX_M;
			if(one[1][j]){
				dbg cout << "+ " << j << endl;
				ans++;
			}
		}
		for(int i = 1; i < m; i++){
			if(one[1][i] && one[1][i - 1]){
				dbg cout << "--- " << i << endl;
				ans -= unite(MAX_M + i - 1, MAX_M + i);
				dbg cout << ans << endl;
			}
		}
		for(int i = 0; i < m; i++){
			if(one[1][i] && one[0][i]){
				dbg cout << "- " << i << endl;
				ans -= unite(i, MAX_M + i);
				dbg cout << ans << endl;
			}
		}
		for(int i = 0; i < MAX_M * 2; i++){
			to[i] = -1;
		}
		for(int i = 0; i < m; i++){
			if(one[1][i] && to[get(MAX_M + i)] == -1){
				val[i] = to[get(MAX_M + i)] = i;
			}else{
				val[i] = (one[1][i] ? to[get(MAX_M + i)] : 0);
			}
		}
		for(int i = 0; i < m; i++){
			t[i] = val[i];
			t[i + MAX_M] = i + MAX_M;
			one[0][i] = one[1][i];
		}
	}

	cout << ans << endl;

}