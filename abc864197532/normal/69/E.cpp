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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n), v;
    fop (i,0,n) cin >> a[i], v.pb(a[i]);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    fop (i,0,n) a[i] = lower_bound(all(v), a[i]) - v.begin();
    vector <int> co(v.size(), 0);
    set <int, greater<int>> pos;
    for (int i = 0, j = k; j <= n; ++j) {
        while (i < j) {
            co[a[i]]++;
            if (co[a[i]] == 1) pos.insert(a[i]);
            if (co[a[i]] == 2) pos.erase(a[i]);
            i++;
        }
        if (pos.size()) cout << v[*pos.begin()] << endl;
        else cout << "Nothing\n";
        co[a[j - k]]--;
        if (co[a[j - k]] == 1) pos.insert(a[j - k]);
        if (co[a[j - k]] == 0) pos.erase(a[j - k]);
    }
}