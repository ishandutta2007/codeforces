#include<bits/stdc++.h>

using namespace std;

vector < int > a;
int ok, f = 1, s = 1;

void dfs(int pos, int n) {
    if (ok) return;
    if (pos == (int)a.size() || pos == 10) {
        int go = n / (f * s);
        if (min({f, s, go}) == 1) return;
        if (f != s && f != go && go != s) {
            cout << "YES" << '\n';
            cout << f << " " << s << " " << go << '\n';
            ok = 1;
            return;
        }
        return;
    }
    f *= a[pos], dfs(pos + 1, n);
    f /= a[pos];
    s *= a[pos], dfs(pos + 1, n);
    s /= a[pos];
    dfs(pos + 1, n);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int i = 2, T = n;
        a = {};
        while (i * i <= n) {
            if (n % i == 0) a.push_back(i), n /= i;
            else ++i;
        }
        if (n != 1) a.push_back(n);
        ok = 0, f = 1, s = 1;
        dfs(0, T);
        if (ok == 0) cout << "NO" << '\n';
    }
    return 0;
}