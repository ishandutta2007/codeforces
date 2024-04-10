#include<bits/stdc++.h>

using namespace std;

int ans[5][5];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    ans[1][1] = (1 << 18) - 1, ans[3][1] = 0, ans[3][2] = 0, ans[1][3] = 0, ans[3][3] = (1 << 18) - 1, ans[2][2] = (1 << 18) - 1;
    ans[2][3] = k, ans[1][2] = k, ans[2][1] = (((1 << 18) - 1)^k);
    cout << "3 3" << '\n';
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}