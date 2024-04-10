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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
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

int solve(string s, char c1, char c2){
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] != c1 && s[i] != c2)
			return 0;
	}
	return (int) s.size();
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ans = 0;

	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];

	for(char c1 = 'a'; c1 <= 'z'; c1++){
		for(char c2 = 'a'; c2 <= 'z'; c2++){
			int res = 0;
			for(int i = 0; i < n; i++)
				res += solve(s[i], c1, c2);
			ans = max(ans, res);
		}
	}

	cout << ans;

}