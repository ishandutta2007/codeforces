#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011
#define inf (1LL << 60)

struct op {
    int tp;
    int a, b, x;
    int id;

    void read() {
        scanf("%d", &tp);

        if (tp == 1)
            scanf("%d%d", &a, &b);
        else
            scanf("%d", &x);
    }
};


int n, i, bucket_size;
op Q[maxN];

map< pair<int, int>, int> M;
vector< pair<int, int> > lines;
int cnt[maxN];

vector<int> to_process;
ll ans[maxN];


void hull_and_solve(int l, int r) {
    static vector< pair<int, int> > work;
    static vector< pair<ll, int> > hull;
    ll a1, a2, b1, b2, lmt;
    int i;

    work.clear();
    for (i = 0; i < lines.size(); i++)
        if (cnt[i])
            work.pb(lines[i]);

    if (work.empty()) return;
    hull = {mp(-inf, 0)};

    for (i = 1; i < work.size(); i++) {
        if (work[hull.back().second].first == work[i].first) {
            hull[ hull.size() - 1 ].second = i;
            continue;
        }

        a2 = work[i].first;
        b2 = work[i].second;

        while (hull.size() > 0) {
            a1 = work[hull.back().second].first;
            b1 = work[hull.back().second].second;

            lmt = (b1 - b2 + a2 - a1 - 1) / (a2 - a1);
            if (lmt > hull.back().first) break;
            hull.pop_back();
        }

        hull.pb(mp(lmt, i));
    }

    for (i = l; i <= r; i++) {
        if (Q[i].tp != 3) continue;

        int pos = upper_bound(hull.begin(), hull.end(), mp(1LL * Q[i].x, n + 1)) - hull.begin();
        pos--;

        ans[i] = 1LL * work[ hull[pos].second ].first * Q[i].x + 1LL * work[ hull[pos].second ].second;
    }
}

void solve_bucket(int l, int r) {
    int i;

    // get static lines
    to_process.clear();
    for (i = l; i <= r; i++) {
        if (Q[i].tp == 3) {
            ans[i] = -inf;
            continue;
        }

        if (Q[i].tp == 1) {
            to_process.pb(i);
            continue;
        }

        to_process.pb(Q[i].x);
        if (Q[i].x < l)
            cnt[ Q[ Q[i].x ].id ]--;
    }

    // solve queries for static lines
    hull_and_solve(l, r);

    // roll back
    for (i = l; i <= r; i++)
        if (Q[i].tp == 2)
            if (Q[i].x < l)
                cnt[ Q[ Q[i].x ].id ]++;

    // brute force for dynamic lines
    for (i = l; i <= r; i++) {
        if (Q[i].tp == 1) {
            cnt[Q[i].id]++;
            continue;
        }

        if (Q[i].tp == 2) {
            cnt[ Q[ Q[i].x ].id ]--;
            continue;
        }

        for (auto e : to_process) {
            if (cnt[Q[e].id] == 0) continue;

            ans[i] = max(ans[i], 1LL * Q[e].a * Q[i].x + 1LL * Q[e].b);
        }

        if (ans[i] == -inf)
            printf("EMPTY SET\n");
        else
            printf("%lld\n", ans[i]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    // read data
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        Q[i].read();

        if (Q[i].tp == 1)
            lines.pb(mp(Q[i].a, Q[i].b));
    }

    // get the id of insert operations
    sort(lines.begin(), lines.end());
    lines.resize(unique(lines.begin(), lines.end()) - lines.begin());

    M.clear();
    for (i = 0; i < lines.size(); i++)
        M[lines[i]] = i;
    for (i = 1; i <= n; i++)
        if (Q[i].tp == 1)
            Q[i].id = M[mp(Q[i].a, Q[i].b)];

    // solve buckets of queries
    bucket_size = 5 * sqrt(n);

    for (i = 1; i <= n; i += bucket_size)
        solve_bucket(i, min(n, i + bucket_size - 1));

    return 0;
}