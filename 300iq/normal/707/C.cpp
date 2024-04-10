#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1 << endl;
        return 0;
    }
    ll p = n * (ll) n;
    if (n % 2 == 0) {
        cout << p / 4 - 1 << ' ' << p / 4 + 1 << endl;
        return 0;
    } else {
        cout << p / 2 << ' ' << p / 2 + 1 << endl;
        return 0;
    }
}