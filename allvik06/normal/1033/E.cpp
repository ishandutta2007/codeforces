#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;
const int INF = 1e9;
vector<int> last_step, cur_step, res;
bool find_tmp = false;
int kek_s;

int kek_ask1(int l, int r) {
    cout << "? " << (int) last_step.size() + r - l + 1 << endl;
    for (int i: last_step) cout << i + 1 << " ";
    for (int i = l; i <= r; ++i) cout << cur_step[i] + 1 << " ";
    cout << endl;
    int big_s;
    cin >> big_s;
    if (!find_tmp) {
        find_tmp = true;
        cout << "? " << (int) last_step.size() << endl;
        for (int i: last_step) cout << i + 1 << " ";
        cout << endl;
        cin >> kek_s;
    }
    cout << "? " << r - l + 1 << endl;
    for (int i = l; i <= r; ++i) cout << cur_step[i] + 1 << " ";
    cout << endl;
    int here_s;
    cin >> here_s;
    return big_s - kek_s - here_s;
}

void real_find_res(int l, int r) {
    if (kek_ask1(l, r) == 0) return;
    if (l == r) {
        res.push_back(cur_step[l]);
        return;
    }
    int m = (l + r) / 2;
    real_find_res(l, m);
    real_find_res(m + 1, r);
}

int ask1(int l, int r, int me) {
    cout << "? " << r - l + 2 << endl;
    for (int i = l; i <= r; ++i) cout << last_step[i] + 1 << " ";
    cout << me + 1 << " ";
    cout << endl;
    int big_s;
    cin >> big_s;
    cout << "? " << r - l + 1 << endl;
    for (int i = l; i <= r; ++i) cout << last_step[i] + 1 << " ";
    cout << endl;
    int small_s;
    cin >> small_s;
    return big_s - small_s;
}

int find_res(int l, int r, int me) {
    if (l == r) {
        return last_step[l];
    }
    int m = (l + r) / 2;
    if (ask1(l, m, me)) return find_res(l, m, me);
    else return find_res(m + 1, r, me);
}

int ask2(vector<int> &all, int i) {
    if (i == -1) {
        cout << "? " << (int) all.size() << endl;
        for (int j: all) cout << j + 1 << " ";
        cout << endl;
    } else {
        cout << "? " << (int) all.size() - 1 << endl;
        for (int j = 0; j < (int) all.size(); ++j) {
            if (i == j) continue;
            cout << all[j] + 1 << " ";
        }
        cout << endl;
    }
    int s;
    cin >> s;
    return s;
}

pair<int, int> final_part(vector<int> &all) {
    if ((int) all.size() <= 1) return {-1, -1};
    int now = ask2(all, -1);
    for (int i = 0; i < (int) all.size(); ++i) {
        int here = ask2(all, i);
        if (here < now) {
            for (int j: all) {
                if (all[i] == j) continue;
                cout << "? 2" << endl << all[i] + 1 << " " << j + 1 << endl;
                int s;
                cin >> s;
                if (s > 0) return {all[i], j};
            }
        }
    }
    return {-1, -1};
}

vector<vector<int>> g;
vector<int> st;

bool find_path(int v, int p, int need) {
    st.push_back(v);
    if (v == need) return true;
    for (int i: g[v]) {
        if (i != p) {
            if (find_path(i, v, need)) return true;
        }
    }
    st.pop_back();
    return false;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector<int> d(n, INF);
    g.resize(n);
    d[0] = 0;
    res = {0};
    while (true) {
        last_step = res;
        res.clear();
        cur_step.clear();
        find_tmp = false;
        for (int i = 0; i < n; ++i) {
            if (d[i] == INF) {
                cur_step.push_back(i);
            }
        }
        if (cur_step.empty()) break;
        real_find_res(0, (int)cur_step.size() - 1);
        for (int i: res) {
            int ans = find_res(0, (int) last_step.size() - 1, i);
            g[ans].push_back(i);
            g[i].push_back(ans);
            d[i] = (d[ans] ^ 1);
        }
    }
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        if (!d[i]) {
            all.push_back(i);
        }
    }
    auto ans = final_part(all);
    if (ans.first == -1) {
        all.clear();
        for (int i = 0; i < n; ++i) {
            if (d[i]) {
                all.push_back(i);
            }
        }
        ans = final_part(all);
    }
    if (ans.first == -1) {
        cout << "Y " << (int) all.size() << endl;
        for (int i: all) cout << i + 1 << " ";
        cout << endl;
        return 0;
    }
    find_path(ans.first, -1, ans.second);
    cout << "N " << (int) st.size() << endl;
    for (int i: st) cout << i + 1 << " ";
    cout << endl;
}