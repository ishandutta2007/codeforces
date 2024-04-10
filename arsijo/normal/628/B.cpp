#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
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

int get(int n){
	int q = 2;
	while(q * 2 <= n)
		q *= 2;
	return q;
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

	string s;
	cin >> s;

	ll ans = 0;
	for(int i = 0; i < (int) s.size(); i++)
		if(s[i] == '4' || s[i] == '0' || s[i] == '8')
			ans++;

	for(int i = 1; i < (int) s.size(); i++){
		int a = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if(a % 4 == 0){
			ans += i;
		}
	}

	cout << ans;

}