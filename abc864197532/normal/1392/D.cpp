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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (count(all(s), 'L') == 0 || count(all(s), 'R') == 0) {
            cout << (n + 2) / 3 << endl;
            continue;
        }
        deque <char> dq(all(s));
        while (dq.front() != 'R' || dq.back() != 'L') dq.pb(dq.front()), dq.pop_front();
        int ans = 0;
        int a = 0, b = 0;
        bool is = false;
        fop (i,0,n) {
            if (!is) {
                if (dq[i] == 'R') a++;
                else {
                    is = true;
                    b++;
                }
            } else {
                if (dq[i] == 'R') {
                    is = false;
                    ans += (a) / 3 + (b) / 3;
                    a = 1, b = 0;
                } else {
                    b++;
                }
            }
        }
        ans += (a) / 3 + (b) / 3;
        cout << ans << endl;
    }
}