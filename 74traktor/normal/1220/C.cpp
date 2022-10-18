#include <bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 1;
int cnt[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int j = 0; j < s[i] - 'a'; ++j) if (cnt[j] != 0) f = 1;
        if (f) cout << "Ann" << '\n';
        else cout << "Mike" << '\n';
        cnt[s[i] - 'a']++;
    }
    return 0;
}