#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, c;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> a >> b >> c;
        int sum = a + b + c;
        if (max({a, b, c}) <= sum - max({a, b, c}) + 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}