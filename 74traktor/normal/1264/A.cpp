#include<bits/stdc++.h>

using namespace std;

int const maxn = 400005;
int a[maxn];

void solve() {
    int n, gg = 0, ss = 0, bb = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int cnt = n / 2;
    vector < int > Q;
    int lst = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != a[i - 1]) Q.push_back(lst), lst = 1;
        else lst++;
    }
    Q.push_back(lst);
    int g = Q[0], s = 0, b = 0;
    for (int i = 1; i < (int)Q.size(); ++i) {
        if (s <= g) s += Q[i];
        else b += Q[i];
        if (g < min(s, b) && g + s + b > gg + ss + bb && g + s + b <= n / 2) {
            gg = g, ss = s, bb = b;
        }
    }
    cout << gg << " " << ss << " " << bb << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}