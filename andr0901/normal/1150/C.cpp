#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int one = 0, two = 0;
    forn (i, 0, n) {
        int t;
        cin >> t;
        if (t == 1)
            one++;
        if (t == 2)
            two++;
    }
    if (!one) {
        forn (i, 0, two)
            cout << "2 ";
        return 0;
    }
    if (!two) {
        forn (i, 0, one)
            cout << "1 ";
        return 0;
    }
    cout << "2 ";
    two--;
    cout << "1 ";
    one--;
    while (one > 1) {
        cout << "1 1 ";
        one -= 2;
    }
    while (two > 0) {
        cout << "2 ";
        two--;
    }
    if (one)
        cout << "1 ";
    return 0;
}