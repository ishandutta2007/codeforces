#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
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

	string s;
	cin >> s;
	int n = (int) s.size();
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == '0'){
			a++;
		}else if(s[i] == '1'){
			b++;
		}else{
			c++;
		}
	}

	if(a + c > b){
		cout << "00" << endl;
	}

	if(s[s.size() - 1] != '0' && a <= n / 2 && b + (s[s.size() - 1] == '?' ? 1 : 0) <= (n + 1) / 2){
		cout << "01" << endl;
	}

	if(s[s.size() - 1] != '1' && a + (s[s.size() - 1] == '?' ? 1 : 0) <= n / 2 && b <= (n + 1) / 2){
		cout << "10" << endl;
	}

	if(b + c - 2 >= a){
		cout << "11" << endl;
	}

}