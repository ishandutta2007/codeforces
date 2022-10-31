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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    bool ok = 1;
    int a = -1, b = -1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i >= 5 && n / i >= 5) {
                a = i;
                b = n / i;
                break;
            }
        }
    }
    if (a == -1)
        return cout << -1, 0;
    vector <char> t = {'a', 'e', 'i', 'o', 'u'};
    forn (i, 0, a) {
        forn (j, 0, b) {
            cout << t[(i + j) % 5];
        }
    }
    return 0;
}