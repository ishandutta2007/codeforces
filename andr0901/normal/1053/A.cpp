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

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int _n, _m, k;
    cin >> _n >> _m >> k;
    if ((2LL * _n * _m) % k)
        return cout << "NO", 0;
    cout << "YES\n0 0\n";
    int n = _n, m = _m;
    int g1 = gcd(n, k); 
    n /= g1, k /= g1;
    int g2 = gcd(m, k);
    m /= g2, k /= g2;
    if (k == 2)
        return cout << n << " 0\n0 " << m, 0;
    if (2 * n <= _n)
        return cout << 2 * n << " 0\n0 " << m, 0;
    if (2 * m <= _m)
        return cout << n << " 0\n0 " << 2 * m, 0;
    return 0;
}