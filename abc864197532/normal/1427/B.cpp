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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int a = count(all(s), 'W');
        if (a == 0) {
            cout << max(2 * k - 1, 0) << endl;
            continue;
        }
        vector <int> add;
        int cnt = 1;
        deque <int> dq(all(s));
        while (dq.front() == 'L') dq.pop_front();
        while (dq.back() == 'L') dq.pop_back();
        dq.pb('#');
        fop (i,1,dq.size()) {
            if (dq[i] != dq[i - 1]) {
                if (dq[i] == 'W') add.pb(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        sort(rall(add));
        int c = add.size() + 1;
        a += k;
        while (add.size() && k >= add.back()) {
            k -= add.back();
            c--;
            add.pop_back();
        }
        a = min(a, n);
        cout << 2 * a - c << endl;
    }
}