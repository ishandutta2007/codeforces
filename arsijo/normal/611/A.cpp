#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 2e4 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int ar[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	string s;
	cin >> s;
	cin >> s;

	bool bol = (s == "week");
	int ans = 0;
	int d = 1, m = 1, w = 5;
	for(int i = 0; i < 366; i++){
		if(d > ar[m - 1]){
			d = 1;
			m++;
		}
		if(w == 8){
			w = 1;
		}
		if(bol && w == n)
			ans++;
		if(!bol && d == n)
			ans++;
		d++;
		w++;
	}

	cout << ans;

}