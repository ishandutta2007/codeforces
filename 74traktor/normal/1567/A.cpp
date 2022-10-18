#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;
        for (auto c : s) {
            if (c == 'U') cout << 'D';
            else if (c == 'D') cout << 'U';
            else cout << c;
        }
        cout << '\n';
    }
    return 0;
}