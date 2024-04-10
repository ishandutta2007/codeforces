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
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

bool ask(int x, int y, int a, int b) {
	cout << "? " << y + 1 << ' ' << x + 1 << ' ' << b + 1 << ' ' << a + 1 << endl;
	string s;
	cin >> s;
	return s == "YES";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0, y = 0;
    string ans, ans2;
    while (x + y < n - 1) {
    	if (ask(x + 1, y, n - 1, n - 1)) {
    		ans.pb('R');
    		x++;
		} else {
			ans.pb('D');
			y++;
		}
	}
	int nx = n - 1, ny = n - 1;
	while (x != nx || y != ny) {
		if (ask(0, 0, nx, ny - 1)) {
			ny--;
			ans2.pb('D');
		} else {
			nx--;
			ans2.pb('R');
		}
	}
	reverse(all(ans2));
	cout << "! " << ans << ans2 << endl;
}