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
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define input _read("input.txt")
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int ar[4] = {2, 3, 5, 7};

ll n, ans = n;

void dfs(int pos, ll t, int used){
	if(pos == 4){
		if(used % 2 == 1){
			ans -= n / t;
		}else{
			ans += n / t;
		}
		return;
	}
	dfs(pos + 1, t * ar[pos], used + 1);
	dfs(pos + 1, t, used);
}

int main() {

	sync;
	cout.precision(10);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	dfs(0, 1, 0);
	cout << ans;


}