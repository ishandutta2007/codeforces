#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n0, n1, n2, t;
    cin >> t;
    while (t--) {
        cin >> n0 >> n1 >> n2;
        string ans = "";
        if (n1 == 0) {
            if (n0 > 0) for (int i = 0; i <= n0; ++i) cout << "0";
            if (n2 > 0) for (int i = 0; i <= n2; ++i) cout << "1";
            cout << '\n';
            continue;
        }
        ans = "0";
        for (int i = 0; i < n1; ++i) ans += char((i + 1) % 2 + '0');
        for (int i = 0; i < n0; ++i) ans = "0" + ans;
        string answer = "";
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (ans[i] == '0') answer += ans[i];
            else {
                for (int j = 0; j <= n2; ++j) answer += ans[i];
                for (int j = i + 1; j < (int)ans.size(); ++j) answer += ans[j];
                break;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}