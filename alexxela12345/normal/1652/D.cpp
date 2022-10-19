#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

//#define int ll
#ifndef LOCAL
//#define endl '\n'
#endif

#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}

int powmod(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = mul(ans, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}

int rev(int a) {
    return powmod(a, MOD - 2);
}

vector<vector<int>> g;

vector<int> p;
vector<int> m;

int cur_time = 0;
vector<int> tin, tout;

const int LOG = 19;
vector<vector<int>> up;
vector<int> d;

void dfs(int v, int pa=-1) {
    tin[v] = cur_time++;
    p[v] = pa;
    if (pa == -1) {
        pa = v;
    }
    d[v] = d[pa] + 1;
    up[v].resize(LOG);
    up[v][0] = pa;
    for (int i = 1; i < LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : g[v]) {
        if (u != pa) {
            dfs(u, v);
        }
    }
    tout[v] = cur_time;
}

int go(int a, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) { 
            a = up[a][i];
        }
    }
    return a;
}

int lca(int a, int b) {
    if (d[b] > d[a])
        swap(a, b);
    a = go(a, d[a] - d[b]);
    if (a == b)
        return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

bool cmptin(int a, int b) {
    return tin[a] < tin[b];
}

void dfs1(int v, int pa, int mm=1) {
    mm = mul(mm, m[v]);
    m[v] = mm;
    for (int u : g[v]) {
        if (u != pa) {
            dfs1(u, v, mm);
        }
    }
}

vector<pair<int, int>> getd(int x) {
    int cur = 2;
    map<int, int> cnt;
    while (cur * cur <= x) {
        while (x % cur == 0) {
            cnt[cur]++;
            x /= cur;
        }
        cur++;
    }
    if (x != 1) {
        cnt[x]++;
    }
    vector<pair<int, int>> ans;
    for (auto  pp : cnt)
        ans.push_back(pp);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    tin.assign(n, 0);
    tout.assign(n, 0);
    d.assign(n, 0);
    up.clear();
    up.resize(n);
    cur_time = 0;
    vector<array<int, 4>> arr(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
        arr[i][0]--;
        arr[i][1]--;
        int gg = gcd(arr[i][2], arr[i][3]);
        arr[i][2] /= gg;
        arr[i][3] /= gg;
        g[arr[i][0]].push_back(arr[i][1]);
        g[arr[i][1]].push_back(arr[i][0]);
    }
    m.assign(n, 1);
    p.assign(n, -1);
    dfs(0, -1);
    unordered_map<int, vector<pair<int, int>>> ma;
    for (int i = 0; i < n - 1; i++) {
        if (p[arr[i][0]] == arr[i][1]) {
            swap(arr[i][0], arr[i][1]); 
            swap(arr[i][2], arr[i][3]);
        }
        m[0] = mul(m[0], arr[i][2]);
        m[arr[i][1]] = mul(m[arr[i][1]], mul(rev(arr[i][2]), arr[i][3]));
        for (auto pp : getd(arr[i][2])) {
            ma[pp.first].push_back({0, pp.second});
            ma[pp.first].push_back({arr[i][1], -pp.second});
        }
        for (auto pp : getd(arr[i][3])) {
            ma[pp.first].push_back({arr[i][1], pp.second});
        }
    }
    dfs1(0, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, m[i]);
    }

    for (auto [pr, arr] : ma) {
        vector<int> vs = {0};
        for (auto pp : arr) {
            vs.push_back(pp.first);
        }
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        sort(vs.begin(), vs.end(), cmptin);
        for (int i = (int) vs.size() - 2; i >= 0; i--) {
            vs.push_back(lca(vs[i], vs[i + 1]));
        }
        sort(vs.begin(), vs.end(), cmptin);
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        unordered_map<int, int> mm;
        for (auto pp : arr) {
            mm[pp.first] += pp.second;
        }
        vector<int> st;
        for (int v : vs) {
            if (st.empty()) {
                st.push_back(v);
            } else {
                while (!st.empty() && tout[st.back()] <= tin[v]) {
                    st.pop_back();
                }
                mm[v] += mm[st.back()];
                st.push_back(v);
            }
        }
        int mn = 1e9;
        for (auto el : mm) {
            mn = min(mn, el.second);
        }
        int rp = rev(pr);
        for (int i = 0; i < mn; i++) {
            ans = mul(ans, rp); 
        }
    }


    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}