#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    multiset <ll> a1;
    multiset <pair <ll, ll> > a2;
    int n;
    cin >> n;
    vector <ll> t(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> w[i];
    }
    for (int i = 1; i < n; i++) {
        if (t[i] > t[0]) {
            a1.insert(w[i] + 1 - t[i]);
        } else {
            a2.insert({t[i], w[i] + 1 - t[i]});
        }
    }
    int ans = (int) a1.size() + 1;
    while (1) {
        ans = min(ans, (int) a1.size() + 1);
        if ((int) a1.size() == 0) {
            cout << 1 << endl;
            return 0;
        } else {
            auto it = a1.begin(); 
            if (*it > t[0]) break;
            t[0] -= *it;
            a1.erase(it);
            while ((int) a2.size() > 0 && a2.rbegin()->fc > t[0]) {
                a1.insert(a2.rbegin()->sc);
                a2.erase(--a2.end());
            }
        }
    }
    cout << ans << '\n';
}