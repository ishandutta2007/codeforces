#include <bits/stdc++.h>

using namespace std;

#define int long long

int toInt(char c) {
    if (c == '0') return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MOD = 998244353;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = toInt(c);
    }
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        b[i] = toInt(c);
    }
    for (int i = 0; i < n / 2; i++) swap(a[i], a[n - i - 1]);
    for (int i = 0; i < m / 2; i++) swap(b[i], b[m - i - 1]);
    vector<long long> sum(n);
    sum[0] = a[0];
    long long curPow = 2;
    for (int i = 1; i < n; i++) {
        sum[i] = (sum[i - 1] + (a[i] * curPow) % MOD) % MOD;
        curPow = (curPow * 2) % MOD;
    }
    long long ans = 0;
    for (int i = 0; i < n && i < m; i++) {
        if (b[i]) ans = (ans + sum[i]) % MOD;
        //cout << ans << " ";
    }
    //cout << "\n";
    for (int i = n; i < m; i++) if (b[i]) ans = (ans + sum[n - 1]) % MOD;
    //for (int i : sum) cout << i << " ";
    cout << ans;
    return 0;
}