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
    int b, k;
    cin >> b >> k;
    vector <int> a(k);
    ll s = 0;
    forn (i, 0, k) {
        cin >> a[i];
        s += a[i];
    }
    if (b % 2) {
        if (s % 2)
            cout << "odd";
        else
            cout << "even";
    } else {
        if (a.back() % 2)
            cout << "odd";
        else
            cout << "even";
    }
    return 0;
}