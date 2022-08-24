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
    ll l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    ll l = l1, r = r1;
    l = max(l, l2);
    r = min(r, r2);
    cout << max(0ll, r - l + 1 - (l <= k && k <= r)) << endl;
}