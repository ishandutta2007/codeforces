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

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	for(int i = 0; i < n; i++){
		if('z' - s[i] > s[i] - 'a'){
			int q = 'z' - s[i];
			q = min(q, m);
			m -= q;
			s[i] += q;
		}else{
			int q = s[i] - 'a';
			q = min(q, m);
			m -= q;
			s[i] -= q;
		}
	}

	cout << (m == 0 ? s : "-1") << endl;

}