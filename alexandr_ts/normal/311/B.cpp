#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

const int N = 1e5 + 10;
const int P = 103;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;

ll di[N];
ll a[N];
ll pref[N];
pl begl = mp(INF, INF * INF);
vector <pl> p[P];
vector <pl> l[P];

inline bool ptAbove(pl l, pl p) {
    return l.first * p.first + l.second < p.second;
}

inline pl inter(pl l1, pl l2) {
    ld x = (l1.second - l2.second) / (l2.first - l1.first);
    return {x, l2.first * x + l2.second};
}

inline void add(ll k, ll b, int i) {
    pl newl = mp(k, b);
    while (p[i].size() && ptAbove(newl, p[i].back())) {
        p[i].pop_back();
        l[i].pop_back();
    }
    p[i].pb(inter(l[i].back(), newl));
    l[i].pb(newl);
}

inline ll calc(pl l, ll x) {
    return llroundl(l.first * x + l.second);
}

inline ll get(ll x, int i) {
    int i1 = lower_bound(p[i].begin(), p[i].end(), mp((ld)x, (ld)-INF * INF)) - p[i].begin();
    return calc(l[i][i1], x);
}

ll solve(int m, int p1) {
    for (int i = 0; i <= p1 + 1; i++) {
        p[i].clear();
        l[i] = {begl};
    }
    add(0, 0, 1);
    ll ans;

    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= p1; i++) {
            ans = a[j] * j - pref[j] + get(a[j], i);
            add(-j, pref[j] + ans, i + 1);
        }
    }
    return ans;
}

int main() {
    int n, m, p1, tr;
    scanf("%d %d %d", &n, &m, &p1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &tr);
        di[i + 1] = di[i] + tr;
    }

    for (int i = 0; i < m; i++) {
        int h, t;
        scanf("%d %d", &h, &t);
        a[i + 1] = t - di[h - 1];
    }

    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
        pref[i] = pref[i - 1] + a[i];

    cout << solve(m, p1) << endl;
}