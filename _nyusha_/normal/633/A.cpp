#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x <= c; ++x) {
        if (c - a * x >= 0 && (c - a * x) % b == 0) {
            cout << "Yes";
            exit(0);
        }
    }
    cout << "No";
    return 0;
}