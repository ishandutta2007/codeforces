#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
#ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, b;
    cin >> n >> d >> b;

    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int step = 1 << 17; step > 0; step /= 2) {
//    for (int step = 1; step > 0; step = 0) {
        int curr = ans + step - 1;
        int firstGood = curr + 1;
        int lastGood = n - curr;
        if (firstGood > lastGood) {
            continue;
        }
        vector<int64_t> c(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            c[i] = a[i];
        }
        vector<int64_t> v(n + 2, 0);
        for (int i = 1; i < firstGood; ++i) {
            v[i] = c[i];
        }
        for (int i = firstGood; i <= lastGood; ++i) {
            v[i] = max((int64_t) 0, c[i] - b);
        }
        for (int i = lastGood + 1; i <= n; ++i) {
            v[i] = c[i];
        }
        vector<int64_t> have = c;
        int push = firstGood;
        int drag = firstGood;
        for (int i = 1; i <= n; ++i) {
            if ((have[i] < b && firstGood <= i && i <= lastGood) || v[i] < 0) {
                drag = max(drag, i + 1);
                int64_t x = (firstGood <= i && i <= lastGood ? max(b - have[i], (int64_t) 0): 0) - v[i];
                int64_t init = x;
                while (drag <= n && drag - d * (int64_t) i <= i && x > 0) {
                    if (c[drag] >= x) {
                        c[drag] -= x;
                        v[drag] -= x;
                        x = 0;
                        break;
                    } else {
                        x -= c[drag];
                        v[drag] -= c[drag];
                        c[drag] = 0;
                        drag++;
                    }
                }
                x = init - x;
                if (firstGood <= i && i <= lastGood && have[i] < b) {
                    have[i] += x;
                    x = 0;
                    if (have[i] > b) {
                        x = have[i] - b;
                        have[i] = b;
                    }
                }
                v[i] += x;
            }
            if ((have[i] < b && firstGood <= i && i <= lastGood) || v[i] < 0) {
                cerr << i << ' ' << have[i] << ' ' << v[i] << endl;
                cerr << drag << endl;
                break;
            }
            push = max(push, i + 1);
            while (push <= n && i + d * (int64_t) (n - push + 1) >= push) {
                if (have[push] < b) {
                    if (v[i] >= b - have[push]) {
                        v[i] -= b - have[push];
                        have[push] = b;
                    } else {
                        have[push] += v[i];
                        v[i] = 0;
                        break;
                    }
                }
                int64_t diff = c[push] - v[push];
                if (v[i] >= diff) {
                    v[i] -= diff;
                    v[push] = c[push];
                    push++;
                } else {
                    v[push] += v[i];
                    v[i] = 0;
                    break;
                }
            }
        }
        bool ok = true;
        for (int i = firstGood; i <= lastGood; ++i) {
            ok &= have[i] >= b;
        }
        if (!ok) {
            ans += step;
        }
    }

    cout << ans << '\n';
}