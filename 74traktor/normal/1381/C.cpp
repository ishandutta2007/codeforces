#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], ans[maxn];
map < int, int > cnt;
vector < int > g[maxn];
set < pair < int, int > > link;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        set < int > good;
        for (int i = 1; i <= n + 1; ++i) g[i] = {};
        for (int i = 1; i <= n + 1; ++i) good.insert(i);
        for (int i = 1; i <= n; ++i) good.erase(a[i]);
        int oks = (*good.begin());
        int Cnt = y - x;
        for (int i = 1; i <= n; ++i) ans[i] = oks;
        set < pair < int, int > > Q;
        cnt.clear();
        for (int i = 1; i <= n; ++i) cnt[a[i]]++, g[a[i]].push_back(i);
        for (auto key : cnt) Q.insert({key.second, key.first});
        while (x--) {
            y--;
            auto p = (*Q.rbegin());
            Q.erase(p);
            if (p.first > 1) Q.insert({p.first - 1, p.second});
            int pos = g[p.second].back();
            ans[pos] = a[pos];
            g[p.second].pop_back();
        }
        int sum = 0;
        for (auto key : Q) sum += key.first;
        if (sum > 0) {
            auto p = (*Q.rbegin());
            if (p.first <= sum / 2) {
                vector < pair < int, int > > top;
                for (auto key : Q) {
                    for (int j = 1; j <= key.first; ++j) {
                        top.push_back({key.second, g[key.second].back()});
                        g[key.second].pop_back();
                    }
                }
                for (int j = 0; j < (int)top.size(); ++j) {
                    int nxt = (j + p.first) % (int)top.size();
                    if (y > 0) {
                        y--, ans[top[j].second] = top[nxt].first;
                    }
                }
            }
            else {
                for (auto elem : Q) {
                    if (elem != p) {
                        for (int j = 1; j <= elem.first; ++j) {
                            int pos1 = g[elem.second].back(), pos2 = g[p.second].back();
                            g[elem.second].pop_back();
                            g[p.second].pop_back();
                            if (y > 0) ans[pos1] = a[pos2], y--;
                            if (y > 0) ans[pos2] = a[pos1], y--;
                        }
                    }
                }
            }
        }
        if (y > 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}