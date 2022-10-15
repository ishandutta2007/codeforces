#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("INPUT.TXT", "r", stdin)
#define output freopen("OUTPUT.TXT", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	int ar[n][m * 2];
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m * 2; j++){
			cin >> ar[i][j];
			if(ar[i][j]){
				ans++;
				if(j % 2 && ar[i][j - 1])
					ans--;
			}
		}
	}

	cout << ans;

}