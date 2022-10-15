#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
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
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
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

bool check(int a, int b, int c){
	return a < b && b < c;
}

bool check(int a, int b, int c, int d){
	return check(a, c, b) || check(a, d, b) || check(c, a, d) || check(c, b, d);
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	string s;
	cin >> s;

	for(int i = 1; i < (int) s.size(); i++){
		if(s[i] == s[i - 1]){
			char c1 = s[i - 1];
			char c2 = (i == (int) s.size() - 1 ? '?' : s[i + 1]);
			for(int j = 0; j < 3; j++){
				if('a' + j != c1 && 'a' + j != c2){
					s[i] = 'a' + j;
					break;
				}
			}
		}
	}

	cout << s << endl;

}