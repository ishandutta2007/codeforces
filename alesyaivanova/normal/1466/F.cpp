#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 5e5 + 9;
int p[maxn];
int sz[maxn];
bool kek[maxn];
int n, m;
int mod = 1e9 + 7;

int binpow(int x, int pw) {
    if (pw == 0)
        return 1;
    if (pw == 1)
        return x % mod;
    int y = binpow(x, pw / 2);
    y = (y * y) % mod;
    if (pw % 2)
        y = (y * x) % mod;
    return y;
}

int find_p(int i) {
    if (p[i] != i)
        p[i] = find_p(p[i]);
    return p[i];
}

void merg(int i, int e) {
    i = find_p(i);
    e = find_p(e);
    if (i == e)
        return;
    if (sz[i] < sz[e])
        swap(i, e);
    sz[i] += sz[e];
    p[e] = i;
    kek[i] |= kek[e];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        p[i] = i;
        sz[i]= 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            x--;
            int v = find_p(x);
            if (!kek[v]) {
                kek[v] = 1;
                ans.pb(i);
            }
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int px = find_p(x);
            int py = find_p(y);
            if (px != py && (!kek[px] || !kek[py])) {
                merg(x, y);
                ans.pb(i);
            }
        }
    }
    cout << binpow(2, ans.size()) << " ";
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
}