#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<pair<int, int>> evs(m);
    for (int i = 0; i < m; i++) {
        cin >> evs[i].first >> evs[i].second;
        --evs[i].second;
    }

    const int FAT = 400;

    vector<vector<int>> koks(n);
    for (int i = 0; i < m; i++) {
        int j = evs[i].second;
        if (a[j].first + a[j].second > FAT) {
            koks[j].push_back(i);
        }
    }
    vector<int> add(m + 1);
    for (int i = 0; i < n; i++) {
        if (koks[i].size() & 1) {
            koks[i].emplace_back(m);
        }
        for (int j = 0; j < koks[i].size(); j++) {
            if (j & 1) {
                continue;
            } else {
                int st = koks[i][j] + a[i].first;
                int en = koks[i][j + 1];
                while (st < en) {
                    add[st]++;
                    st = min(en, st + a[i].second);
                    add[st]--;
                    st += a[i].first;
                }
            }
        }
    }
    for (int i = 1; i < m; i++) {
        add[i] += add[i - 1];
    }

    vector<vector<int>> cur;
    for (int i = 0; i < FAT; i++) {
        cur.emplace_back(vector<int>(i));
    }

    vector<pair<int, int>> bounds(n);
    for (int i = 0; i < m; i++) {
        int j = evs[i].second;
        int mod = a[j].first + a[j].second;
        if (mod <= FAT) {
            int from;
            int to;
            if (evs[i].first == 1) {
                from = (i + a[j].first) % mod;
                to = i % mod;
                bounds[j] = {from, to};
            } else {
                from = bounds[j].first;
                to = bounds[j].second;
            }
            if (from < to) {
                for (int k = from; k < to; k++) {
                    if (evs[i].first == 1) {
                        cur[mod][k]++;
                    } else {
                        cur[mod][k]--;
                    }
                }
            } else {
                for (int k = from; k < mod; k++) {
                    if (evs[i].first == 1) {
                        cur[mod][k]++;
                    } else {
                        cur[mod][k]--;
                    }
                }
                for (int k = 0; k < to; k++) {
                    if (evs[i].first == 1) {
                        cur[mod][k]++;
                    } else {
                        cur[mod][k]--;
                    }
                }
            }
        }

        for (int k = 1; k < FAT; k++) {
            add[i] += cur[k][i % k];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << add[i] << '\n';
    }

    cout.flush();
    return 0;
}