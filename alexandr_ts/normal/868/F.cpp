#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 21;
const int N = 1e5 + 10;

ll a[N];
int n;
int tl = -1, tr = -1;
ll answ = 0;
int rpos[N], lpos[N];
ll cnt[N];
ll d[M][N];

ll cnt2[N];

ll calc(int l, int r) {
    if (tl == -1) {
        ll ans = 0;
        frab(i, l, r + 1)
            cnt2[a[i]] = 0;
        frab(i, l, r + 1) {
            cnt2[a[i]]++;
            ans += (cnt2[a[i]] - 1);
        }
        answ = ans, tl = l, tr = r;
        return ans;
    }
    ll ans = answ;
    if (l < tl) {
        for (int i = tl - 1; i >= l; i--) {
            cnt2[a[i]]++;
            ans += (cnt2[a[i]] - 1);
        }
    }
    if (r > tr) {
        for (int i = tr + 1; i <= r; i++) {
            cnt2[a[i]]++;
            ans += (cnt2[a[i]] - 1);
        }
    }

    if (l > tl) {
        for (int i = tl; i < l; i++) {
            ans -= (cnt2[a[i]] - 1);
            cnt2[a[i]]--;
        }
    }

    if (r < tr) {
        for (int i = tr; i > r; i--) {
            ans -= (cnt2[a[i]] - 1);
            cnt2[a[i]]--;
        }
    }

    tl = l, tr = r, answ = ans;
}

void solve(int m, int kleft, int kright, int jleft, int jright) {
    if (jleft > jright) return;
    int j = (jleft + jright) / 2;
    int ansk = kleft;
    if (kleft > kright) return;
    if (kleft <= min(kright, j)) {
        ll c = calc(kleft + 1, j);
        frab(k, kleft, min(kright, j) + 1) {
            if (d[m - 1][k] + c < d[m][j])
                d[m][j] = d[m - 1][k] + c, ansk = k;
            c -= (cnt2[a[k + 1]] - 1);
            tl++;
            answ = c;
            cnt2[a[k + 1]]--;
        }
    }
    solve(m, kleft, ansk, jleft, j - 1);
    solve(m, ansk, kright, j + 1, jright);
}

int mp1[N];

int main() {
    //freopen("a.in", "r", stdin);
    int K;
    //cin >> n >> m1;
    scanf("%d %d", &n, &K);
    frab(i, 1, 1 + n)
        scanf("%d", &a[i]);

    fill(rpos, rpos + n + 1, INF);
    fill(mp1, mp1 + n + 1, -1);
    for (int i = n; i >= 1; i--) {
        if (mp1[a[i]] != -1)
            rpos[i] = mp1[a[i]];
        mp1[a[i]] = i;
    }
    fill(mp1, mp1 + n + 1, -1);

    fill(lpos, lpos + n + 1, -INF);
    for (int i = 1; i <= n; i++) {
        if (mp1[a[i]] != -1)
            lpos[i] = mp1[a[i]];
        mp1[a[i]] = i;
    }

    frab(i, 0, K + 1)
        frab(j, 0, n + 1)
            d[i][j] = INF * INF;
    d[0][0] = 0;

    frab(m, 1, K + 1)
        solve(m, 0, n, 1, n);
//    fr(i, n + 1) cout << d[1][i] << " ";cout << endl;
//    fr(i, n + 1) cout << d[2][i] << " ";cout << endl;
    cout << d[K][n];
    //cout << calc(1, n) << endl;
}