#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
bool _minus = false;
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
char wr[12];
int k;
inline void write(int x) {
	k = 0;
	if (!x)
		++k, wr[k] = '0';
	while (x) {
		++k;
		wr[k] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = k; i >= 1; --i)
		putchar(wr[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

set<string> can_be[10005];
set<string> ss;

inline bool check(int a, string t){
	if(can_be[a].find(t) == can_be[a].end()){
		return !can_be[a].empty();
	}else{
		return (int) can_be[a].size() > 1;
	}
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	string s;
	cin >> s;

	int n = (int) s.size();
	can_be[n].insert("A");
	can_be[n].insert("B");
	for(int i = n - 2; i >= 5; i--){
		if(check(i + 2, s.substr(i, 2)))
			can_be[i].insert(s.substr(i, 2));
		if(i != n - 2 && check(i + 3, s.substr(i, 3)))
			can_be[i].insert(s.substr(i, 3));
	}

	for(int i = 5; i < (int) s.size(); i++){
		string t = "";
		for(int j = 0; j <= 2 && i + j < (int) s.size(); j++){
			t += s[i + j];
			if(j && !can_be[i + j + 1].empty()){
				ss.insert(t);
			}
		}
	}
	cout << ss.size() << endl;
	for(set<string>::iterator it = ss.begin(); it != ss.end(); it++){
		cout << *it << endl;
	}

}