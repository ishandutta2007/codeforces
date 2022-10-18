#include <bits/stdc++.h>

using namespace std;

main() {
/*#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, ans = 0;
    cin >> n;
    multiset < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.insert(x);
    }
    while ((int)a.size() > 0) {
        ans++;
        x = (*a.begin());
        multiset < int > new_a;
        for (auto key : a) {
            if (key % x != 0) new_a.insert(key);
        }
        a = new_a;
    }
    cout << ans << '\n';
    return 0;
}