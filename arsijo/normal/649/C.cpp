#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-8;
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

const int MAX = 2e5 + 1;
int ar[MAX], n;

bool check(int n, int x, int y){
	for(int i = 0; i < n; i++){
		int q = ar[i];
		int t = min(x, ar[i] / 2);
		q -= t * 2;
		x -= t;
		t = min(q, y);
		y -= t;
		q -= t;
		t = min(q, x);
		x -= t;
		q -= t;
		if(q)
			return false;
	}
	return true;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);

	if(!check(1, x, y)){
		cout << 0;
		return 0;
	}

	int l = 1, r = n;
	while(l < r){
		int w = (l + r + 1) >> 1;
		if(check(w, x, y))
			l = w;
		else
			r = w - 1;
	}

	cout << l;

}