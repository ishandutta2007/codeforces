#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int ok[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set < char > t;
    for (int i = 1; i <= k; ++i) {
        char x;
        cin >> x;
        t.insert(x);
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (t.find(s[i]) != t.end()) ok[i] = 1;
    }
    int ans = 0, lst = -1;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (ok[i] == 0) lst = -1;
        else {
            if (lst == -1) lst = i;
            ans += (lst - i + 1);
        }
    }
    cout << ans;
    return 0;
}