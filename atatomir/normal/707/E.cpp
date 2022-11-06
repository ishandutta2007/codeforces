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

#define maxN 2016

struct cell {
    int x, y;
    ll w;

    void read() {
        scanf("%d%d%lld\n", &x, &y, &w);
    }
};

int n, m, k, len, i, j, qq, q, x;
bool is_on[maxN];
vector<cell> Sn[maxN];
cell aux;

pair<int, int> wh[maxN][maxN][2];
char s[55];

int xx1, yy1, xx2, yy2;
vector<int> mv[maxN];



void add_edge(cell A, cell B, pair<int, int> to_add) {
    if (mp(A.x, A.y) > mp(B.x, B.y))
        swap(A, B);

    if (A.x == B.x)
        wh[A.x][A.y][0] = to_add;
    else
        wh[A.x][A.y][1] = to_add;
}

void extract_edge(const int& x, const int& y, const int& tp) {
    if (wh[x][y][tp].first)
        mv[wh[x][y][tp].first].pb(wh[x][y][tp].second);
}

bool is_in(const cell& who) {
    return (xx1 <= who.x && who.x <= xx2 && yy1 <= who.y && who.y <= yy2);
}

ll solve() {
    int i;
    ll ans = 0;

    for (i = 1; i <= k; i++) mv[i].clear();

    for (i = xx1; i <= xx2; i++) {
        extract_edge(i, yy1 - 1, 0);
        extract_edge(i, yy2, 0);
    }

    for (i = yy1; i <= yy2; i++) {
        extract_edge(xx1 - 1, i, 1);
        extract_edge(xx2, i, 1);
    }

    for (i = 1; i <= k; i++) {
        if (is_on[i] == false) continue;

        sort(mv[i].begin(), mv[i].end());
        mv[i].pb(Sn[i].size());

        for (j = 0; j < mv[i].size(); j++) {
            if (!is_in(Sn[i][ mv[i][j]  - 1])) continue;

            ans += Sn[i][ mv[i][j] - 1].w - (j == 0 ? 0 : Sn[i][ mv[i][j - 1] - 1].w);
        }
    }


    return ans;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= k; i++) {
        scanf("%d", &len);
        Sn[i].clear();
        is_on[i] = true;

        for (j = 1; j <= len; j++) {
            aux.read();
            Sn[i].pb(aux);
        }

        for (j = 1; j < len; j++) {
            add_edge(Sn[i][j - 1], Sn[i][j], mp(i, j));
            Sn[i][j].w += Sn[i][j - 1].w;
        }
    }


    scanf("%d\n", &q);
    for (int qq = 1; qq <= q; qq++) {
        scanf("%s", s + 1);
        if (s[1] == 'S') {
            scanf("%d\n", &x);
            is_on[x] ^= true;
        } else {
            scanf("%d%d%d%d\n", &xx1, &yy1, &xx2, &yy2);
            printf("%lld\n", solve());
        }
    }


    return 0;
}