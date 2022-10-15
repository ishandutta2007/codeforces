#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
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

const int MAX = 1e5;
ll ar[MAX], t[MAX];

void upd(int pos, ll val){
	for(int i = pos; i < MAX; i |= (i + 1))
		t[i] = max(t[i], val);
}

ll get(int pos){
	ll ans = 0;
	for(int i = pos; i >= 0; i &= (i + 1), i--)
		ans = max(ans, t[i]);
	return ans;
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

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> ar[i];
		upd(i, ar[i]);
	}

	int m;
	cin >> m;

	while(m--){
		int w, h;
		cin >> w >> h;
		ll ans = get(w - 1);
		cout << ans << endl;
		upd(0, ans + h);
	}

}