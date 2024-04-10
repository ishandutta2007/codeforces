#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

typedef vector <vector <int>> matrix;

const int MOD = 1e9 + 7;
int m;

matrix operator*(const matrix& a, const matrix& b) {
    matrix ans(a.size(), vector <int> (b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
                ans[i][j] = (ans[i][j] + 1LL * a[i][k] * b[k][j]) % (MOD - 1);
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

matrix init_transition_c() {
    matrix ans = {{1, 1, 1, 1, 0}, 
                  {1, 0, 0, 0, 0}, 
                  {0, 1, 0, 0, 0}, 
                  {0, 0, 0, 1, 1},
                  {0, 0, 0, 0, 1}};
    return ans;
}

int c;

matrix init_basis_c() {
    matrix ans = {{0}, 
                  {0}, 
                  {0}, 
                  {2}, 
                  {2}};
    return ans;
}

matrix init_transition_f() {
    matrix ans = {{1, 1, 1}, 
                  {1, 0, 0}, 
                  {0, 1, 0}};
    return ans;
}

int f1, f2, f3;

matrix init_basis1() {
    matrix ans = {{0}, 
                  {0}, 
                  {1}};
    return ans;
}

matrix init_basis2() {
    matrix ans = {{0}, 
                  {1}, 
                  {0}};
    return ans;
}

matrix init_basis3() {
    matrix ans = {{1}, 
                  {0}, 
                  {0}};
    return ans;
}

int get(matrix a) {
    /*int ans = 0;
    for (int i = 0; i < 2 * k; i++)
        ans = (ans + a[i][0]) % MOD;
    cout << ans;*/
    return a[0][0];
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    return (1LL * bin_pow(a, p / 2) * bin_pow(a, p / 2)) % MOD;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> f1 >> f2 >> f3 >> c, f1 %= MOD, f2 %= MOD, f3 %= MOD;
    matrix transition_c = init_transition_c();
    matrix basis_c = init_basis_c();
    matrix transition_f = init_transition_f();
    matrix basis1 = init_basis1();
    matrix basis2 = init_basis2();
    matrix basis3 = init_basis3();
    cout << ((bin_pow(c, get(power(transition_c, n - 3) * basis_c)) *
             bin_pow(f1, get(power(transition_f, n - 3) * basis1)) % MOD) * 
            ((bin_pow(f2, get(power(transition_f, n - 3) * basis2)) * 
             bin_pow(f3, get(power(transition_f, n - 3) * basis3)) % MOD))) % MOD;
    return 0;
}