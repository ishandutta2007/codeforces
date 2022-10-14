#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 350;

int main () {
	int n;
	cin >> n;
	vector <int> cnt(101, 0), a(n), is(101, 0);
	fop (i,0,n) cin >> a[i], cnt[a[i]]++;
	vector <int> one, more;
	fop (i,1,101) {
		if (cnt[i] == 1) one.pb(i), is[i] = 1;
		else if (cnt[i] > 1) more.pb(i), is[i] = 2;
		else is[i] = 0;
	}
	if (one.size() & 1 && more.empty()) {
		cout << "NO\n";
	} else {
		if (one.size() & 1 ^ 1) {
			cout << "YES\n";
			string s;
			fop (i,0,n) {
				if (is[a[i]] == 1) {
					fop (j,0,one.size()) {
						if (one[j] == a[i]) {
							s.pb('A' + (j < one.size() / 2));
						}
					}
				} else {
					s.pb('A');
				}
			}
			cout << s << endl;
		} else {
			string s;
			bool iss = true;
			int p = 0;
			while (p < more.size() && cnt[more[p]] == 2) p++;
			if (p == more.size()) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				fop (i,0,n) {
					if (is[a[i]] == 1) {
						fop (j,0,one.size()) {
							if (one[j] == a[i]) {
								s.pb('A' + (j >= one.size() / 2));
							}
						}
					} else {
						if (a[i] == more[p]) {
							if (iss) s.pb('A');
							else s.pb('B');
							iss = false;
						} else {
							s.pb('A');
						}
					}
				}
				cout << s << endl;
			}
		}
	}
}