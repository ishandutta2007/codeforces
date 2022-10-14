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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    bool is[n][n];
    auto f = [&](char c) {
    	if (c >= '0' && c <= '9') return c - '0';
    	return c - 'A' + 10;
	};
    fop (i,0,n) {
    	cin >> s;
    	fop (j,0,n / 4) {
    		int k = f(s[j]);
    		fop (ii,0,4) {
    			if (k & (1 << ii)) {
    				is[i][j * 4 + 3 - ii] = true;
				} else {
					is[i][j * 4 + 3 - ii] = false;
				}
			}
		}
	}
	int g = 0;
	fop (i,0,n) {
		int now = 1;
		fop (j,1,n) {
			if (is[i][j] == is[i][j - 1]) {
				now++;
			} else {
				g = __gcd(g, now);
				now = 1;
			}
		}
		g = __gcd(g, now);
	}
	fop (i,0,n) {
		int now = 1;
		fop (j,1,n) {
			if (is[j][i] == is[j - 1][i]) {
				now++;
			} else {
				g = __gcd(g, now);
				now = 1;
			}
		}
		g = __gcd(g, now);
	}
	cout << g << endl;
}