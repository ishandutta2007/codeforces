#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 100087, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve() {
	int n, c = 0, m;
	cin >> n;
	map <string, int> name;
	vector <string> name_id;
	string s, t;
	fop (i,0,n) {
		cin >> s;
		name[s] = c++;
		name_id.pb(s);
	}
	cin >> m;
	string input[m];
	getline(cin, s);
	set <int> in[m];
	vector <int> question(m, -1);
	fop (i,0,m) {
		getline(cin, s);
		input[i] = s;
		if (s[0] != '?') {
			string tmp;
			for (int i = 0; s[i] != ':'; ++i) tmp += s[i];
			question[i] = name[tmp];
		}
		auto ask = [&](char c) {
			return c == '.' || c == ',' || c == '!' || c == '?' || c == ' ' || c == ':';
		};
		for (auto A : name) {
			tie(t, c) = A;
			for (int ii = 0; ii + t.length() <= s.length(); ++ii) {
				int cnt = 0;
				for (int j = ii; j < ii + t.length(); ++j) cnt += (s[j] == t[j - ii]);
				if (cnt == t.length()) {
					if (ii + t.length() == s.length() || ask(s[ii + t.length()])) {
						if (ii == 0 || ask(s[ii - 1])) {	
							in[i].insert(c);
							break;
						}
					}
				}
			}
		}
	}
	vector <vector <bool>> dp(m, vector <bool>(n, false));
	fop (i,0,n) {
		if (question[0] == -1) {
			if (!in[0].count(i)) dp[0][i] = true;
		} else {
			if (question[0] == i) dp[0][i] = true;
		}
	}
	fop (i,1,m) {
		if (question[i] == -1) {
			fop (j,0,n) {
				if (!in[i].count(j)) {
					fop (k,0,n) if (k != j) {
						if (dp[i - 1][k]) dp[i][j] = true;
					}
				}
			}
		} else {
			fop (k,0,n) if (k != question[i]) {
				if (dp[i - 1][k]) dp[i][question[i]] = true;
			}
		}
	}
	int p = -1;
	fop (i,0,n) if (dp[m - 1][i]) p = i;
	if (p == -1) {
		cout << "Impossible\n";
	} else {
		int now = m - 1;
		question[now] = p;
		while (now > 0) {
			fop (i,0,n) if (i != p) {
				if (dp[now - 1][i]) {
					question[now - 1] = i;
					p = i;
					now--;
					break;
				}
			}
		}
		fop (i,0,m) {
			if (input[i][0] == '?') {
				string s = name_id[question[i]];
				cout << s << input[i].substr(1) << endl;
			} else {
				cout << input[i] << endl;
			}
		}
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}