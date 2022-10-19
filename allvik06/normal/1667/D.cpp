#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int INF = 1e9;
vector <vector <int>> g, gg;
vector <int> p, gl, type;
vector <pair <int, int>> ans;

void dfs(int v) {
    for (int i : gg[v]) {
        if (i == p[v]) continue;
        gl[i] = gl[v] + 1;
        g[v].push_back(i);
        p[i] = v;
        dfs(i);
    }
}

void find_ans(int v, int need) {
    int d = (v == 0);
    vector <int> all0, all1, all;
    for (int i : g[v]) {
        if (type[i] == 0) all0.push_back(i);
        else if (type[i] == 1) all1.push_back(i);
        else all.push_back(i);
    }
    while (true) {
        int cnt0 = (int)all0.size();
        int cnt1 = (int)all1.size();
        int cnt = (int)all.size();
        int tot = cnt0 + cnt1 + cnt;
        if (tot % 2 == 0) {
            if (cnt1 + cnt >= cnt0 && cnt0 + cnt >= cnt1 - 1 && need == 0) {
                ans.emplace_back(p[v], v);
                need = 2;
                d = 1;
            }
        } else {
            if (cnt0 + cnt >= cnt1 && cnt1 + cnt >= cnt0 - 1 && need == 1) {
                ans.emplace_back(p[v], v);
                need = 2;
                d = 1;
            }
        }
        if (cnt0 || cnt1 || cnt) {
            if (tot % 2 == d) {
                if (cnt0) {
                    find_ans(all0.back(), 0);
                    all0.pop_back();
                }
                else if (cnt) {
                    find_ans(all.back(), 0);
                    all.pop_back();
                }
                else break;
            } else {
                if (cnt1) {
                    find_ans(all1.back(), 1);
                    all1.pop_back();
                }
                else if (cnt) {
                    find_ans(all.back(), 1);
                    all.pop_back();
                }
                else break;
            }
        } else {
            break;
        }
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.assign(n, {});
        gg.assign(n, {});
        p.assign(n, -1);
        gl.assign(n, 0);
        type.assign(n, -1);
        ans.clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            gg[x].push_back(y);
            gg[y].push_back(x);
        }
        dfs(0);
        vector <int> all;
        for (int i = 0; i < n; ++i) all.push_back(i);
        sort(all.begin(), all.end(), [&](int a, int b) {
            return gl[a] > gl[b];
        });
        for (int i = 0; i < n; ++i) {
            if (g[i].empty()) type[i] = 0;
        }
        bool ok = true;
        for (int i : all) {
            int v = p[i];
            if (type[v] != -1) continue;
            int cnt0 = 0, cnt1 = 0, cnt = 0;
            for (int j : g[v]) {
                if (type[j] == 0) ++cnt0;
                else if (type[j] == 1) ++cnt1;
                else ++cnt;
            }
            if (v == 0) {
                break;
            }
            bool can0 = false, can1 = false;
            while (true) {
                int tot = cnt0 + cnt1 + cnt;
                if (tot % 2 == 0) {
                    if (cnt1 + cnt >= cnt0 && cnt0 + cnt >= cnt1 - 1) can0 = true;
                } else {
                    if (cnt0 + cnt >= cnt1 && cnt1 + cnt >= cnt0 - 1) can1 = true;
                }
                if (cnt0 || cnt1 || cnt) {
                    if (tot % 2 == 0) {
                        if (cnt0) --cnt0;
                        else if (cnt) --cnt;
                        else break;
                    } else {
                        if (cnt1) --cnt1;
                        else if (cnt) --cnt;
                        else break;
                    }
                } else {
                    break;
                }
            }
            if (can0 && can1) type[v] = 2;
            else if (can0) type[v] = 0;
            else if (can1) type[v] = 1;
            else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        find_ans(0, 2);
        if ((int)ans.size() != n - 1) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
    }
}

/*

 */