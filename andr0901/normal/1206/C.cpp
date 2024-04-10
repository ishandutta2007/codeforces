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
    ll n;
    cin >> n;
    if (n % 2 == 0)
        return cout << "NO", 0;
    cout << "YES\n";
    vector <int> a, b;
    bool flag = 1;
    forn (i, 0, n) {
        if (flag) {
            a.pb(2 * i + 1);
            b.pb(2 * i + 2);
        } else {
            a.pb(2 * i + 2);
            b.pb(2 * i + 1);
        }
        flag = (!flag);
    }
    forn (i, 0, n)
        cout << a[i] << " ";
    forn (i, 0, n) 
        cout << b[i] << " ";
    return 0;
}