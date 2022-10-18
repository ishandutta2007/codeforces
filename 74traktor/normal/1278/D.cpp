#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
vector < int > g[maxn];
pair < int, int > a[maxn];
int cnt[maxn], start[maxn], stop[maxn], revl[maxn], revr[maxn], sum[maxn], imin[4 * maxn], imax[4 * maxn], ok[4* maxn];
int inf = 1e9, mini;
int used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 0) dfs(u);
    }
}

inline void add(int l, int x) {
    while (l < maxn) {
        sum[l] += x;
        l = (l|(l + 1));
    }
}

inline int ans(int l) {
    int t = 0;
    while (l >= 0) {
        t += sum[l];
        l = (l&(l + 1)) - 1;
    }
    return t;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r, bal = 0, sz = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; ++i) {
        start[a[i].first] = a[i].second, stop[a[i].second] = a[i].first;
        revl[a[i].first] = i, revr[a[i].second] = i;
    }
    if (n == 1) {
        cout << "YES" << '\n';
        return 0;
    }
    set < pair < int, int > > numb;
    for (int i = 1; i <= 2 * n; ++i) {
        if (start[i] != 0) {
            mini = 1e9;
            bal++;
            for (auto key : numb) {
                if (key.first > i) break;
                g[key.second].push_back(revl[i]);
                g[revl[i]].push_back(key.second);
                sz++;
            }
            numb.insert({start[i], revl[i]});
            cnt[revl[i]] += (bal - 1);
            cnt[revl[i]] -= 2 * (bal - 1 - ans(start[i]));
            add(start[i] + 1, 1);
        }
        if (stop[i] != 0) {
            add(i + 1, -1);
            bal--;
            numb.erase({i, revr[i]});
        }
        if (sz > 4 * n) {
            cout << "NO";
            return 0;
        }
    }
    numb = {};
    for (int i = 2 * n; i >= 1; --i) {
        if (stop[i] != 0) {
            bal++;
            for (auto key : numb) {
                if (key.first * (-1) < stop[i]) break;
                g[key.second].push_back(revr[i]), g[revr[i]].push_back(key.second);
                sz++;
            }
            numb.insert({-stop[i], revr[i]});
            cnt[revr[i]] += (bal - 1);
        }
        if (start[i] != 0) bal--, numb.erase({-i, revl[i]});
        if (sz > 4 * n) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            cout << "NO";
            return 0;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        //cout << cnt[i] << '\n';
        if (cnt[i] == 0) {
            cout << "NO" << '\n';
            return 0;
        }
        sum += cnt[i];
        if (sum > 2 * n) {
            cout << "NO";
            return 0;
        }
    }
    if (sum != 2 * (n - 1)) {
        cout << "NO" << '\n';
    }
    else cout << "YES" << '\n';
    return 0;
}