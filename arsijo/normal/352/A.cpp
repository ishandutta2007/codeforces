#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	//write();
	input;
#else

#endif

	int n;
	cin >> n;

	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		m ? b++ : a++;
	}

	int w = 0;
	int e = 0;
	for(int i = 0; i < b; i++){
		e = (e * 10 + 5) % 9;
		if(e == 0)
			w = i + 1;
	}

	if(!a){
		cout << -1;
		return 0;
	}

	for(int i = 0; i < w; i++)
		cout << 5;

	cout << 0;
	if(w)
		for(int i = 1; i < a; i++)
			cout << 0;

}