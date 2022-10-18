#include <bits/stdc++.h>

using namespace std;

int cnt[27];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    for (int i = 1; i <= cnt['n' - 'a']; ++i) cout << 1 << " ";
    for (int i = 1; i <= cnt['z' - 'a']; ++i) cout << 0 << " ";
    return 0;
}