#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e3 + 2;
const int N = 2e5 + 12;

//vector <pair <int, int> > l[N], r[N];

struct Q {
    int l, r, cost;
} a[N];

bool cmp1(Q a, Q b) {
    return a.l < b.l;
}

vector <Q> b[N];
vector <int> l[N], r[N];

bool cmp2(Q a, Q b) {
    if (a.r - a.l != b.r - b.l)
        return a.r - a.l < b.r - b.l;
    return a.l < b.l;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    //fill(l, l + N, -INF);
    //fill(r, r + N, INF);
    fr(i, n) {
        cin >> a[i].l >> a[i].r >> a[i].cost;
        int len = a[i].r - a[i].l + 1;
        b[len].pb(a[i]);
    }
    fr(i, N) {
        if (!b[i].size()) continue;
        sort(b[i].begin(), b[i].end(), cmp1);
        l[i].resize(b[i].size());
        r[i].resize(b[i].size());
        l[i].back() = b[i].back().cost;
        for (int j = (int)l[i].size() - 2; j >= 0; j--)
            l[i][j] = min(l[i][j + 1], b[i][j].cost);
        r[i][0] = b[i][0].cost;
        frab(j, 1, b[i].size())
            r[i][j] = min(r[i][j - 1], b[i][j].cost);
    }

    //sort(a, a + n, cmp2);

    int ans = INF;

    fr(i, N) {
        if (!b[i].size()) continue;
        int len = x - i;
        if (len <= 0) continue;
        int cl = 0, cr = 0;
        if (!b[len].size()) continue;
        fr(j, b[i].size()) {
            while (cl < b[len].size() && b[i][j].r >= b[len][cl].l)
                cl++;
            while (cr + 1 < b[len].size() && b[i][j].l > b[len][cr + 1].r)
                cr++;
            if (cl < b[len].size())
                ans = min(ans, b[i][j].cost + l[len][cl]);
            if (b[i][j].l > b[len][cr].r)
                ans = min(ans, b[i][j].cost + r[len][cr]);
        }
    }


    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}