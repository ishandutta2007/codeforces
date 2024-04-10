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

#define maxN 1000011

int n, m, i, j;
int v[maxN];
pair<int, int> Q[maxN];
ll limit;

vector< pair<ll, ll> > work, coup;
ll ans;
ll sol[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    scanf("%d", &m);
    for (i = 1; i <= m; i++) scanf("%d", &Q[i].first), Q[i].second = i;

    sort(v + 1, v + n + 1);
    sort(Q + 1, Q + m + 1);

    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n && v[i] == v[j]; j++);
        work.pb(mp(v[i], j - i ));
    }
    limit = Q[m].first;

    for (i = 0; i < work.size(); i++) {
        if (1LL * work[i].first * work[i].first < limit && work[i].second > 1)
            coup.pb(mp(work[i].first * work[i].first, 1LL * work[i].second * (work[i].second - 1)));

        for (j = i + 1; j < work.size(); j++)
            if (1LL * work[i].first * work[j].first < limit)
                coup.pb(mp(work[i].first * work[j].first, 2LL * work[i].second * work[j].second));
    }

    ans = 1LL * n * (n - 1);
    for (auto e : coup)
        ans -= e.second;

    sort(coup.begin(), coup.end());

    for (i = m; i > 0; i--) {
        while (coup.size() > 0) {
            if (Q[i].first > coup.back().first) break;
            ans += coup.back().second;
            coup.pop_back();
        }

        sol[ Q[i].second ] = ans;
    }

    for (i = 1; i <= m; i++)
        printf("%lld\n", sol[i]);


    return 0;
}