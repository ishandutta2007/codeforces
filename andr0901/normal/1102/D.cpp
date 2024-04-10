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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(3);
    forn (i, 0, n) {
        char c;
        cin >> c;
        a[i] = c - '0';
        b[a[i]]++;
    }
    forn (i, 0, n) {
        if (b[a[i]] > n / 3 && a[i] == 2) {
            if (b[0] < n / 3) {
                b[a[i]]--;
                a[i] = 0;
                b[0]++;
            }
            else if (b[1] < n / 3) {
                b[a[i]]--;
                a[i] = 1;
                b[1]++;
            }
        }
    }
    forn (i, 0, n) {
        if (b[a[i]] > n / 3 && a[i] == 1) {
            if (b[0] < n / 3) {
                b[a[i]]--;
                a[i] = 0;
                b[0]++;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (b[a[i]] > n / 3 && a[i] == 0) {
            if (b[2] < n / 3) {
                b[a[i]]--;
                a[i] = 2;
                b[2]++;
            }
            else if (b[1] < n / 3) {
                b[a[i]]--;
                a[i] = 1;
                b[1]++;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (b[a[i]] > n / 3 && a[i] == 1)
            if (b[2] < n / 3) {
                b[a[i]]--;
                a[i] = 2;
                b[2]++;
            }
    }
    forn (i, 0, n)
        cout << a[i];
    return 0;
}