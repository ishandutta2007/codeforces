#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define y1 ybutnot1
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

int n, a, b, n1, n2;

int next1(){
	if(n1 > n)
		return 0;
	n1 += 2;
	return n1 - 2;
}

int next2(){
	if(n2 > n)
		return 0;
	n2 += 2;
	return n2 - 2;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> a >> b;
	n1 = 1;
	n2 = 2;

	int ar[a][b];
	ms(ar);

	for(int i = 0; i < a; i++){
		for(int j = (i % 2 == 0 ? 0 : 1); j < b; j += 2)
			ar[i][j] = next1();
	}

	for(int i = 0; i < a; i++){
		for(int j = (i % 2 == 0 ? 1 : 0); j < b; j += 2)
			ar[i][j] = next2();
	}

	if(next1() || next2()){
		cout << -1;
		return 0;
	}

	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

}