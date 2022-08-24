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

const int MAXN = (int) 1e5 + 7;
bool good[MAXN];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int u, v, l;
    vector <pair <int, pair <int, int> > > abc;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &l);
        abc.pb({l, {u, v}});
    }
    int x;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        good[x] = 1;
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (good[abc[i].sc.fc] ^ good[abc[i].sc.sc]) {
            ans = min(ans, abc[i].fc);
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        return 0;
    }
}