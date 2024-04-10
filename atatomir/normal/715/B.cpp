#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024
#define inf (1LL << 60)
#define too_big (1000000000000000LL)

ll n, m, L, S, T, i, x, y, z;
vector< pair<ll, ll> > list[maxN];
vector< pair<ll, ll> > edges;
vector< pair< pair<ll, ll>, ll> > kn;
multiset< pair<ll, ll> > E;

ll dist[maxN];
priority_queue< pair<ll, ll> > H;

bool found = false;

void no_sol() {
    printf("NO");
    exit(0);
}

void print_known() {
    for (auto e : kn)
        printf("%lld %lld %lld\n", e.first.first - 1, e.first.second - 1, e.second);
}

void case_one() {
    ll i;

    for (i = 1; i <= n; i++) dist[i] = inf;
    dist[S] = 0;
    H.push(mp(0, S));

    while (!H.empty()) {
        ll node = H.top().second;
        ll cost = -H.top().first;
        H.pop();

        if (dist[node] != cost) continue;
        for (auto to : list[node]) {
            if (to.second == 0) continue;
            if (dist[to.first] <= dist[node] + to.second) continue;

            dist[to.first] = dist[node] + to.second;
            H.push(mp(-dist[to.first], to.first));
        }
    }

    if (dist[T] == inf) return;
    if (dist[T] < L) no_sol();
    if (dist[T] == L) {
        printf("YES\n");
        for (auto e : edges)
            printf("%lld %lld %lld\n", e.first - 1, e.second - 1, too_big);

        print_known();
        exit(0);
    }
}

void set_val(int a, int b, int delta) {
    for (int i = 0; i < list[a].size(); i++)
        if (list[a][i].first == b)
            list[a][i].second += delta;

    for (int i = 0; i < list[b].size(); i++)
        if (list[b][i].first == a)
            list[b][i].second += delta;
}

void case_two() {
    ll i;

    for (i = 1; i <= n; i++) dist[i] = inf;
    dist[S] = 0;
    H.push(mp(0, S));

    while (!H.empty()) {
        ll node = H.top().second;
        ll cost = -H.top().first;
        H.pop();

        if (dist[node] != cost) continue;
        for (auto to : list[node]) {
            to.second = max(to.second, 1LL);

            if (dist[to.first] <= dist[node] + to.second) continue;

            dist[to.first] = dist[node] + to.second;
            H.push(mp(-dist[to.first], to.first));
        }
    }

    if (dist[T] > L) no_sol();
    if (dist[T] == L) {
        found = true;
        return;
    }

    vector<ll> way = {};
    for (ll node = T; node != S; ) {
        way.pb(node);

        for (auto to : list[node]) {
            if (dist[to.first] != dist[node] - max(1LL, to.second)) continue;
            node = to.first;
            break;
        }
    }

    way.pb(S);
    //reverse(way.begin(), way.end());

    ll dif = L - dist[T];

    for (i = 1; i < way.size(); i++) {
        auto pp = mp(way[i - 1], way[i]);
        auto it = E.lower_bound(pp);

        if (it != E.end()) {
            if (*it == pp) {
                if (dif) set_val(pp.first, pp.second, +dif);
                //printf("%lld %lld %lld\n", pp.first - 1, pp.second - 1, 1 + dif);
                dif = 0;
                //E.erase(it);
            }
        }
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld%lld", &n, &m, &L, &S, &T);
    S++; T++; E.clear();
    for (i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        x++; y++;

        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));

        if (z == 0)
            edges.pb(mp(x, y));
        else
            kn.pb(mp(mp(x, y), z));

        if (z == 0) E.insert(mp(x, y)), E.insert(mp(y, x));
    }

    case_one();

    for (i = 1; i <= n; i++)
        for (ll j = 0; j < list[i].size(); j++)
            list[i][j].second = max(list[i][j].second, 1LL);

    int tr = m + 11;
    while (!found && --tr > 0)
        case_two();

    if (tr <= 0) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    for (i = 1; i <= n; i++)
        for (auto to : list[i])
            if (i < to.first)
                printf("%lld %lld %lld\n", i - 1, to.first - 1, to.second);



    return 0;
}