#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

struct frog {
    int id;
    ll pos, tongue, cnt;

    bool operator<(const frog& who)const {
        return pos < who.pos;
    }
};

int n, m, i, lim, pos, val;
frog F[maxN];
set< pair<ll, int> > S;
multiset< pair<ll, ll> > M;
pair<ll, ll> ans[maxN];



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &F[i].pos, &F[i].tongue);
        F[i].id = i, F[i].cnt = 0;
    }

    sort(F + 1, F + n + 1);

    lim = -1;
    for (i = 1; i <= n; i++) {
        if (F[i].pos + F[i].tongue <= lim) continue;
        lim = F[i].pos + F[i].tongue;
        S.insert(mp(F[i].pos + F[i].tongue, i));
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &pos, &val);

        auto e = S.lower_bound(mp(1LL * pos, -1));
        if (e == S.end()) {
            M.insert(mp(pos, val));
            continue;
        }
        if (F[e->second].pos > pos) {
            M.insert(mp(pos, val));
            continue;
        }

        int fr = e->second;
        ll ini = F[fr].pos + F[fr].tongue;
        F[fr].tongue += val;
        F[fr].cnt++;

        while (true) {
            auto e = M.lower_bound(mp(F[fr].pos, -1));
            if (e == M.end()) break;
            if (e->first > F[fr].pos + F[fr].tongue) break;
            F[fr].tongue += e->second;
            F[fr].cnt++;
            M.erase(e);
        }

        while (true) {
            auto e = S.lower_bound(mp(ini, -1));;
            if (e == S.end()) break;
            if (e->first > F[fr].pos + F[fr].tongue) break;
            S.erase(e);
        }

        S.insert(mp(F[fr].pos + F[fr].tongue, fr));
    }

    for (i = 1; i <= n; i++)
        ans[F[i].id] = mp(F[i].tongue, F[i].cnt);

    for (i = 1; i <= n; i++)
        printf("%lld %lld\n", ans[i].second, ans[i].first);

    return 0;
}