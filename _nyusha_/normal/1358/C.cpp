#include<bits/stdc++.h>

using namespace std;

#define int long long
int dp[7][7][100];

inline int get_sum(int x) {
    assert(x >= -1);
    return x * (x + 1) / 2;
}

inline int val(int x, int y) {
    return x + get_sum(x + y - 2);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*dp[0][0][1] = 1;
    vector < vector < int > > a = {{1, 2, 4}, {3, 5, 8}, {6, 9, 13}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int sum = a[i][j]; sum <= 50; ++sum) {
                if (i > 0) dp[i][j][sum] = (dp[i][j][sum]|dp[i - 1][j][sum - a[i][j]]);
                if (j > 0) dp[i][j][sum] = (dp[i][j][sum]|dp[i][j - 1][sum - a[i][j]]);
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int cnt = 0;
            cout << i << " " << j << " : ";
            for (int s = 0; s <= 50; ++s) {
                if (dp[i][j][s]) cnt++;
            }
            cout << cnt << "  ::  ";
            for (int s = 0; s <= 50; ++s) {
                if (dp[i][j][s]) cout << s << " ";
            }
            cout << endl;
        }
    }
    //exit(0);
    */
    int t, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        if (x2 - x1 <= y2 - y1) {
            ans += get_sum(x2 - x1);
            ans += (val(x2, y1) - val(x1, y1 + x2 - x1)) * (y2 - y1 - (x2 - x1));
            int d = val(x2, y1 + (y2 - y1 - (x2 - x1))) - val(x1, y2);
            ans += (get_sum(d - 1) - get_sum(d - 1 - (x2 - x1)));
        }
        else {
            ans += get_sum(y2 - y1);
            ans += (x2 - x1 - (y2 - y1)) * (val(x1 + y2 - y1, y1) - val(x1, y2));
            int d = val(x2, y1) - val(x1 + (x2 - x1 - (y2 - y1)), y2);
            ans += (get_sum(d - 1) - get_sum(d - 1 - (y2 - y1)));
        }
        cout << abs(ans) + 1 << endl;
    }
    return 0;
}