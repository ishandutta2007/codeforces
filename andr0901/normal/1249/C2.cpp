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

vector <ll> p, pref;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    p = pref = {1};
    while (p.back() <= 1e18) {
        p.pb(p.back() * 3);
        pref.pb(pref.back() + p.back());
        //cout << p.back() << " " << pref.back() << "\n";
    }
    int q;
    cin >> q;
    while (q --> 0) {
        ll n;
        cin >> n;
        ll x = *lower_bound(all(pref), n);
        for (int i = lower_bound(all(pref), n) - pref.begin(); i >= 0; --i) {
            if (x - p[i] >= n)
                x -= p[i];
        }
        cout << x << "\n";
    }
    return 0;
}