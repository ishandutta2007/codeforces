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

#define maxN 333

const int def = 100000;

int n, i, j, x, S, D, ans;
vector< pair<int, int> > le, ri;
bool ciur[def + 11];

vector<int> list[maxN];
bool us[maxN];

map<int, bool> M;
vector<int> adj[maxN];

vector< vector<int> > sol;
vector<int> aux;

void pre() {
    ll i, j;

    for (i = 2; i <= def; i++) {
        if (ciur[i]) continue;
        for (j = i * i; j <= def; j += i) ciur[j] = true;
    }
}

void no_sol() {
    printf("Impossible");
    exit(0);
}

bool dfs(int node) {
    us[node] = true;
    if (node == D) return true;

    for (int i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (us[to]) continue;
        if (dfs(to)) {
            swap(list[node][i], list[node].back());
            list[node].pop_back();
            list[to].pb(node);
            return true;
        }
    }

    return false;
}

void dfs2(int node) {
    us[node] = true;
    aux.pb(node);

    for (auto to : adj[node])
        if (!us[to])
            dfs2(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x % 2)
            le.pb(mp(x, i));
        else
            ri.pb(mp(x, i));
    }

    if (le.size() * ri.size() == 0) no_sol();

    S = 1; D = 2;
    for (i = 1; i <= le.size(); i++) list[S].pb(2 + i), list[S].pb(2 + i);
    for (i = 1; i <= le.size(); i++) {
        for (j = 1; j <= ri.size(); j++) {
            if (ciur[le[i - 1].first + ri[j - 1].first] == false) {
                list[2 + i].pb(2 + le.size() + j);
            }
        }
    }
    for (i = 1; i <= ri.size(); i++) list[2 + le.size() + i].pb(D), list[2 + le.size() + i].pb(D);

    bool ok = true;
    while (ok) {
        ok = false;
        memset(us, 0, sizeof(us));

        while (dfs(S)) {
            ans++;
            ok = true;
            us[D] = false;
        }
    }

    if (ans != n) no_sol();
    for (i = 1; i <= le.size(); i++) {
        M.clear();
        for (auto to : list[2 + i])
            M[to] = true;

        for (j = 1; j <= ri.size(); j++) {
            if (ciur[le[i - 1].first + ri[j - 1].first]) continue;
            if (M[2 + le.size() + j] == false) {
                adj[le[i - 1].second].pb(ri[j - 1].second);
                adj[ri[j - 1].second].pb(le[i - 1].second);
            }
        }
    }

    memset(us, 0, sizeof(us));
    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        aux.clear();
        dfs2(i);
        sol.pb(aux);
    }

    printf("%d\n", sol.size());
    for (auto e : sol) {
        printf("%d ", e.size());
        for (auto ee : e)
            printf("%d ", ee);
        printf("\n");
    }


    return 0;
}