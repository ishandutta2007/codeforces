#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> inline T sqr(T a) {
	return a * a;
}
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
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
const ld E = 1e-15;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int solve(string s){
	if(s == "")
		return 0;
	int x = 0, y = 0;
	int ans = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == 'U'){
			x--;
		}else if(s[i] == 'D'){
			x++;
		}else if(s[i] == 'R'){
			y++;
		}else if(s[i] == 'L'){
			y--;
		}
		if(x == 0 && y == 0)
			ans++;
	}
	string t = "";
	for(int i = 1; i < (int) s.size(); i++)
		t += s[i];
	return ans + solve(t);
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	string s;
	cin >> s;
	cout << solve(s);

}