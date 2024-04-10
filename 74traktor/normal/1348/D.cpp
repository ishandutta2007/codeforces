#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int lef = 0, righ = min(n, (long long)40);
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            int N = n - mid - 1, sum = 0;
            for (int j = 1; j <= mid; ++j) {
                sum += (mid - j + 1) * (1ll << (j - 1));
            }
            if (sum >= N) righ = mid;
            else lef = mid;
        }
        cout << righ << '\n';
        int cnt = 1;
        int sum = n - righ - 1;
        for (int j = 1; j <= righ; ++j) {
            int f = min(cnt, sum / (righ - j + 1));
            cout << f << " ";
            sum -= f * (righ - j + 1);
            cnt += f;
        }
        assert(sum == 0);
        cout << '\n';
    }
    return 0;
}