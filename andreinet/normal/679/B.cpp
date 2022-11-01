#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t cube(int x) {
    return (int64_t) x * x * x;
}

int64_t getAns(int64_t m) {
    int64_t cnt1 = 0;
    int maxVal = 1e5;
    int firstv = -1, firstc = 0;

    int64_t cm = m;

    for (int i = maxVal; i > 0; --i) {
        int64_t v = (int64_t) i * i * i;
        if (v <= cm) {
            if (firstv == -1) {
                firstv = i;
                firstc = cm / v;
            }
            cnt1 += cm / v;
            cm %= v;
        }
    }

    int64_t cnt2 = 0;
    int64_t X2 = 0;
    for (int i = 1; i < firstv; ++i) {
        int64_t v = cube(i);
        int64_t v1 = cube(i + 1);
        cnt2 += (v1 - 1 - X2) / v;
        X2 += v * ((v1 - 1 - X2) / v);
    }
    X2 += firstv * (firstc - 1);
    return max(cnt1, cnt2);
}

void solve1(int64_t m) {
    int64_t ans1 = getAns(m);
    int64_t ans2 = m;
    for (int64_t step = 1LL << 62; step > 0; step /= 2) {
        if (ans2 - step > 0 && getAns(ans2 - step) == ans1) {
            ans2 -= step;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

void solve2(int64_t m) {
    int ans1 = 0;
    int64_t ans2 = 0;
    int maxVal = 1e5;
    for (int i = 0; i <= 7; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (1 * i + 8 * j >= 27) {
                break;
            }
            for (int k = 0; k <= 2; ++k) {
                if (1 * i + 8 * j + 27 * k >= 64) {
                    break;
                }
                if (1 * i + 8 * j + 27 * k > m) {
                    break;
                }
                int64_t val = 1 * i + 8 * j + 27 * k;
                int cnt = i + j + k;
                tie(ans1, ans2) = max(make_pair(ans1, ans2),
                                      make_pair(cnt, val));
                vector<int> poss;
                for (int x = 4; x <= maxVal; ++x) {
                    int64_t v = cube(x);
                    int64_t v1 = cube(x + 1);
                    if (val + v <= m && val + v < v1) {
                        cnt++;
                        poss.push_back(x);
                        val += v;
                    }
                }
                int64_t cval = val;
                int64_t vmin = m + 1;
                for (int i = SZ(poss) - 1; i >= 0; --i) {
                    for (int step = 1 << 16; step > 0; step /= 2) {
                        if (poss[i] + step > maxVal) {
                            continue;
                        }
                        if (i < SZ(poss) - 1 && poss[i] + step >= poss[i + 1]) {
                            continue;
                        }
                        int64_t ncval = cval - cube(poss[i]) +
                            cube(poss[i] + step);
                        int64_t add = cube(poss[i] + step) - cube(poss[i]);
                        if (add > vmin) {
                            continue;
                        }
                        int64_t nval = val - cube(poss[i]) +
                                       cube(poss[i] + step);
                        if (nval <= m) {
                            val = nval;
                            cval = ncval;
                            vmin -= add;
                            poss[i] += step;
                        }
                    }
                    vmin = min(vmin, cube(poss[i] + 1) - 1 - cval);
                    cval -= cube(poss[i]);
                }
                tie(ans1, ans2) = max(make_pair(ans1, ans2),
                                      make_pair(cnt, val));
            }
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int64_t m;
    cin >> m;
    solve2(m);
}