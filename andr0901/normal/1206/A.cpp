#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    int m;
    cin >> m;
    vector <int> b(m);
    forn (i, 0, m) 
        cin >> b[i];
    forn (i, 0, n) {
        forn (j, 0, m) {
            int c = a[i] + b[j];
            bool ok = 1;
            forn (k, 0, n)  
                if (a[k] == c)
                    ok = 0;
            forn (k, 0, m)
                if (b[k] == c)
                    ok = 0;
            if (ok) {
                cout << a[i] << " " << b[j];
                return 0;
            }
        }
    }
    return 0;
}