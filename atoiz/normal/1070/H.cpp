#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s) freopen(string(s) + ".inp", "r", stdin), freopen(string(s) + ".out", "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 5e4 + 5;
int n;
map<string, string> rep;
map<string, int> cnt;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, n) {
		string s;
		cin >> s;
		int m = s.length();
		map<string, bool> appear;
		fw (l, 0, m) {
			string cur = "";
			fw (r, l, m) {
				cur += s[r];
				if (!appear.count(cur)) {
					cnt[cur]++;
					if (!rep.count(cur)) rep[cur] = s;
					appear[cur] = 1;
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (!cnt.count(s)) cout << "0 -\n";
		else cout << cnt[s] << " " << rep[s] << "\n";
	}
	return 0;
}