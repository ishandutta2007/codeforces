#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> n;
        multiset < int > a;
        for (int j = 1; j <= n; ++j) {
            string s;
            cin >> s;
            if ((int)s.size() > 4) continue;
            a.insert(stoi(s));
        }
        int ok = 0;
        while ((int)a.size() > 1) {
            int x = (*a.begin());
            a.erase(a.find(x));
            if (x > 2048) continue;
            int y = (*a.begin());
            a.erase(a.find(y));
            if (x == 2048 || y == 2048) ok = 1;
            if (x != y) a.insert(y);
            else a.insert(x + y);
        }
        if ((int)a.size() == 1 && (*a.begin()) == 2048) ok = 1;
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}