#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> T sqr(T a) {
	return a * a;
}
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
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define db 1
#else
#define db 0
#endif
#define dbg if(db) cout

int main() {

	cout.precision(11);
	cout << fixed;
	sync;

#ifdef LOCAL
	input;
#endif

	string a, b;
	cin >> a >> b;

	string s = b + "!" + a;
	int pref[s.size()];
	int n = (int) b.size();
	pref[0] = 0;
	for(int i = 1; i < (int) s.size(); i++){
		int j = pref[i - 1];
		while(j > 0 && s[i] != s[j])
			j = pref[j - 1];
		if(s[i] == s[j])
			j++;
		pref[i] = j;
	}

	int ans = 0;

	for(int i = 2 * n; i < (int) s.size(); i++){
		if(pref[i] >= n){
			i += n - 1;
			ans++;
		}
	}

	cout << ans;

}