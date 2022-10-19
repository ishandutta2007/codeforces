#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
const int INF = 1e9;

struct node {
    array <int, 2> nxt = {-1, -1};
    int mx1 = -INF, mx2 = -INF;
};

vector <node> nodes;

void add(int x, int val) {
    int now = 0;
    for (int i = 29; i >= 0; --i) {
        nodes[now].mx2 = nodes[now].mx1;
        nodes[now].mx1 = val;
        int b = ((x >> i) & 1);
        if (nodes[now].nxt[b] == -1) {
            int nxt = (int)nodes.size();
            nodes.emplace_back();
            nodes[now].nxt[b] = nxt;
        }
        now = nodes[now].nxt[b];
    }
    nodes[now].mx2 = nodes[now].mx1;
    nodes[now].mx1 = val;
}

vector <int> solve1(int n, int q, vector <int>& a, vector <pair <int, int>>& query) {
    nodes.clear();
    vector <int> ans(q);
    vector <vector <int>> l(n), r(n);
    for (int i = 0; i < q; ++i) {
        int x = query[i].first, y = query[i].second;
        l[x].push_back(i);
        r[y].push_back(i);
        query[i] = make_pair(x, y);
    }
    map <int, int> num;
    vector <vector <int>> all(n);
    vector <vector <int>> all_x(q);
    for (int b = 29; b >= 0; --b) {
        int cha = 0;
        num.clear();
        for (int i = 0; i < n; ++i) all[i].clear();
        for (int i = 0; i < n; ++i) {
            int x = (a[i] >> (b + 1)), nu;
            if (num.count(x)) nu = num[x];
            else {
                num[x] = cha;
                nu = cha;
                ++cha;
            }
            if ((a[i] >> b) & 1) continue;
            all[nu].push_back(i);
        }
        for (int i = 0; i < q; ++i) {
            if (!num.count(ans[i])) {
                ans[i] = ans[i] * 2 + 1;
                continue;
            }
            int nu = num[ans[i]];
            int c = upper_bound(all[nu].begin(), all[nu].end(), query[i].second) - lower_bound(all[nu].begin(), all[nu].end(), query[i].first);
            if (c >= 2) {
                ans[i] *= 2;
                continue;
            } else if (c == 1) {
                all_x[i].push_back(*lower_bound(all[nu].begin(), all[nu].end(), query[i].first));
            }
            ans[i] *= 2;
            ++ans[i];
        }
    }
    nodes.emplace_back();
    for (int i = 0; i < n; ++i) {
        add(a[i], i);
        for (int j : r[i]) {
            for (int z : all_x[j]) {
                int now = 0;
                for (int b = 29; b >= 0; --b) {
                    int nxt0 = nodes[now].nxt[0], nxt1 = nodes[now].nxt[1];
                    if ((a[z] >> b) & 1) {
                        if (nxt0 != -1 && nodes[nxt0].mx1 >= query[j].first) {
                            ans[j] = min(ans[j], a[z] | a[nodes[nxt0].mx1]);
                        }
                        if (nxt1 == -1) break;
                        now = nxt1;
                    } else {
                        if (nxt0 != -1) {
                            if (nodes[nxt0].mx1 != z && nodes[nxt0].mx1 >= query[j].first) {
                                now = nxt0;
                                continue;
                            }
                            if (nodes[nxt0].mx2 != z && nodes[nxt0].mx2 >= query[j].first) {
                                now = nxt0;
                                continue;
                            }
                        }
                        if (nxt1 == -1) break;
                        now = nxt1;
                    }
                }
                if (nodes[now].mx1 >= query[j].first && nodes[now].mx1 != z) ans[j] = min(ans[j], a[z] | a[nodes[now].mx1]);
                if (nodes[now].mx2 >= query[j].first && nodes[now].mx2 != z) ans[j] = min(ans[j], a[z] | a[nodes[now].mx2]);
            }
        }
    }
    return ans;
}

vector <int> solve2(int n, int q, vector <int>& a, vector <pair <int, int>>& query) {
    vector <int> ans;
    for (auto i : query) {
        int minn = INF;
        for (int j = i.first; j <= i.second; ++j) {
            for (int k = j + 1; k <= i.second; ++k) {
                minn = min(minn, a[j] | a[k]);
            }
        }
        ans.push_back(minn);
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            int n, q;
            cin >> n;
            vector <int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            cin >> q;
            vector <pair <int, int>> query(q);
            for (int i = 0; i < q; ++i) {
                cin >> query[i].first >> query[i].second; --query[i].first; --query[i].second;
            }
            auto ans = solve1(n, q, a, query);
            for (int i : ans) cout << i << "\n";
        }
    } else {
        srand(1303);
        int t;
        cin >> t;
        while (t--) {
            if (t % 100 == 0) cout << t << "\n";
            int n = 100, q = 100;
            vector <int> a(n);
            for (int i = 0; i < n; ++i) a[i] = rand() % 10000;
            vector <pair <int, int>> query(q);
            for (int i = 0; i < q; ++i) {
                int l = rand() % n, r = rand() % n;
                while (l >= r) {
                    l = rand() % n;
                    r = rand() % n;
                }
                query[i] = make_pair(l, r);
            }
            if (solve1(n, q, a, query) != solve2(n, q, a, query)) {
                cout << n << "\n";
                for (int i : a) cout << i << " ";
                cout << "\n";
                cout << q << "\n";
                for (auto i : query) cout << i.first + 1 << " " << i.second + 1 << "\n";
                return 0;
            }
        }
    }
}

/*
5
14 3 14 5 1
5
1 4
3 4
3 4
4 5
1 2
 */