#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn];

int good(vector < int > sz, int n) {
    if (n % 2 == 0) {
        int can = 0;
        for (auto key : sz) {
            if (key == 1) continue;
            can += key;
        }
        return can >= n;
    }
    int can = 0, flag = 0;
    for (auto key : sz) {
        if (key == 1) continue;
        if (key > 2) flag = 1;
        can += key;
    }
    return can >= n && flag;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];
        int s1 = 0, s2 = 0;
        vector < int > f, s;
        for (int i = 1; i <= k; i++) {
            f.push_back(a[i] / m);
            s.push_back(a[i] / n);
        }
        if (good(f, n) || good(s, m)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}