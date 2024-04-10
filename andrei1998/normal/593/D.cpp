#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

#define lint long long int
using namespace std;

const int NMAX = 200005;

pair <int, int> all_edges[NMAX];

struct path {
    vector <int> nodes;
    set <int> positives;

    int father = 0;
};

vector <path> paths;

int which_path[NMAX];
int which_pos[NMAX];

vector <pair <int, lint> > graph[NMAX];

int sz[NMAX];
int h[NMAX];
lint edge[NMAX];

void dfs (int node, int father) {
    int who = 0;
    int maximum = -1;

    sz[node] = 1;
    for (auto it: graph[node])
        if (it.first != father) {
            h[it.first] = 1 + h[node];
            edge[it.first] = it.second;

            dfs(it.first, node);

            sz[node] += sz[it.first];

            if (sz[it.first] > maximum) {
                maximum = sz[it.first];
                who = it.first;
            }
        }

    if (!who) {
        path p;
        p.nodes.push_back(node);
        which_path[node] = paths.size();

        paths.push_back(p);
    }
    else {
        which_path[node] = which_path[who];
        paths[which_path[node]].nodes.push_back(node);

        for (auto it: graph[node])
            if (it.first != father && it.first != who)
                paths[which_path[it.first]].father = node;
    }
}

inline void prepare_paths () {
    int j;
    for (int i = 0; i < paths.size(); ++ i) {
        reverse(paths[i].nodes.begin(), paths[i].nodes.end());
        for (j = 0; j < paths[i].nodes.size(); ++ j) {
            which_pos[paths[i].nodes[j]] = j;
            if (edge[paths[i].nodes[j]] > 1)
                paths[i].positives.insert(j);
        }

        //cout << "drumul " << i << endl;
        //for (auto it: paths[i].positives)
        //    cout << it << ' ';
        //cout << endl;
        //cout << paths[i].father << endl;

    }
}

inline void update (int node, lint val) {
    edge[node] = val;

    if (val == 1)
        paths[which_path[node]].positives.erase(which_pos[node]);
}

lint query (int a, int b, lint y) {
    //cout << "query " << a << ' ' << b << ' ' << y << endl;

    if (y == 0)
        return 0;

    set <int> :: iterator it;
    if (which_path[a] == which_path[b]) {
        //cout << "aici e delicat " << endl;
        if (h[a] < h[b])
            swap(a, b);

        if (a == b)
            return y;
        y /= edge[a];

        it = paths[which_path[a]].positives.lower_bound(which_pos[a]);
        if (it != paths[which_path[a]].positives.begin()) {
            -- it;
            if (h[paths[which_path[a]].nodes[*it]] > h[b])
                return query(paths[which_path[a]].nodes[*it] , b, y);
            else
                return y;
        }
        else
            return y;
    }
    else if (h[paths[which_path[a]].father] > h[paths[which_path[b]].father]) {
        //Urcam pe lantul lui a
        y /= edge[a];

        it = paths[which_path[a]].positives.lower_bound(which_pos[a]);
        if (it != paths[which_path[a]].positives.begin()) {
            -- it;
            return query(paths[which_path[a]].nodes[*it] , b, y);
        }
        else
            return query(paths[which_path[a]].father, b, y);
    }
    else {
        //cout << "urc b " << endl;
        //Urcam pe lantul lui b
        y /= edge[b];

        it = paths[which_path[b]].positives.lower_bound(which_pos[b]);
        if (it != paths[which_path[b]].positives.begin()) {
            -- it;
            return query(a, paths[which_path[b]].nodes[*it], y);
        }
        else
            return query(a, paths[which_path[b]].father, y);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int a, b;
    lint x;

    for (int i = 1; i < n; ++ i) {
        cin >> a >> b >> x;

        graph[a].push_back(make_pair(b, x));
        graph[b].push_back(make_pair(a, x));

        all_edges[i] = {a, b};
    }

    h[1] = 1;
    dfs(1, 0);

    prepare_paths();

    for (int i = 1; i < n; ++ i)
        if (h[all_edges[i].first] < h[all_edges[i].second])
            swap(all_edges[i].first, all_edges[i].second);

    int type;
    while (m --) {
        cin >> type >> a;

        if (type == 1) {
            cin >> b >> x;
            cout << query(a, b, x) << '\n';
        }
        else {
            cin >> x;
            update(all_edges[a].first, x);
        }
    }
    return 0;
}