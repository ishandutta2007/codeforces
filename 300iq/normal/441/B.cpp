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


int type[3000 + 7];

bool cmp(pair <bool, int> a, pair <bool, int> b) {
    return a > b;
}

int main() {
    int n, v, a, b;
    scanf("%d%d", &n, &v);
    vector <pair <bool, int> > t[3000 + 7];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b); 
        t[a].pb({0, i});
        t[a + 1].pb({1, i});
        type[i] = b;
    }
    int ans = 0;
    int cur = v;
    for (int i = 1; i <= 3002; i++) {
        sort(all(t[i]), cmp);
        for (auto c : t[i]) {
            int was = min(type[c.sc], v);
            v -= was;
            ans += was;
            type[c.sc] -= was;
        }
        v = cur;
    }
    printf("%d\n", ans);
}