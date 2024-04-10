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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MOD = 998244353;
    int n;
    cin >> n;
    string a;
    cin >> a;
    int l = 1;
    forn (i, 1, n) {
        if (a[i] == a[i - 1])
            l++;
        else
            break;
    }
    int r = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1])
            r++;
        else
            break;
    }
    //cout << l << " " << r << "\n";
    if (a[0] == a[n - 1])
        cout << (1LL * (l + 1) * (r + 1)) % MOD;
    else
        cout << (l + r + 1) % MOD;
    return 0;
}