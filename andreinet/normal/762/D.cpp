#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;
const int64_t LINF = 1LL << 62;

int A[NMAX][3];
int64_t dp[8], ndp[8];

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

        for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < n; ++i) {
            cin >> A[i][j];
        }
    }

    vector<int> states[8][8];
    for (int curr = 0; curr < 8; ++curr) {
        for (int prev = 0; prev < 8; ++prev) {
            vector<int>& st = states[curr][prev];
            for (int k = 0; k < 3; ++k) {
                if ((prev & (1 << k)) != 0 && (curr & (1 << k)) == 0) {
                    goto NEXT;
                }
            }
            if (prev == 7) {
                st = {7, 4, 1};
                continue;
            } else if (prev == 3 || prev == 6 || prev == 5) {
                if (curr == 7) {
                    int o = -1;
                    for (int i = 0; i < 3; ++i) {
                        if ((prev & (1 << i)) == 0) {
                            o = i;
                            break;
                        }
                    }
                    int a, b;
                    if (prev == 3) a = 0, b = 1;
                    else if (prev == 6) a = 1, b = 2;
                    else a = 0, b = 2;
                    st.push_back((1 << a) | (1 << o));
                    st.push_back((1 << b) | (1 << o));
                } else {
                    st = {prev, 0};
                }
            } else if (prev == 0) {
                continue;
            } else {
                if ((curr ^ prev) == 5) {
                    continue;
                }
                if (prev == 1) {
                    if (curr == 1) {
                        st = {1};
                    } else if (curr == 3) {
                        st = {2};
                    } else if (curr == 7) {
                        st = {4, 7};
                    }
                } else if (prev == 2) {
                    if (curr == 3) {
                        st = {1};
                    } else if (curr == 2) {
                        st = {2};
                    } else if (curr == 6) {
                        st = {4};
                    }
                } else if (prev == 4) {
                    if (curr == 7) {
                        st = {1, 7};
                    } else if (curr == 6) {
                        st = {2};
                    } else if (curr == 4) {
                        st = {4};
                    }
                }
            }
            NEXT:;
        }
    }

    for (int i = 0; i < 8; ++i) {
        dp[i] = -LINF;
    }
    dp[1] = 0;
    for (int i = 0; i < n; ++i) {
        fill(ndp, ndp + 8, -LINF);
        for (int conf = 1; conf < 8; ++conf) {
            int64_t add = 0;
            for (int j = 0; j < 3; ++j) {
                if (conf & (1 << j)) {
                    add += A[i][j];
                }
            }
            for (int pconf = 1; pconf < 8; ++pconf) {
                for (int x: states[conf][pconf]) {
                    ndp[x] = max(ndp[x], dp[pconf] + add);
                }
            }
        }
        memcpy(dp, ndp, sizeof dp);
    }
    cout << dp[4] << '\n';
}