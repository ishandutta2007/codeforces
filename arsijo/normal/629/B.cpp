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
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
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

int sum(int n){
	return n * (n + 1) / 2;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(std::time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int M = 367;
	int a[M], b[M];
	ms(a);
	ms(b);

	int n;
	cin >> n;
	while(n--){
		char c;
		cin >> c;
		int l, r;
		cin >> l >> r;
		if(c == 'M'){
			for(int i = l; i <= r; i++)
				a[i]++;
		}else{
			for(int i = l; i <= r; i++)
				b[i]++;
		}
	}

	int ans = 0;
	for(int i = 0; i < M; i++)
		ans = max(ans, min(a[i], b[i]));
	cout << ans * 2;

}