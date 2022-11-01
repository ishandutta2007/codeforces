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

    int n;
    cin >> n;

    vector<int> green, blue, red;
    for (int i = 0; i < n; ++i) {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'R') {
            red.push_back(x);
        } else if (c == 'B') {
            blue.push_back(x);
        } else {
            green.push_back(x);
        }
    }
    int64_t ans = 0;
    if (SZ(green) == 0) {
        if (red.empty()) {
            red.push_back(0);
        }
        if (blue.empty()) {
            blue.push_back(0);
        }
        ans = red.back() - red.front() + blue.back() - blue.front();
    } else {
        int posr = 0, posb = 0;
        while (posr < SZ(red) && red[posr] < green[0]) {
            ans += (posr + 1 == SZ(red) || red[posr + 1] > green[0]) ? green[0] - red[posr]:
                red[posr + 1] - red[posr];
            posr++;
        }
        while (posb < SZ(blue) && blue[posb] < green[0]) {
            ans += (posb + 1 == SZ(blue) || blue[posb + 1] > green[0]) ? green[0] - blue[posb]:
                blue[posb + 1] - blue[posb];
            posb++;
        }
        for (int i = 0; i + 1 < SZ(green); ++i) {
            int rightr = posr;
            int rightb = posb;
            while (rightr < SZ(red) && red[rightr] < green[i + 1]) {
                rightr++;
            }
            while (rightb < SZ(blue) && blue[rightb] < green[i + 1]) {
                rightb++;
            }
            int64_t cost1 = 2 * (green[i + 1] - green[i]);
            int64_t cost2 = green[i + 1] - green[i];
            if (rightr > posr) {
                cost2 += green[i + 1] - green[i];
                int vmax = max(red[posr] - green[i], green[i + 1] - red[rightr - 1]);
                for (int j = posr + 1; j < rightr; ++j) {
                    vmax = max(vmax, red[j] - red[j - 1]);
                }
                cost2 -= vmax;
            }
            if (rightb > posb) {
                cost2 += green[i + 1] - green[i];
                int vmax = max(blue[posb] - green[i], green[i + 1] - blue[rightb - 1]);
                for (int j = posb + 1; j < rightb; ++j) {
                    vmax = max(vmax, blue[j] - blue[j - 1]);
                }
                cost2 -= vmax;
            }
            ans += min(cost1, cost2);

            posr = rightr;
            posb = rightb;
        }
        while (posr < SZ(red)) {
            ans += (posr - 1 < 0 || red[posr - 1] < green.back()) ? red[posr] - green.back():
                red[posr] - red[posr - 1];
            posr++;
        }
        while (posb < SZ(blue)) {
            ans += (posb - 1 < 0 || blue[posb - 1] < green.back()) ? blue[posb] - green.back():
                blue[posb] - blue[posb - 1];
            posb++;
        }
    }
    cout << ans << '\n';
}