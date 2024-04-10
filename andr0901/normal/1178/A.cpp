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
    vector <int> a(n), ans;
    int s = 0, Alise = 0;
    forn (i, 0, n) {
        cin >> a[i];
        s += a[i];
        if (!i) {
            Alise += a[i];
            ans.pb(0);
        }
        if (a[0] >= 2 * a[i]) {
            Alise += a[i];
            ans.pb(i);
        }
    }
    if (s < 2 * Alise) {
        cout << sz(ans) << "\n";
        for (int i : ans)
            cout << i + 1 << " ";
    } else 
        cout << 0;

    return 0;
}