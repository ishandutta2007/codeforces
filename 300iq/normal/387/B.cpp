#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    set <int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    int cnt = 0;
    vector <int> f;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        f.pb(x);
    }
    reverse(all(f));
    for (int i = 0; i < m; i++) {
        x = f[i];
        if (s.size() == 0) {
            continue;
        }
        auto it = s.upper_bound(x);
        if (it == s.begin()) {
            continue;
        } else {
            cnt++;
            it--;
            s.erase(it);
        }
    }
    printf("%d\n", n - cnt);
}