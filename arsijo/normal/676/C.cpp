#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 9;
const ld E = 1e-13;
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

int ar[2];
int m;
bool check(){
	return min(ar[0], ar[1]) <= m;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(40);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n >> m;
	string s;
	cin >> s;
	int ans = 0;
	for(int l = 0, r = 0; r < n; r++){
		ar[s[r] - 'a']++;
		while(!check()){
			ar[s[l++] - 'a']--;
		}
		ans = max(ans, r - l + 1);
	}

	cout << ans << endl;

}