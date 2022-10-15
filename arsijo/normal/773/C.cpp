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
#ifndef LOCAL
#define map unordered_map
#endif

int bits(ll n){
	int ans = 0;
	while(n){
		ans += n & 1;
		n >>= 1;
	}
	return ans;
}

bool is_power(ll n){
	return bits(n) == 1;
}

int get_power(ll n){
	for(int i = 0; i < 50; i++){
		if(n & (1LL << i))
			return i;
	}
	return -1;
}

int v[50];
vector<ll> vec;

int a[50], b[50];

bool check(int x){
	vector<int> v(50);
	for(int i = 0; i < 50; i++){
		v[i] = ::v[i];
	}
	ms(a);
	ms(b);
	for(ll a : vec){
		int last = 0;
		for(int i = 0; (1LL << i) < a; i++){
			if(!v[i])
				return false;
			v[i]--;
			last = i;
		}
		::a[last]++;
		x--;
	}
	for(int i = 0; i < x; i++){
		b[0]++;
		v[0]--;
	}
	for(int i = 1; i < 50; i++){
		while(v[i] && (b[i - 1])){
			b[i - 1]--;
			v[i]--;
			b[i]++;
		}
		while(v[i] && (a[i - 1])){
			a[i - 1]--;
			a[i]++;
			v[i]--;
		}
	}
	int j = 49;
	for(int i = 49; i >= 0; i--){
		while(v[i]){
			while(j >= 0 && b[j] == 0)
				j--;
			if(j < 0 || (j + 1) < i)
				return false;
			b[j]--;
			v[i]--;
		}
	}
	return true;
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

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(is_power(a)){
			v[get_power(a)]++;
		}else{
			vec.push_back(a);
		}
	}

	sort(vec.begin(), vec.end());

	int l = max(1, (int) vec.size());
	int r = v[0];

	while(l < r){
		int x = (l + r) >> 1;
		if(check(x)){
			r = x;
		}else{
			l = x + 1;
		}
	}

	if(check(v[0])){
		while(l <= v[0]){
			cout << l << " ";
			l++;
		}
	}else{
		cout << -1 << endl;
	}

}