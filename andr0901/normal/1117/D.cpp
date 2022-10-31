#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;
typedef vector <vector <int>> matrix;

const int MOD = 1e9 + 7;
int m;

matrix operator*(const matrix& a, const matrix& b) {
    matrix ans(a.size(), vector <int> (b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
                ans[i][j] = (ans[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
    return ans;
}

matrix power(matrix a, long long m) {
    matrix ans(a.size(), vector <int> (a.size()));
    for (int i = 0; i < (int)a.size(); i++)
        ans[i][i] = 1;
    while (m) {
        if (m % 2) {
            ans = ans * a;
            m--;
        } else {
            a = a * a;
            m /= 2;
        }
    }
    return ans;
}

matrix init_transition() {
    matrix ans(m, vector <int> (m));
    ans[0][0] = 1;
    ans[0][m - 1] = 1;
    forn (i, 1, m)
        ans[i][i - 1] = 1;
    /*forn (i, 0, m) {
        forn (j, 0, m)
            cout << ans[i][j] << " ";
        cout << "\n";
    }*/
    return ans;
}

matrix init_basis() {
    matrix ans(m, vector <int> (1));
    forn (i, 0, m)
        ans[i][0] = 1;
    ans[0][0]++;
    /*for (int i = 0; i < 2 * k; i++) {
        for (int j = 0; j < 1; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }*/
    return ans;
}

void output(matrix a) {
    /*int ans = 0;
    for (int i = 0; i < 2 * k; i++)
        ans = (ans + a[i][0]) % MOD;
    cout << ans;*/
    cout << a[0][0];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n >> m;
    if (n == m)
        return cout << 2, 0;
    if (n < m)
        return cout << 1, 0;
    matrix transition = init_transition();
    matrix basis = init_basis();
    output(power(transition, n - m) * basis);
    return 0;
}

/*int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <int> dp(n + 1);
    forn (i, 0, m)
        dp[i] = 1;
    dp[m] = 2;
    forn (i, m + 1, n + 1)
        dp[i] = dp[i - 1] + dp[i - m];

    cout << dp[n];
    return 0;
}*/