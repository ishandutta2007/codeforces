#include<bits/stdc++.h>

using namespace std;

void solve() {
    string p, h, check;
    cin >> p >> h;
    check = p;
    sort(check.begin(), check.end());
    for (int i = 0; i + (int)p.size() - 1 < (int)h.size(); ++i) {
        string a = "";
        for (int j = i; j < i + (int)p.size(); ++j) a += h[j];
        sort(a.begin(), a.end());
        if (a == check) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}