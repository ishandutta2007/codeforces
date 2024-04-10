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

    int64_t n;
    int q;
    cin >> n >> q;

    while (q-- > 0) {
        int64_t pos;
        cin >> pos;

        int64_t len = n;
        int64_t have = 0;
        int64_t parity = 0;
        while (true) {
            if (pos % 2 == 1) {
                break;
            }
            int64_t x = (pos - have + 1) / 2;
//            x = len / 2 - x + 1;
            int add = 0;
            if (len % 2 == 1 && have % 2 == 1) {
                add = 1;
            }
            have = have + len;
            pos = have + x;
            len /= 2;
            len += add;
        }
        cout << pos / 2 + 1 << '\n';
    }
}