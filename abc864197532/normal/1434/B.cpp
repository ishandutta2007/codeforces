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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pair <char, int>> in(2 * n);
    int pre = 0;
    fop (i,0,n * 2) {
        cin >> in[i].X;
        if (in[i].X == '+') pre++;
        else {
            cin >> in[i].Y;
            pre--;
            if (pre < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    vector <int> ans;
    set <int> s;
    FOP (i,2 * n,0) {
        if (in[i].X == '+') {
            ans.pb(int(*s.begin()));
            s.erase(s.begin());
        } else {
            s.insert(in[i].Y);
        }
    }
    reverse(all(ans));
    assert(s.empty());
    bool is = true;
    int now = 0;
    fop (i,0,n * 2) {
        if (in[i].X == '+') {
            s.insert(ans[now++]);
        } else {
            assert(s.size());
            is &= int(*s.begin()) == in[i].Y;
            s.erase(s.begin());
        }
    }
    if (is) {
        cout << "YES\n";
        printv(ans);
    } else {
        cout << "NO\n";
    }
}