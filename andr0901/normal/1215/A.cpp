#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    } {
        int _n = n;
        _n -= (k1 - 1) * a1 + (k2 - 1) * a2;
        cout << max(0, _n);
    } 
    cout << " "; {
        int _n = n;
        int deleted = min(a1, _n / k1);
        _n -= deleted * k1;
        cout << deleted + min(a2, _n / k2);
    }
    return 0;
}