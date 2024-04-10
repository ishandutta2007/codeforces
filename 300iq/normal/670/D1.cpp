#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define int ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x > 0 ? x : -x)
  
using namespace std;
  
main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k, x, m;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <pair <pair <int, int>, int> > s;
    for (int i = 0; i < n; i++) {
        s.insert(mp(mp(a[i] / b[i], a[i] % b[i]), i));
    }
    while (k--) {
        pair <pair <int, int>, int> p = *s.begin();
        p.fc.sc++;
        while (p.fc.sc >= b[p.sc]) {
            p.fc.fc++;
            p.fc.sc -= b[p.sc];
        }
        s.erase(s.begin());
        s.insert(p);
    }
    cout << s.begin()->fc.fc << endl;
}