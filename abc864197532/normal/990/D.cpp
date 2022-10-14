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
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 2 && a == 1 && b == 1) {
    	cout << "NO\n";
    	return 0;
	}
	if (n == 3 && a == 1 && b == 1) {
		cout << "NO\n";
		return 0;
	}
	if (b == 1) {
    	cout << "YES\n";
    	vector <vector <bool>> ma(n, vector <bool>(n, 0));
    	fop (i,0,n - a) {
			ma[i][i + 1] = true;
			ma[i + 1][i] = true;
		}
		fop (i,0,n) {
			fop (j,0,n) {
				cout << ma[i][j];
			}
			cout << endl;
		}
	} else if (a == 1) {
    	cout << "YES\n";
    	vector <vector <bool>> ma(n, vector <bool>(n, 1));
    	fop (i,0,n - b) {
			ma[i][i + 1] = false;
			ma[i + 1][i] = false;
		}
		fop (i,0,n) ma[i][i] = 0;
		fop (i,0,n) {
			fop (j,0,n) {
				cout << ma[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "NO\n";
	}
}