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
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    multiset <int> s;
    forn (i, 0, n)
        s.insert(0);
    int cnt = 1;
    forn (i, 0, m) {
        int t;
        cin >> t;
        t--;
        s.erase(s.find(a[t]));
        a[t]++;
        s.insert(a[t]);
        //cout << *s.begin() << " ";
        if (*s.begin() == cnt) {
            cout << 1;
            cnt++;
        } else
            cout << 0;
    }
    return 0;
}