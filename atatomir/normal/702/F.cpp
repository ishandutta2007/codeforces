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

#define maxN 200011

const int limit = 500;

struct query {
    int money, id;

    bool operator<(const query& who)const {
        return money < who.money;
    }
    bool operator<(const int& who)const {
        return money < who;
    }
};

struct intr {
    int l, r, bought, down;
};



int n, m, i, j, x, pos;
pair<int, int> T[maxN];
query Q[maxN];
vector<intr> work;

int ans[maxN];


void rebuild() {
    int i;

    for (auto e : work)
        for (i = e.l; i <= e.r; i++)
            ans[Q[i].id] += e.bought, Q[i].money -= e.down;

    sort(Q + 1, Q + m + 1);

    work.clear();
    work.pb({1, m, 0, 0});
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &T[i].second, &T[i].first);
        T[i].first *= -1;
    }
    sort(T + 1, T + n + 1);

    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &x);
        Q[i] = {x, i};
    }

    rebuild();

    for (i = 1; i <= n; i++) {
        int pay = T[i].second;

        int def = work.size();
        for (j = 0; j < def; j++) {
            int l = work[j].l;
            int r = work[j].r;

            if (Q[l].money - work[j].down >= pay) {
                // all interval
                work[j].bought++;
                work[j].down += pay;
                continue;
            }

            if (Q[r].money - work[j].down >= pay) {
                // partial

                pos = lower_bound(Q + l, Q + r + 1, pay + work[j].down) - Q;
                work.pb({pos, work[j].r, work[j].bought + 1, work[j].down + pay});
                work[j].r = pos - 1;
            }
        }

        if (work.size() > limit)
            rebuild();
    }

    rebuild();
    for (i = 1; i <= m; i++)
        printf("%d ", ans[i]);

    return 0;
}