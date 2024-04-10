#include<bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 5;
int cnt[maxn], oks[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, last_ans = 1, sum;
    cin >> n;
    cnt[n] = n;
    sum = n;
    for (int i = 1; i <= n; ++i) oks[i] = 1;
    for (int i = n - 1; i >= 1; --i) {
        int f = i + 1;
        for (int j = 2 * f; j <= n; j += f) {
            sum -= oks[j];
            oks[j] = 0;
        }
        cnt[i] = sum;
    }
    for (int i = 2; i <= n; ++i) {
        while (1) {
            if (cnt[last_ans] >= i) {
                cout << last_ans << " ";
                break;
            }
            else last_ans++;
        }
    }
    return 0;
}