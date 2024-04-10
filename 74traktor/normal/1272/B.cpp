#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cntl = 0, cntr = 0, cntu = 0, cntd = 0;
    for (auto c : s) {
        if (c == 'L') cntl++;
        else if (c == 'R') cntr++;
        else if (c == 'U') cntu++;
        else cntd++;
    }
    int ans = min(cntl, cntr) + min(cntu, cntd);
    if (min(cntl, cntr) == 0 && min(cntu, cntd) == 0) {
        cout << 0 << '\n';
        return;
    }
    if (min(cntl, cntr) == 0) {
        cout << 2 << '\n';
        cout << "UD" << '\n';
        return;
    }
    if (min(cntu, cntd) == 0) {
        cout << 2 << '\n';
        cout << "RL" << '\n';
        return;
    }
    cout << 2 * ans << '\n';
    for (int i = 0; i < min(cntl, cntr); ++i) cout << "R";
    for (int i = 0; i < min(cntu, cntd); ++i) cout << "U";
    for (int i = 0; i < min(cntl, cntr); ++i) cout << "L";
    for (int i = 0; i < min(cntu, cntd); ++i) cout << "D";
    cout << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}