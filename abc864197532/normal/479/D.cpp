#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 1000007, x = 864197532, N = 200000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    lli d, x, y;
    cin >> n >> d >> x >> y;
    lli input[n];
    set <lli> s;
    fop (i,0,n) cin >> input[i], s.insert(input[i]);
    int is = 0;
    fop (i,0,n) {
        if (s.count(input[i] + x)) is |= 1;
        if (s.count(input[i] + y)) is |= 2;
    }
    if (is == 3) {
        cout << 0 << '\n';
    } else if (is > 0) {
        cout << 1 << '\n';
        if (is == 2) {
        	cout << x << '\n';
        } else {
        	cout << y << '\n';
        }
    } else {
        fop (i,0,n) {
            if (s.count(input[i] + y - x) and input[i] - x >= 0) {
                cout << 1 << '\n' << input[i] - x << '\n';
                return 0;
            }
            if (s.count(input[i] + y - x) and input[i] + y <= d) {
            	cout << 1 << '\n' << input[i] + y << '\n';
            	return 0;
			}
            if (s.count(input[i] + x + y) and input[i] + x <= d) {
                cout << 1 << '\n' << input[i] + x << '\n';
                return 0;
            }
        }
        cout << "2\n" << x << ' ' << y << '\n';
    }
}