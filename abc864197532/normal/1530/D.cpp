#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), ans(n, -1);
    vector <bool> vis(n + 1, false);
    int tans = 0, p = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!vis[a[i]]) ans[i] = a[i], vis[a[i]] = true, tans++;
        else p = i;
    }
    vector <int> all;
    for (int i = 1; i <= n; ++i) if (!vis[i]) all.pb(i);
    if (all.size() == 1 && p + 1 == all[0]) {
        ans.assign(n, -1);
        vis.assign(n + 1, false);
        for (int i = n - 1; ~i; --i) {
            if (!vis[a[i]]) ans[i] = a[i], vis[a[i]] = true;
        }
    }
    while (true) {
        vector <int> nxt = ans;
        int now = 0;
        bool is = true;
        shuffle(all(all), rng);
        for (int i = 0; i < n; ++i) if (nxt[i] == -1) {
            nxt[i] = all[now++];
            is &= nxt[i] != i + 1;
        }
        if (is) {
            ans = nxt;
            break;
        }
    }
    cout << tans << endl;
    printv(all(ans));
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}