#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

bool check(const vector<pair<char, int>>& real, const vector<pair<char, int>>& got) {
    for (int i = 0; i < (1 << 10); ++i) {
        int x1 = i, x2 = i;
        for (const auto& p: real) {
            if (p.first == '&') {
                x1 &= p.second;
            } else if (p.first == '|') {
                x1 |= p.second;
            } else {
                x1 ^= p.second;
            }
        }
        for (const auto& p: got) {
            if (p.first == '&') {
                x2 &= p.second;
            } else if (p.first == '|') {
                x2 |= p.second;
            } else {
                x2 ^= p.second;
            }
        }
        if (x1 != x2) {
            return false;
        }
    }
    return true;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> change(10, -1);
    vector<int> doXor(10, 0);

    vector<pair<char, int>> real;
    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '|') {
            for (int j = 0; j < 10; ++j) {
                if (x & (1 << j)) {
                    change[j] = 1;
                    doXor[j] = 0;
                }
            }
        } else if (c == '&') {
            for (int j = 0; j < 10; ++j) {
                if (x & (1 << j)) {
                } else {
                    change[j] = 0;
                    doXor[j] = 0;
                }
            }
        } else {
            for (int j = 0; j < 10; ++j) {
                if (x & (1 << j)) {
                    doXor[j] ^= 1;
                }
            }
        }
        real.push_back(make_pair(c, x));
    }
    int vand = (1 << 10) - 1;
    int vor = 0;
    int vxor = 0;
    for (int i = 0; i < 10; ++i) {
        if (change[i] == 0) {
            vand ^= 1 << i;
        } else if (change[i] == 1) {
            vor |= 1 << i;
        }
        vxor |= doXor[i] << i;
    }
    vector<pair<char, int>> got = {
        {'&', vand},
        {'|', vor},
        {'^', vxor},
    };
    // cerr << check(real, got) << endl;
    cout << SZ(got) << '\n';
    for (const pair<char, int>& p: got) {
        cout << p.first << ' ' << p.second << '\n';
    }
}