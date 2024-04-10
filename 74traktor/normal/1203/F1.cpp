#include <bits/stdc++.h>

using namespace std;

int const maxn = 105, maxc = 31005;
int used[maxn];
int inf = 1e9;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r, a, b;
    cin >> n >> r;
    vector < pair < int, int > > Q1, Q2;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        if (b >= 0) {
            Q1.push_back({a, b});
        }
        else {
            Q2.push_back({a, b});
        }
    }
    sort(Q1.begin(), Q1.end());
    for (auto key : Q1) {
        if (r >= key.first) {
            r += key.second;
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    bool f;
    for (int i = 0; i < (int)Q2.size(); ++i) {
        int sum = 0;
        f = false;
        for (int j = 0; j < (int)Q2.size(); ++j) {
            if (used[j] == 1) continue;
            sum += Q2[j].second;
        }
        int pos = -1, big_sum = -1 * inf;
        for (int j = 0; j < (int)Q2.size(); ++j) {
            if (used[j] == 0) {
                sum -= Q2[j].second;
                if (r + sum >= Q2[j].first && r + sum + Q2[j].second >= 0 && (pos == -1 || sum > big_sum)) {
                    used[j] = 1;
                    big_sum = sum;
                    pos = j;
                    f = true;
                    break;
                }
                sum += Q2[j].second;
            }
        }
        if (pos == -1) {
            cout << "NO" << '\n';
            return 0;
        }
        else used[pos] = 1;
    }
    cout << "YES" << '\n';
    return 0;
}