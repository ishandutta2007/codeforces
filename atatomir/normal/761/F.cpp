#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024
#define maxK 300011
#define sigma 26
#define add(mm, rr, vv) mm[rr.x1][rr.y1] += vv, mm[rr.x2 + 1][rr.y1] -= vv, mm[rr.x1][rr.y2 + 1] -= vv, mm[rr.x2 + 1][rr.y2 + 1] += vv
#define simp_form(mm) for (int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) mm[i][j] += mm[i - 1][j] + mm[i][j - 1] - mm[i - 1][j - 1];
#define form(mm) for (int rep = 0; rep < 2; rep++) simp_form(mm);
#define get_rect(mm, R) (mm[R.x2][R.y2] - mm[R.x1 - 1][R.y2] - mm[R.x2][R.y1 - 1] + mm[R.x1 - 1][R.y1 - 1])

struct rect {
    int x1, y1, x2, y2;
    ll ans;
};

int n, m, i, j, k;
char mat[maxN][maxN];
vector<rect> R[sigma];
rect aux;
char col;

ll lqcount[maxN][maxN];
ll rqcount[maxN][maxN];
ll lqsum[maxN][maxN];
ll rqsum[maxN][maxN];

ll _lqcount[maxN][maxN];
ll _rqcount[maxN][maxN];
ll _lqsum[maxN][maxN];
ll _rqsum[maxN][maxN];

ll diff[maxN][maxN];
ll _diff[maxN][maxN];

ll actcount[maxN][maxN];

ll global[maxN][maxN];

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

void solve(int tp) {
    int i, j;

    memset(actcount, 0, sizeof(actcount));
    for (auto e : R[tp]) {
        add(actcount, e, +1);

        add(lqcount, e, +1);
        add(lqsum, e, tp);

        add(rqcount, e, -1);
        add(rqsum, e, -tp);
    }

    memcpy(_lqcount, lqcount, sizeof(lqcount));
    memcpy(_rqcount, rqcount, sizeof(rqcount));
    memcpy(_lqsum, lqsum, sizeof(lqsum));
    memcpy(_rqsum, rqsum, sizeof(rqsum));

    simp_form(actcount);
    form(_lqcount);
    form(_rqcount);
    form(_lqsum);
    form(_rqsum);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            diff[i][j] += (R[tp].size() - actcount[i][j]);

            if (mat[i][j] != 'a' + tp)
                global[i][j] += actcount[i][j] * abss(mat[i][j] - 'a' - tp);
        }
    }

    for (i = 0; i < R[tp].size(); i++) {
        aux = R[tp][i];

        R[tp][i].ans += get_rect(_lqcount, aux) * tp - get_rect(_lqsum, aux);
        R[tp][i].ans += get_rect(_rqsum, aux) - get_rect(_rqcount, aux) * tp;
    }

}

void solve2(int tp) {
    int i, j;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            _diff[i][j] = diff[i][j] * abss(tp - (mat[i][j] - 'a'));

    simp_form(_diff);

    for (i = 0; i < R[tp].size(); i++) {
        aux = R[tp][i];

        R[tp][i].ans += get_rect(_diff, aux);
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n", &n, &m, &k);
    for (i = 1; i <= n; i++)
        scanf("%s\n", mat[i] + 1);

    if (k == 1) {
        printf("0");
        return 0;
    }

    aux.ans = 0;

    for (i = 1; i <= k; i++) {
        scanf("%d%d%d%d %c", &aux.x1, &aux.y1, &aux.x2, &aux.y2, &col);
        R[col - 'a'].pb(aux);

        add(rqcount, aux, +1);
        add(rqsum, aux, col - 'a');
    }

    for (col = 'a'; col <= 'z'; col++)
        solve(col - 'a');

    simp_form(global);

    for (col = 'a'; col <= 'z'; col++)
        solve2(col - 'a');

    ll ans = 1LL << 60;

    for (int tp = 0; tp < sigma; tp++) {
        for (auto &e : R[tp]) {
            e.ans += global[n][m] - get_rect(global, e);
            ans = min(ans, e.ans);
        }
    }

    printf("%lld", ans);

    return 0;
}