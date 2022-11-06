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
#define maxQ 100011

struct query {
    int op;
    int x, y;
};

int n, m, i, j, q, act;
query Q[maxQ];
vector<int> list[maxQ];
vector<int> rets[maxQ];
int ans[maxQ];
int wh[maxQ];

int mat[maxN][maxN];
int how[maxN];
int sh[maxN];
int cnt;

void solve(int node) {
    int bef;

    // set answers
    ans[node] = cnt;
    for (auto e : rets[node])
        ans[e] = cnt;

    for (int to : list[node]) {
        int x = Q[to].x;
        int y = Q[to].y;

        if (Q[to].op == 1) {
            bef = mat[x][y];
            if ((mat[x][y] ^ sh[x]) == 0)
                mat[x][y] ^= 1, cnt++, how[x]++;

            solve(to);

            if (mat[x][y] != bef) cnt--, how[x]--;
            mat[x][y] = bef;
        }

        if (Q[to].op == 2) {
            bef = mat[x][y];
            if ((mat[x][y] ^ sh[x]) == 1)
                mat[x][y] ^= 1, cnt--, how[x]--;

            solve(to);

            if (mat[x][y] != bef) cnt++, how[x]++;
            mat[x][y] = bef;
        }

        if (Q[to].op == 3) {
            sh[x] ^= 1;
            cnt += m - how[x] - how[x];
            how[x] = m - how[x];

            solve(to);

            how[x] = m - how[x];
            cnt -= m - how[x] - how[x];
            sh[x] ^= 1;
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    act = 0;
    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &Q[i].op);
        if (Q[i].op <= 2)
            scanf("%d%d", &Q[i].x, &Q[i].y);
        else
            scanf("%d", &Q[i].x);

        if (Q[i].op <= 3) {
            list[act].pb(i);
            act = i;
        } else {
            act = wh[Q[i].x];
            rets[act].pb(i);
        }

        wh[i] = act;
    }

    solve(0);
    for (i = 1; i <= q; i++)
        printf("%d\n", ans[i]);


    return 0;
}