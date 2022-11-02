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

const int maxn = 1e6 + 9;
vector<int> g[maxn];
vector<int> rg[maxn];
int n, m;
vector<vector<int> > a;
bool used[maxn];
int ts[maxn];
int pt;
int C[maxn];
bool kek[maxn];
bool used1[maxn];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y];
}

int c(int x, int y) {
    return x * m + y;
}

void topsort(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to])
            topsort(to);
    }
    ts[pt] = v;
    pt--;
}

void find_c(int v, int j) {
    used[v] = 1;
    C[v] = j;
    for (int to : rg[v]) {
//        cerr << "     " << v << " " << to << "\n";
        if (!used[to])
            find_c(to, j);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m, 0);
        string s;
        cin >> s;
        for (int e = 0; e < m; e++)
            a[i][e] = (s[e] == '#');
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            if (!a[i][e])
                continue;
            kek[c(i, e)] = 1;
            cnt++;
            if (ok(i - 1, e))
                g[c(i, e)].pb(c(i - 1, e));
            for (int j = i; j < n; j++) {
                if (a[j][e] && j != i) {
                    g[c(i, e)].pb(c(j, e));
                    break;
                }
                if (ok(j, e - 1))
                    g[c(i, e)].pb(c(j, e - 1));
                if (ok(j, e + 1))
                    g[c(i, e)].pb(c(j, e + 1));
            }
        }
    }
//    cout << cnt << "\n";
    pt = cnt - 1;
    for (int i = 0; i < n * m; i++) {
        if (kek[i] && !used[i]) {
            topsort(i);
        }
    }
    for (int i = 0; i < n * m; i++) {
        used[i] = 0;
        for (int to : g[i]) {
//            cerr << " " << i << " " << to << "\n";
            rg[to].pb(i);
        }
    }
    pt = 0;
    for (int i = 0; i < cnt; i++) {
        int v = ts[i];
//        cerr << "    " << v << "\n";
        if (!used[v]) {
//            cerr << "!\n";
            find_c(v, pt);
            pt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        if (!kek[i])
            continue;
//        cout << i << " " << C[i] << "\n";
        for (int to : rg[i]) {
            if (C[to] != C[i])
                used1[C[i]] = 1;
        }
//        cout << i << " " << used1[C[i]] << "\n";
    }
//    for (int i = 0; i < cnt; i++)
//        cout << used1[C[i]];
    for (int i = 0; i < pt; i++) {
        if (!used1[i])
            ans++;
    }
    cout << ans;
}