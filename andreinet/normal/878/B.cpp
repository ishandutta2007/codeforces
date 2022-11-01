#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int LIM = 600010;;
const int TRIM = 300000;

pair<vector<pair<int, int64_t>>, int64_t> getAnswer(const vector<int>& a, int m, int k) {
    if (m == 0) {
        return {{}, 0};
    } else {
        vector<pair<int, int64_t>> stk;
        pair<vector<pair<int, int64_t>>, int64_t> b = getAnswer(a, m / 2, k);
        int64_t rem = b.second * 2;
        for (int u = 0; u < 2; ++u) {
            for (const pair<int, int64_t>& p: b.first) {
                if (p.first >= 0 && !stk.empty() && p.first == stk.back().first) {
                    stk.back().second += p.second;
                } else {
                    stk.push_back(p);
                }
                while (!stk.empty()) {
                    int64_t buckets = stk.back().second / k;
                    if (buckets == 0) {
                        break;
                    }
                    stk.back().second %= k;
                    rem += buckets * k;
                    if (stk.back().second == 0) {
                        stk.pop_back();
                    }
                }
            }
        }
        if (m & 1) {
            for (int x : a) {
                pair<int, int64_t> p = make_pair(x, (int64_t) 1);
                if (p.first >= 0 && !stk.empty() && p.first == stk.back().first) {
                    stk.back().second += p.second;
                } else {
                    stk.push_back(p);
                }
                while (!stk.empty()) {
                    int64_t buckets = stk.back().second / k;
                    if (buckets == 0) {
                        break;
                    }
                    stk.back().second %= k;
                    rem += buckets * k;
                    if (stk.back().second == 0) {
                        stk.pop_back();
                    }
                }
            }
        }
        if (SZ(stk) > LIM) {
            vector<pair<int, int64_t>> nStk;
            for (int i = 0; i < TRIM; ++i) {
                nStk.push_back(stk[i]);
            }
            nStk.push_back(make_pair(-1, (int64_t) 1));
            for (int i = SZ(stk) - TRIM; i < SZ(stk); ++i) {
                nStk.push_back(stk[i]);
            }
            stk = move(nStk);
        }
        return make_pair(stk, rem);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int& x: a) {
        cin >> x;
    }

    vector<pair<int, int64_t>> rem;
    int64_t ans;
    tie(rem, ans) = getAnswer(a, m, k);
    // for (const pair<int, int64_t>& p: rem) {
    //     cerr << p.first << ' ' << p.second << endl;
    // }

    cout << (int64_t) m * n - ans << '\n';
}