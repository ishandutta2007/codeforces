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
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	bool is = true;
	fop (i,0,k) {
	    int t = 0;
	    for (int j = i; j < n; j += k) {
            if (s[j] != '?') t |= 1 << s[j] - '0';
	    }
	    if (t == 3) is = false;
	    if (t == 1 || t == 2) {
            for (int j = i; j < n; j += k) {
                s[j] = '0' + t - 1;
            }
	    }
	}
	if (!is) {
		cout << "NO\n";
		return;
	}
	int a[2] = {0, 0};
	fop (i,0,k) if (s[i] != '?') a[s[i] - '0']++;
	k >>= 1;
	if (a[0] > k || a[1] > k) is = false;
	if (is) cout << "YES\n";
	else cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}