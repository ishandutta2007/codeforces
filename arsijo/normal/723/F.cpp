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

int n, m;

struct dsu {
	int *t;
	dsu(int n) {
		t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = i;
		}
	}
	int get(int a) {
		return (t[a] == a ? a : t[a] = get(t[a]));
	}
	void unite(int a, int b) {
		t[get(a)] = get(b);
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

	cin >> n >> m;
	vector<ii> v, vec;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	int s, t, ds, dt;
	cin >> s >> t >> ds >> dt;
	dsu dsu(n + 1);
	vector<ii> ans;
	for(ii a : v) {
		if(a.first == s || a.second == s || a.first == t || a.second == t) {
			vec.push_back(a);
		} else {
			if(dsu.get(a.first) != dsu.get(a.second)) {
				ans.push_back(a);
				dsu.unite(a.first, a.second);
			}
		}
	}

	vector<int> ar1(n + 1), ar2(n + 1);

	bool has_connect = false;

	for(ii a : vec) {
		if(a.first == s || a.second == s) {
			if(a.second == s)
			swap(a.first, a.second);
			if(a.second == t) {
				has_connect = true;
			} else {
				ar1[dsu.get(a.second)] = a.second;
			}
		} else {
			if(a.second == t)
			swap(a.first, a.second);
			ar2[dsu.get(a.second)] = a.second;
		}
	}

	vector<int> e;
	for(int i = 1; i <= n; i++){
		if(ar1[i] || ar2[i]){
			if(ar1[i] && ar2[i]){
				e.push_back(i);
			}else{
				if(ar1[i]){
					ds--;
					ans.push_back(make_pair(s, ar1[i]));
				}else{
					dt--;
					ans.push_back(make_pair(t, ar2[i]));
				}
			}
		}
	}

	bool is_connected = false;

	if(!e.empty()){
		is_connected = true;
		ans.push_back(make_pair(s, ar1[e.back()]));
		ans.push_back(make_pair(t, ar2[e.back()]));
		e.pop_back();
		ds--, dt--;
		while(!e.empty()){
			int pos = e.back();
			e.pop_back();
			if(ds >= dt){
				ans.push_back(make_pair(s, ar1[pos]));
				ds--;
			}else{
				ans.push_back(make_pair(t, ar2[pos]));
				dt--;
			}
		}
	}

	if(!is_connected && has_connect){
		ds--, dt--;
		ans.push_back(make_pair(s, t));
		is_connected = true;
	}

	if(ds < 0 || dt < 0 || (int) ans.size() != n - 1){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for(ii a : ans){
		cout << a.first << " " << a.second << endl;
	}

}