#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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

struct hash_stirng {
	ll *t, *hash, key, MOD;
	hash_stirng(ll key, ll MOD, string s) {
		this->key = key;
		this->MOD = MOD;
		int n = (int) s.size();
		t = new ll[n + 1];
		hash = new ll[n + 1];
		hash[0] = 1;
		for (int i = 1; i <= n; i++) {
			hash[i] = (hash[i - 1] * key) % MOD;
		}
		t[0] = 0;
		for (int i = 1; i <= n; i++) {
			t[i] = ((t[i - 1] * key) + s[i - 1]) % MOD;
		}
	}
	inline ll get(int l, int r) {
		ll res = t[r];
		ll g = (t[l - 1] * hash[r - l + 1]) % MOD;
		res -= g;
		if (res < 0)
			res += MOD;
		return res;
	}
};

inline void read_string(string &ans) {
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		ans += ccc;
	}
}

bool prime(ll n){
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

const ll keys[10] = {307, 311, 313, 317, 331, 337, 347, 349, 353, 359};
const ll modules[10] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181};

ll get(string &s, ll key, ll MOD){
	ll ans = 0;
	for(int i = 0; i < (int) s.size(); i++){
		ans = (ans * key + s[i]) % MOD;
	}
	return ans;
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

	int n, k;
	read(n);
	read(k);
	string t;
	read_string(t);
	int m;
	read(m);

	map<ii, int> mm;

	int key1 = keys[rand() % 10];
	int modul1 = modules[rand() % 10];
	int key2 = keys[rand() % 10];
	int modul2 = modules[rand() % 10];

	for(int i = 0; i < m; i++){
		string t;
		read_string(t);
		mm[make_pair(get(t, key1, modul1), get(t, key2, modul2))] = i + 1;
	}

	t += t;
	set<int> s;
	hash_stirng hs1(key1, modul1, t);
	hash_stirng hs2(key2, modul2, t);
	vector<int> ans;
	map<ii, int>::iterator it;
	int size = n * k * 2;
	for(int i = 0; i < k; i++){
		s.clear();
		ans.clear();
		for(int j = n * k + 1 + i; j <= size; j += k){
			ii r = make_pair(hs1.get(j - k + 1, j), hs2.get(j - k + 1, j));
			it = mm.find(r);
			if(it == mm.end())
				break;
			int ind = it->second;
			if(s.find(ind) != s.end())
				break;
			s.insert(ind);
			ans.push_back(ind);
		}
		if((int) ans.size() == n){
			cout << "YES" << endl;
			for(int a : ans){
				cout << a << " ";
			}
			cout << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

}