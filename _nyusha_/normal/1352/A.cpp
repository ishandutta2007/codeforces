#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
    cin >> n;
    string s = to_string(n);
    vector < int > a;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != '0') {
            int x = s[i] - '0';
            for (int j = i + 1; j < (int)s.size(); ++j) {
                x *= 10;
            }
            a.push_back(x);
        }
    }
    cout << a.size() << '\n';
    for (auto key : a) cout << key << " ";
    cout << '\n';
    }
    return 0;
}