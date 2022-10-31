#pragma GCC optmize("Ofast")
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
#define double long double

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    double n, r;
    cin >> n >> r;
    double a = 2.0 * atan2(0, -1) / n;
    cout << fixed << setprecision(30) << (r * (1 - cos(a)) + sqrt(2 * r * r * (1 - cos(a)))) / (1 + cos(a));
    return 0;
}