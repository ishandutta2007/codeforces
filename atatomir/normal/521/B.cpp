#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define mod 1000000009

struct cube {
    int x, y, id;
};

int n, i;
cube c[maxN];
map< pair<int, int>, int > M;

vector<int> list[maxN], up[maxN];
int deg[maxN];

priority_queue<int, vector<int>, greater<int> > hmin;
priority_queue<int> hmax;
bool used[maxN];

int deny[maxN];

void clean_list(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        if (used[data[i]]) {
            data[i] = data.back();
            data.pop_back();
            i--;
            continue;
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &c[i].x, &c[i].y);
        c[i].id = i;
        M[mp(c[i].x, c[i].y)] = c[i].id;
    }

    for (i = 1; i <= n; i++) {
        int aux = M[mp(c[i].x - 1, c[i].y - 1)];
        if (aux) list[i].pb(aux), up[aux].pb(i), deg[aux]++;

        aux = M[mp(c[i].x, c[i].y - 1)];
        if (aux) list[i].pb(aux), up[aux].pb(i), deg[aux]++;

        aux = M[mp(c[i].x + 1, c[i].y - 1)];
        if (aux) list[i].pb(aux), up[aux].pb(i), deg[aux]++;
    }

    for (i = 1; i <= n; i++) {
        if (list[i].size() != 1) continue;
        deny[list[i][0]]++;
    }

    for (i = 1; i <= n; i++) {
        if (deny[i]) continue;
        hmin.push(i);
        hmax.push(i);
    }

    int node;
    ll ans = 0;

    for (i = 1; i <= n; i++) {
        if (i & 1) {
            while (used[hmax.top()] || deny[hmax.top()]) hmax.pop();
            node = hmax.top(); hmax.pop();
        } else {
            while (used[hmin.top()] || deny[hmin.top()]) hmin.pop();
            node = hmin.top(); hmin.pop();
        }

        used[node] = true;
        ans = (ans * n + node - 1) % mod;

        // recompute up
        clean_list(up[node]);
        for (auto e : up[node]) {
            clean_list(list[e]);

            if (list[e].size() == 1)
                deny[list[e][0]]++;
        }

        // recompute down
        clean_list(list[node]);
        if (list[node].size() == 1) {
            deny[list[node][0]]--;
            if (deny[list[node][0]] == 0) {
                hmax.push(list[node][0]);
                hmin.push(list[node][0]);
            }
        }
    }

    printf("%lld", ans);



    return 0;
}