#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Block {
    int64_t len;
    char c;
    Block() {}
    Block(int64_t _len, char _c):
        len(_len), c(_c) {}

    bool operator==(const Block& o) const {
        return len == o.len && c == o.c;
    }
    bool operator!=(const Block& o) const {
        return len != o.len || c != o.c;
    }
};

vector<Block> compress(const vector<Block>& S) {
    vector<Block> ret;
    ret.push_back(S[0]);
    for (int i = 1; i < SZ(S); ++i) {
        if (S[i].c == ret.back().c) {
            ret.back().len += S[i].len;
        } else {
            ret.push_back(S[i]);
        }
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<Block> S1, S2;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        cin.get();
        char c;
        cin >> c;
        S1.push_back(Block(l, c));
    }
    S1 = compress(S1);
    n = SZ(S1);
    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        cin.get();
        char c;
        cin >> c;
        S2.push_back(Block(l, c));
    }
    S2 = compress(S2);
    m = SZ(S2);
    if (SZ(S2) == 1) {
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            if (S1[i].c == S2[0].c) {
                ans += max((int64_t) 0, S1[i].len - S2[0].len + 1);
            }
        }
        cout << ans << '\n';
    } else if (SZ(S2) == 2) {
        int64_t ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (S1[i].c == S2[0].c && S1[i + 1].c == S2[1].c &&
                S1[i].len >= S2[0].len && S1[i + 1].len >= S2[1].len) {
                ++ans;
            }
        }
        cout << ans << '\n';
    } else {
        vector<int> P(m + 1, 0);
        int l = m - 2;
        for (int i = 2, k = 0; i <= l; ++i) {
            while ((k != 0 && S2[i] != S2[k + 1]) || k == l) {
                k = P[k];
            }
            if (k + 1 <= l && S2[i] == S2[k + 1]) {
                ++k;
            }
            P[i] = k;
        }
        int64_t ans = 0;
        for (int i = 1, k = 0; i < n - 1; ++i) {
            while ((k != 0 && S1[i] != S2[k + 1]) || k == l) {
                k = P[k];
            }
            if (k + 1 <= l && S1[i] == S2[k + 1]) {
                ++k;
            }
            if (k == l &&
                S1[i - l].c == S2[0].c && S1[i + 1].c == S2.back().c &&
                S1[i - l].len >= S2[0].len && S1[i + 1].len >= S2.back().len) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}