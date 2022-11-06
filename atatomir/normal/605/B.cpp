#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, m, i , x, y, used;
vector< int > used_edge;
vector< int > fake_edge;

int w[maxN];
int ans_l[maxN], ans_r[maxN];

bool cmp(int a, int b) {
    return w[a] < w[b];
}

bool solve() {
    int set_nr;
    int ll, rr;
    int pos_used, pos_fake;

    set_nr = 1;
    ll = 1; rr = 2;
    pos_used = 0;
    pos_fake = 0;

    for (int kk = m; kk > 0; kk--) {
        int prov = 0;
        int val = 1000000001;

        if (pos_used != used_edge.size()) {
            prov = 1;
            val = w[ used_edge[pos_used] ];
        }

        if (pos_fake != fake_edge.size()) {
            if (w[ fake_edge[pos_fake] ] < val) {
                prov = 2;
                val = w[ fake_edge[pos_fake] ];
            }
        }

        if (prov == 1) {
            set_nr++;
            int id = used_edge[pos_used];
            pos_used++;

            ans_l[id] = 1;
            ans_r[id] = set_nr;
        } else {
            int id = fake_edge[pos_fake];
            pos_fake++;

            ll++;
            if (ll == rr) {
                rr++;
                ll = 2;
            }

            if (rr > set_nr)
                return false;
            ans_l[id] = ll;
            ans_r[id] = rr;
        }

    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &w[i], &used);
        if (used)
            used_edge.pb(i);
        else
            fake_edge.pb(i);
    }

    sort(used_edge.begin(), used_edge.end(), cmp);
    sort(fake_edge.begin(), fake_edge.end(), cmp);

    if (!solve()) {
        printf("-1");
        return 0;
    }

    for (i = 1; i <= m; i++)
        printf("%d %d\n", ans_l[i], ans_r[i]);

    return 0;
}