#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2500, logN = 17, K = 350;
const int MAXN = 100000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	string s;
    	cin >> s;
    	int a = 0, n = s.length();
    	for (char c : s) a |= (1 << c - 'a');
    	if (__builtin_popcount(a) == 1) {
    		cout << "-1\n";
		} else {
			bool is = true;
			fop (i,0,n) if (s[i] != s[n - i - 1]) is = false;
			if (is) {
				vector <int> id(26, -1);
				fop (i,0,n) {
					fop (j,0,26) if (~id[j] && s[i] - 'a' != j) {
						swap(s[id[j]], s[i]);
						goto end;
					}
					id[s[i] - 'a'] = i;
				}
				end:
				cout << s << endl;
			} else {
				cout << s << endl;
			}
		}
	}
}