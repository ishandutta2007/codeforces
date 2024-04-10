#include <bits/stdc++.h>

using namespace std;

int gett[100005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= 100000; ++i) {
        string g = to_string(i);
        gett[i] = (int)g.size();
    }
    for (int t = 1; t <= q; ++t) {
        cin >> n;
        int x = 1, sum = 1;
        while (1) {
            if (sum < n) {
                n -= sum;
            }
            else break;
            x++;
            sum += gett[x];
        }
        string s = "";
        for (int i = 1; i <= n; ++i) {
            s += to_string(i);
            if ((int)s.size() >= n) {
                cout << s[n - 1] << '\n';
                break;
            }
        }
    }
    return 0;
}