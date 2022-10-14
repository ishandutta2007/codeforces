#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100005, logN = 18, K = 600, C = 100, M = 1e9;

void solve() {
    int n, t, tmp;
    cin >> n >> t;
    vector <int> a(n);
    vector <lli> pre = {0};
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    fop (i,0,n) pre.pb(pre.back() + a[i]);
    set <lli> s;
    queue <pii> q;
    q.push(mp(0, n));
    while (q.size()) {
        pii A = q.front(); q.pop();
        s.insert(pre[A.Y] - pre[A.X]);
        if (a[A.X] == a[A.Y - 1]) continue;
        int mid = a[A.X] + a[A.Y - 1] >> 1;
        int m = upper_bound(all(a), mid) - a.begin();
        q.push({A.X, m}); q.push({m, A.Y});
    }
    while (t--) {
        int in;
        cin >> in;
        cout << (s.count(in) ? "YES\n" : "NO\n");
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}