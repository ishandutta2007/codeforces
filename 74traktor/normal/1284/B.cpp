#include<bits/stdc++.h>

using namespace std;

#define int long long
int inf = 1e9;
int const maxn = 1e5 + 5;
pair < int, int > a[maxn];
int ok[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, imin, imax, x, y, ans = 0, good = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        imax = -inf, imin = inf;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            imin = min(imin, y);
            imax = max(imax, y);
            if (y > imin) ok[i] = 1;
        }
        a[i] = {imin, imax};
        if (ok[i]) good++;
    }
    vector < int > Q;
    for (int i = 1; i <= n; ++i) if (ok[i] == 0) Q.push_back(a[i].second);
    sort(Q.begin(), Q.end());
    for (int i = 1; i <= n; ++i) {
        if (ok[i]) ans += n;
        else {
            int it = upper_bound(Q.begin(), Q.end(), a[i].first) - Q.begin();
            ans += ((int)Q.size() - it + good);
        }
    }
    cout << ans << '\n';
    return 0;
}