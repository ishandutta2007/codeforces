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
    int n, m;
    cin >> n >> m;
    char c;
    bool good = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            good |= (c == 'C' || c == 'M' || c == 'Y');
        }
    }
    if (good) {
        cout << "#Color" << endl;
    } else {
        cout << "#Black&White" << endl;
    }
}