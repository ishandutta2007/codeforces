 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

vector<int> f;

void incr(int x, int d) {
    for (; x < (int)f.size(); x |= (x + 1)) f[x] += d;
}

int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) ans += f[x];
    return ans;
}

ll kek(vector<int> &a) {
    int n = a.size();
    f.assign(n, 0);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += get(a[i]);
        incr(a[i], 1);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(2);
    for (auto &c : a) {
        cin >> c;
        c %= 2;
        cnt[c]++;
    }
    if (cnt[0] > (n + 1) / 2 || cnt[1] > (n + 1) / 2) {
        cout << -1 << "\n";
        return;
    }
    ll ans = INFLL;
    if (n % 2 == 0) {
        vector<int> b;
        int id0 = 0, id1 = 1;
        for (auto &c : a) {
            if (c == 0) {
                b.pb(id0);
                id0 += 2;
            } else {
                b.pb(id1);
                id1 += 2;
            }
        }
        ans = min(ans, kek(b));
        b.clear();
        id0 = 1, id1 = 0;
        for (auto &c : a) {
            if (c == 0) {
                b.pb(id0);
                id0 += 2;
            } else {
                b.pb(id1);
                id1 += 2;
            }
        }
        ans = min(ans, kek(b));
    } else {
        vector<int> b;
        int id0 = 0, id1 = 1;
        if (cnt[1] > cnt[0]) swap(id0, id1);
        for (auto &c : a) {
            if (c == 0) {
                b.pb(id0);
                id0 += 2;
            } else {
                b.pb(id1);
                id1 += 2;
            }
        }
        ans = min(ans, kek(b));
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}