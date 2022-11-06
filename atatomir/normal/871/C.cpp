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

#define maxN 100011
#define mod 1000000007

int n, i, j, k;
pair<int, int> P[maxN];
vector<int> ord1, ord2;
vector<int> list[maxN];

bool us[maxN];
ll ans = 1;
ll edg, nd, aux;

vector<int> vx, vy;

bool cmp1(int a, int b) {
    return P[a] < P[b];
}

bool cmp2(int a, int b) {
    return mp(P[a].second, P[a].first) < mp(P[b].second, P[b].first);
}

void dfs(int node) {
    nd++;
    us[node] = true;
    vx.pb(P[node].first);
    vy.pb(P[node].second);

    edg += list[node].size();
    for (auto to : list[node])
        if (!us[to])
            dfs(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> P[i].first >> P[i].second;
        ord1.pb(i);
        ord2.pb(i);
    }

    sort(ord1.begin(), ord1.end(), cmp1);
    sort(ord2.begin(), ord2.end(), cmp2);

    for (i = 0; i < ord1.size(); i = j) {
        for (j = i; j < ord1.size(); j++)
            if (P[ord1[i]].first != P[ord1[j]].first)
                break;
        for (k = i + 1; k < j; k++) {
            list[ord1[k - 1]].pb(ord1[k]);
            list[ord1[k]].pb(ord1[k - 1]);
        }
    }

    for (i = 0; i < ord2.size(); i = j) {
        for (j = i; j < ord2.size(); j++)
            if (P[ord2[i]].second != P[ord2[j]].second)
                break;
        for (k = i + 1; k < j; k++) {
            list[ord2[k - 1]].pb(ord2[k]);
            list[ord2[k]].pb(ord2[k - 1]);
        }
    }

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        edg = 0; nd = 0;
        vx.clear(); vy.clear();
        dfs(i);

        sort(vx.begin(), vx.end());
        vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

        sort(vy.begin(), vy.end());
        vy.resize(unique(vy.begin(), vy.end()) - vy.begin());

        aux = 1;
        for (j = 1; j <= vx.size(); j++) aux = (aux * 2) % mod;
        for (j = 1; j <= vy.size(); j++) aux = (aux * 2) % mod;

        edg /= 2;
        if (edg == nd - 1)
            aux = (aux + mod - 1) % mod;

        ans = (ans * aux) % mod;
    }

    cout << ans;


    return 0;
}