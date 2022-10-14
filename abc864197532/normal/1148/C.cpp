#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17, K = 1000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    int pos[n], now[n];
    fop (i,0,n) {
        cin >> now[i];
        now[i]--;
        pos[now[i]] = i;
    }
    vector <pii> ans;
    /*
    2 4 0 5 3 1
    2 5 0 4 1 3
    */
    auto add = [&](int i, int j) {
        swap(now[i], now[j]);
        swap(pos[now[i]], pos[now[j]]);
        ans.eb(i, j);
    };
    fop (i,0,n / 2) {
        if (pos[i] == i) continue;
        if (pos[i] == n - 1) {
            add(pos[i], i);
        } else if (pos[i] >= n / 2) {
            int k = pos[i];
            add(pos[i], 0);
            add(pos[i], n - 1);
            add(pos[i], i);
            if (pos[i] != 0) add(0, k);
        } else {
            add(pos[i], n - 1);
            add(pos[i], i);
        }
    }
    fop (i,n / 2,n) {
        if (pos[i] == i) continue;
        int k = pos[i];
        add(pos[i], 0);
        add(pos[i], i);
        add(0, k);
    }
    cout << ans.size() << endl;
    for (auto A : ans) cout << A.X + 1 << ' ' << A.Y + 1 << endl;
}