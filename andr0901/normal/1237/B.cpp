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
    int n;
    cin >> n;
    vector <int> ord(n);
    forn (i, 0, n) {
        int t;
        cin >> t;
        ord[t - 1] = i;
    }
    int mn = 1e9;
    int ans = 0;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (ord[a[i] - 1] > mn)
            ans++;
        mn = min(mn, ord[a[i] - 1]);
        //cout << ord[a[i] - 1] + 1 << " ";
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}