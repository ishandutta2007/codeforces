#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, logg = 18;
int a[maxn], dp[maxn];
int go[logg][maxn], st[maxn];

int get(int l, int r) {
    int x = st[r - l + 1];
    return __gcd(go[x][l], go[x][r - (1 << x) + 1]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        go[0][i] = a[i];
    }
    for (int j = 1; j < logg; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            go[j][i] = __gcd(go[j - 1][i], go[j - 1][i + (1 << (j - 1))]);
        }
    }
    int x = 2;
    for (int i = 2; i <= n; ++i) {
        st[i] = st[i - 1] + (x == i);
        if (x == i) x *= 2;
    }
    vector < pair < int, int > > st;
    for (int i = 1; i <= n; ++i) {
        int lef = 1, righ = i + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            int t = get(mid, i);
            if (t <= i - mid + 1) lef = mid;
            else righ = mid;
        }
        int t = get(lef, i);
        if (t == i - lef + 1) dp[i] = dp[lef - 1] + 1;
        else dp[i] = dp[i - 1];
        cout << dp[i] << " ";
    }
    return 0;
}