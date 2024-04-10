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

int n, i, j, x, y;
vector<int> list[maxN];
vector< pair<int, int> > ord;

int dad[maxN], cnt[maxN];
ll ans;

bool on[maxN];
ll act, bef;

ll compute(ll x) {
    return (x * (x + 1)) / 2LL;
}

int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

void add_node(int node) {
    act++;
    on[node] = true;

    for (auto to : list[node]) {
        if (on[to] == false) continue;

        int n1 = Find(node);
        int n2 = Find(to);

        if (n1 == n2) continue;
        act -= compute(cnt[n1]);
        act -= compute(cnt[n2]);
        dad[n2] = n1;
        cnt[n1] += cnt[n2];
        act += compute(cnt[n1]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        ord.pb(mp(x, i));
    }

    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    //! min max
    sort(ord.begin(), ord.end());
    memset(on, 0, sizeof(on));
    for (i = 1; i <= n; i++) cnt[i] = 1, dad[i] = i;
    act = 0;

    for (i = 0; i < ord.size(); i = j) {
        bef = act;

        for (j = i; j < ord.size(); j++) {
            if (ord[i].first != ord[j].first) break;
            add_node(ord[j].second);
        }

        ans += 1LL * ord[i].first * (act - bef);
    }

    //! max min
    reverse(ord.begin(), ord.end());
    memset(on, 0, sizeof(on));
    for (i = 1; i <= n; i++) cnt[i] = 1, dad[i] = i;
    act = 0;

    bef = 0;
    for (i = 0; i < ord.size(); i = j) {
        bef = act;

        for (j = i; j < ord.size(); j++) {
            if (ord[i].first != ord[j].first) break;
            add_node(ord[j].second);
        }

        ans -= 1LL * ord[i].first * (act - bef);
    }

    printf("%lld", ans);



    return 0;
}