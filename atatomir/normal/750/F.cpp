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

#define maxN 155

int t, ti;
int h, i, n;
vector<int> adj[maxN];
bool us[maxN];
int questions;

void give_solution(int ans);


vector<int> ask(int x) {
    int k, i, R;
    vector<int> aux;

    if (us[x])
        return adj[x];
    else
        us[x] = true;

    if (++questions == 17) give_solution(x);

    R = x;
    printf("? %d\n", R);
    fflush(stdout);

    aux.clear();
    scanf("%d", &k);
    for (i = 1; i <= k; i++) scanf("%d", &x), aux.pb(x);
    adj[R] = aux;

    if (k == 2) // found the root
        give_solution(R);

    return aux;
}

void get_way(int node, vector<int>& way) {
    way.clear();
    ask(node);

    way.pb(node);
    while (adj[way.back()].size() != 1) {
        for (auto e : adj[way.back()])
            if (!us[e])
                node = e;

        ask(node);
        way.pb(node);
    }

    reverse(way.begin(), way.end());
}

void balance(vector<int>& le, vector<int>& ri) {
    while (le.size() > ri.size()) {
        le.pop_back();
        ri.pb(le.back());
    }

    swap(le, ri);
    while (le.size() > ri.size()) {
        le.pop_back();
        ri.pb(le.back());
    }
}

void dfs(int node, int dist) {
    ask(node);

    for (auto e : adj[node])
        if (!us[e] && dist > 0)
            dfs(e, dist - 1);
}

void solve() {
    int i, node, act_level, len;
    vector<int> le, ri;

    questions = 0;

    scanf("%d", &h);
    n = (1 << h) - 1;
    if (h == 0) exit(0);

    for (i = 1; i <= n; i++) adj[i].clear();
    memset(us, 0, sizeof(us));

    node = 1; ask(node);
    if (adj[node].size() == 1) {
        le = {node};
        ri = {node};
    } else {
        get_way(node, le);
        get_way(node, ri);
        balance(le, ri);
    }

    node = le.back();
    act_level = h - le.size() + 1;

    while (act_level > 3) {
        // go up
        for (auto e : adj[node]) {
            if (!us[e]) {
                node = e;
                break;
            }
        }

        ask(node);
        le.pb(node);
        act_level = h - le.size() + 1;

        if (act_level == 3) break;

        // find a new way
        get_way(node, ri);
        balance(le, ri);

        // get LCA
        node = le.back();
        act_level = h - le.size() + 1;
    }

    // found the solution
    if (act_level == 1)
        give_solution(node);

    dfs(node, 2);
}

void give_solution(int ans) {
    printf("! %d\n", ans);
    fflush(stdout);

    if (ti == t)
        exit(0);
    ti++;
    solve();
}

int main()
{

    scanf("%d", &t);
    ti = 1;
    solve();


    return 0;
}