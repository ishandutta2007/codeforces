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
const int mod = 1e9 + 7, x = 864197532, N = 2000001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli ans = 0;
    int q, x;
    bool is = true;
    cin >> q;
    vector <lli> stk1, stk2;
    stk1.pb(0);
    while (q--) {
    	string s;
    	cin >> s;
    	if (s == "add") {
    		stk1.back()++;
		} else if (s == "for") {
			cin >> x;
			stk1.pb(0);
			stk2.pb(x);
			is = true;
		} else {
			stk1[stk1.size() - 2] += stk1[stk1.size() - 1] * stk2.back();
			stk1.pop_back();
			stk2.pop_back();
		}
		if (stk1.back() >= (1ll << 32)) {
			cout << "OVERFLOW!!!\n";
			return 0;
		}
	}
	cout << stk1.back() << endl;
}