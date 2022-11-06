#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, m, x, y, i;
vector<int> list[maxN];
vector<int> adj[maxN];

bool us[maxN];
int lvl[maxN], low[maxN];
stack< pair<int, int> > S;
vector<int> to_remove;

bool found_cycle;
bool us_cycle[maxN];
vector<int> cycle;

map< pair<int, int>, bool> used_edge;

bool found_way;
int deny;
vector<int> way;
vector<int> aux1, aux2;

bool way_used[maxN];



void give_solution(vector<int>& a, vector<int>& b, vector<int>& c) {
    printf("YES\n");

    printf("%d ", a.size());
    for (auto e : a) printf("%d ", e);
    printf("\n");

    printf("%d ", b.size());
    for (auto e : b) printf("%d ", e);
    printf("\n");

    printf("%d ", c.size());
    for (auto e : c) printf("%d ", e);
    printf("\n");

    exit(0);
}

void dfs_cycle(int node, int from) {
    us_cycle[node] = true;
    cycle.pb(node);

    for (auto to : adj[node]) {
        if (found_cycle) return;
        if (to == from) continue;

        if (!us_cycle[to]) {
            dfs_cycle(to, node);
            continue;
        }

        found_cycle = true;

        int pos;
        for (pos = 0; cycle[pos] != to; pos++) us_cycle[ cycle[pos] ] = false;
        for (int i = pos; i < cycle.size(); i++) cycle[i - pos] = cycle[i];
        cycle.resize(cycle.size() - pos);

        cycle.pb(cycle[0]);
        for (int i = 0; i + 1 < cycle.size(); i++)
            used_edge[mp(cycle[i], cycle[i + 1])] = used_edge[mp(cycle[i + 1], cycle[i])] = true;
        cycle.pop_back();

        return;
    }

    if (found_cycle) return;
    us_cycle[node] = false;
    cycle.pop_back();
}

void dfs_way(int node) {
    way.pb(node);
    way_used[node] = true;

    if (us_cycle[node]) {found_way = true; return;}

    for (int to : adj[node]) {
        if (to == deny) continue;
        if (way_used[to]) continue;

        if (!us_cycle[to]) {
            dfs_way(to);
            if (found_way) return;
            continue;
        }

        found_way = true;
        way.pb(to);
        return;
    }

    if (found_way) return;
    way.pop_back();
    way_used[node] = false;
}

void remove_cycle() {
    static int i;

    for (i = 0; i + 1 < cycle.size(); i++) {
        used_edge[mp(cycle[i], cycle[i + 1])] = used_edge[mp(cycle[i + 1], cycle[i])] = false;
        us_cycle[cycle[i]] = false;
    }
    used_edge[mp(cycle[0], cycle.back())] = used_edge[mp(cycle.back(), cycle[0])] = false;

    cycle.clear();
}

void solve_component(int x, int y) {
    int xx, yy, cnt_edges;
    cnt_edges = 0;
    to_remove.clear();

    //! get the edges of the component
    while (S.top() != mp(x, y)) {
        xx = S.top().first;
        yy = S.top().second;
        S.pop();

        to_remove.pb(xx); to_remove.pb(yy);
        adj[xx].pb(yy);
        adj[yy].pb(xx);
        cnt_edges++;
    }

    xx = x; yy = y; S.pop();
    to_remove.pb(xx); to_remove.pb(yy);
    adj[xx].pb(yy);
    adj[yy].pb(xx);
    cnt_edges++;

    if (to_remove.size() <= 2) {
        //! just an edge ... no solution
        for (auto e : to_remove)
            adj[e].clear();
        return;
    }

    //! find a cycle
    found_cycle = false;
    dfs_cycle(to_remove[0], 0);
    if (found_cycle == false) cerr << "Error no cycle found\n";

    if (cnt_edges == cycle.size()) {
        //! the whole component is a cycle... useless
        for (auto e : to_remove)
            adj[e].clear();
        remove_cycle();
        return;
    }

    //! now just find an unused edge
    pair<int, int> unused = mp(-1, -1);
    for (auto e : cycle) {
        for (auto to : adj[e]) {
            if (!used_edge[mp(e, to)]) {
                unused = mp(e, to);
                break;
            }
        }
        if (unused != mp(-1, -1)) break;
    }

    if (unused == mp(-1, -1)) cerr << "Error no unused edge found\n";

    //! find the third way
    way.clear();
    found_way = 0; deny = unused.first;
    way = {unused.first};
    dfs_way(unused.second);

    if (!found_way) cerr << "Error no path found\n";
    for (auto e : way) way_used[e] = false;

    //! build the solution
    int sz = cycle.size();
    int pos, pos2;
    for (pos = 0; cycle[pos] != unused.first; pos++) cycle.pb(cycle[pos]);

    for (pos2 = pos; cycle[pos2] != way.back(); pos2++) aux1.pb(cycle[pos2]);
    aux1.pb(way.back());

    aux2.pb(unused.first);
    for (i = cycle.size() - 1; cycle[i] != way.back(); i--) aux2.pb(cycle[i]);
    aux2.pb(way.back());

    give_solution(way, aux1, aux2);


    //! remove the edges
    for (auto e : to_remove)
        adj[e].clear();
}

void dfs(int node) {
    us[node] = true;
    low[node] = lvl[node];

    for (auto to : list[node]) {
        if (!us[to]) {
            S.push(mp(node, to));
            lvl[to] = lvl[node] + 1;
            dfs(to);
            low[node] = min(low[node], low[to]);
        } else {
            if (lvl[to] >= lvl[node] - 1) continue;

            low[node] = min(low[node], lvl[to]);
            S.push(mp(node, to));
            continue;
        }


        if (low[to] >= lvl[node]) {
            //! new biconnected component
            solve_component(node, to);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    to_remove.reserve(2 * m);
    for (i = 1; i <= n; i++)
        adj[i].reserve(list[i].size());

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        lvl[i] = 1;
        dfs(i);
    }

    printf("NO");


    return 0;
}