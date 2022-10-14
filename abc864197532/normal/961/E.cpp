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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 18, logN = 17, K = 90002;

lli bit[N] = {};

void add(int p, int v) {
    for (int i = p; i < N; i += i & (-i)) bit[i] += v;
}

lli query(int p) {
    if (p <= 0) return 0;
    lli ans = 0;
    for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
     x <= a_y && y <= a_x
     x <= min(a_y, y - 1) && a_x >= y
     */
    int n;
    cin >> n;
    vector <int> a(n + 1);
    fop (i,1,n + 1) cin >> a[i];
    lli ans = 0;
    priority_queue <pii, vector <pii>, greater<pii>> pq;
    fop (i,1,n + 1) {
        while (pq.size() && pq.top().X < i) {
            pii A = pq.top(); pq.pop();
            add(A.Y, -1);
        }
        ans += query(min(a[i], i - 1));
        add(i, 1);
        pq.push({a[i], i});
    }
    cout << ans << endl;
}