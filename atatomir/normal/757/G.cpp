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

#define maxN 400011

struct edge {
    int x, y, w;
};

struct trie {
    int id;
    trie *dad;
    vector<trie*> list;
    ll prov, cnt, dp;

    trie(int _id, trie *_dad) {
        id = _id;
        dad = _dad;
        list.clear();
        cnt = prov = dp = 0;
    }
};

int n, q, i, x, y, w, cnt, R, t, l, r, v, a, b, c;
int aa[maxN];
vector<int> adj[maxN];
vector<edge> E;

bool dead[maxN];
vector< pair<int, int> > list[maxN];
int lvl[maxN], sub[maxN], dad[maxN];
vector<int> tree[maxN];
vector<ll> dist[maxN];

trie* Head[maxN];
ll last, ans;

void binar() {
    int i, j, new_nodes;
    vector<int> aux, edg;

    cnt = n;
    for (i = 1; i <= n; i++) {
        if (adj[i].size() <= 3) continue;

        new_nodes = adj[i].size() - 3;
        aux.pb(i);

        edg = adj[i];
        adj[i].clear();

        for (j = 1; j <= new_nodes; j++) {
            E.pb({aux.back(), ++cnt, 0});
            adj[aux.back()].pb(E.size() - 1);
            adj[cnt].pb(E.size() - 1);
            aux.pb(cnt);
        }

        for (j = 0; j < aux.size(); j++) {
            while (adj[ aux[j] ].size() < 3 && edg.size() > 0) {
                int e = edg.back();
                edg.pop_back();

                if (E[e].x == i) {
                    E[e].x = aux[j];
                } else {
                    E[e].y = aux[j];
                    swap(E[e].x, E[e].y);
                }

                adj[aux[j]].pb(e);
            }
        }
    }
}

void clean(vector< pair<int, int> >& v) {
    for (int i = 0; i < v.size(); i++) {
        if (dead[ v[i].first ]) {
            v[i] = v.back();
            v.pop_back();
            i--;
            continue;
        }
    }
}

void dfs(int node, int root) {

    clean(list[node]);
    sub[node] = 1;

    for (auto to: list[node]) {
        if (to.first == root) continue;
        dfs(to.first, node);
        sub[node] += sub[to.first];
    }
}

int dfs2(int node, int root, int target) {
    bool ok = true;

    for (auto to : list[node]) {
        if (to.first == root)
            continue;

        int ans = dfs2(to.first, node, target);
        if (ans) return ans;

        if (sub[to.first] > target / 2)
            ok = false;
    }

    if (target - sub[node] > target / 2)
        ok = false;

    if (ok) return node;
    return 0;
}

void dfs3(int node, int root, ll dst) {
    dist[node].pb(dst);

    for (auto to : list[node])
        if (to.first != root)
            dfs3(to.first, node, dst + to.second);
}

int get_centroid(int node, int act_lvl) {
    int target;

    dfs(node, 0);

    target = sub[node];
    node = dfs2(node, 0, target);

    dfs3(node, 0, 0);

    dead[node] = true;
    lvl[node] = act_lvl;
    for (auto to : list[node]) {
        int aux = get_centroid(to.first, act_lvl + 1);
        dad[aux] = node;
        tree[node].pb(aux);
    }

    return node;
}

trie* build(int node, trie* daddy) {
    trie* act = new trie(node, daddy);

    for (auto to : tree[node]) {
        act->list.pb(build(to, act));
    }

    return act;
}

trie* add_node(trie* from, int node) {
    int i, j, x;
    vector<int> way;
    vector<trie*> cop, cop2;
    trie* act, *down;

    way.clear();
    cop.clear();

    for (x = node; x != 0; x = dad[x])
        way.pb(x);
    reverse(way.begin(), way.end());

    cop.pb(from);
    for (i = 1; i < way.size(); i++) {
        x = way[i];
        act = cop.back();

        for (auto to : act->list)
            if (to->id == x)
                cop.pb(to);
    }

    cop2 = cop;
    for (i = 0; i < cop2.size(); i++) {
        cop2[i] = new trie(cop[i]->id, (i == 0 ? NULL : cop2[i - 1]));

        cop2[i]->cnt = cop[i]->cnt;
        cop2[i]->dp = cop[i]->dp;
        cop2[i]->prov = cop[i]->prov;
        cop2[i]->list = cop[i]->list;
    }

    for (i = 0; i + 1 < cop2.size(); i++) {
        for (j = 0; j < cop2[i]->list.size(); j++)
            if (cop2[i]->list[j]->id == cop2[i + 1]->id)
                cop2[i]->list[j] = cop2[i + 1];
    }

    act = cop2.back();
    act->cnt++;
    for (down = act, act = act->dad; act != NULL; down = act, act = act->dad) {
        act->dp += dist[node][lvl[act->id]];
        down->prov += dist[node][lvl[act->id]];
        act->cnt++;
    }

    return cop2[0];
}

ll query(trie* from, int node) {
    int i, j, x;
    vector<int> way;
    vector<trie*> cop;
    trie* act, *down;

    way.clear();
    cop.clear();

    for (x = node; x != 0; x = dad[x])
        way.pb(x);
    reverse(way.begin(), way.end());

    cop.pb(from);
    for (i = 1; i < way.size(); i++) {
        x = way[i];
        act = cop.back();

        for (auto to : act->list)
            if (to->id == x)
                cop.pb(to);
    }

    ll ans = cop.back()->dp;
    if (cop.size() == 1) return ans;

    for (down = cop.back(), cop.pop_back(), act = cop.back(); !cop.empty(); down = act, cop.pop_back(), act = cop.back()) {
        ans += (act->dp - down->prov) + (act->cnt - down->cnt) * dist[node][lvl[act->id]];
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%d", &aa[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &w);
        E.pb({x, y, w});
        adj[x].pb(E.size() - 1);
        adj[y].pb(E.size() - 1);
    }

    binar();
    for (auto e : E) {
        list[e.x].pb(mp(e.y, e.w));
        list[e.y].pb(mp(e.x, e.w));
    }

    R = get_centroid(1, 0);

    Head[0] = build(R, NULL);
    for (i = 1; i <= n; i++)
        Head[i] = add_node(Head[i - 1], aa[i]);

    for (i = 1; i <= q; i++) {
        scanf("%d", &t);

        if (t == 1) {
            scanf("%d%d%d", &a, &b, &c);
            last %= 1 << 30;
            l = last ^ a;
            r = last ^ b;
            v = last ^ c;

            ans = query(Head[r], v) - query(Head[l - 1], v);
            printf("%lld\n", ans);

            last = ans;
        } else {
            scanf("%d", &a);
            last %= 1 << 30;
            x = last ^ a;

            swap(aa[x], aa[x + 1]);
            Head[x] = add_node(Head[x - 1], aa[x]);
        }
    }



    return 0;
}