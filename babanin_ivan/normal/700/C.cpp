#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

struct edge {
    int from, to, w, id;
    edge() {}
    edge(int from, int to, int w, int id):from(from),to(to),id(id),w(w){}
    void scan(int _id) {
        id = _id;
        cin >> from >> to >> w;
        --from;
        --to;
    }
    edge swap() {
        return edge(to, from, w, id);
    }
};

set <int> not_allowed;
vector <edge> e;
vector <vector <edge> > g;
int n, m;
int s, t;

vector <int> find_path(int start, int end, bool &found) {
    queue <int> q;
    vector <pair <int, int>> w_id(n);
    vector <int> used(n, 0);

    q.push(start);
    used[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (edge go: g[v]) {
            if (not_allowed.count(go.id)) {
                continue;
            }
            if (used[go.to]) {
                continue;
            }
            used[go.to] = 1;
            q.push(go.to);
            w_id[go.to] = mp(go.id, v);
        }
    }
    if (!used[end]) {
        found = false;
        return vector<int>();
    }
    found = true;

    vector <int> result;
    int curv = end;
    while (curv != start) {
        result.push_back(w_id[curv].first);
        curv = w_id[curv].second;
    }

    return result;
}

void dfs(int v, int& cur_time, vector<int>&tin, vector <int>& fup, vector <int>& is_bridge, int parent_id=-1) {
    ++cur_time;
    fup[v] = tin[v] = cur_time;

    for (edge go: g[v]) {
        if (not_allowed.count(go.id)) {
            continue;
        }
        if (go.id == parent_id) {
            continue;
        }

        if (tin[go.to] == -1) {
            dfs(go.to, cur_time, tin, fup, is_bridge, go.id);
            if (fup[go.to] > tin[v]) {
                is_bridge[go.id] = true;
            }
            fup[v] = min(fup[v], fup[go.to]);
        }
        else {
            fup[v] = min(fup[v], tin[go.to]);
        }
    }
}

vector <int> find_bridges() {
    vector <int> tin(n, -1);
    vector <int> fup(n, -1);
    vector <int> is_bridge(m, 0);
    int cur_time = 0;

    for (int i = 0; i < n; ++i) {
        if (tin[i] < 0) {
            dfs(i, cur_time, tin, fup, is_bridge);
        }
    }

    return is_bridge;
}

void solve() {

    cin >> n >> m >> s >> t;
    --s;
    --t;

    e.resize(m);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        e[i].scan(i);
        g[e[i].from].push_back(e[i]);
        g[e[i].to].push_back(e[i].swap());
    }

    int cur_ans = -1;
    vector <int> cur_ans_ids;

    bool was_found;
    vector <int> some_way_ids = find_path(s, t, was_found);
    if (!was_found) {
        cur_ans = 0;
        cur_ans_ids = {};
    }
    else {
        vector <int> is_bridge = find_bridges();
        for (int some_id: some_way_ids) {
            if (is_bridge[some_id]) {
                if (cur_ans == -1 || cur_ans > e[some_id].w) {
                    cur_ans = e[some_id].w;
                    cur_ans_ids = {some_id};
                }
            }
            else {
                not_allowed.insert(some_id);

                bool without_id_exist;
                vector<int> some_path_without_id = find_path(s, t, without_id_exist);
                assert(without_id_exist);
                vector <int> bridges_without_id = find_bridges();
                for (int some_some_id: some_path_without_id) {
                    if (bridges_without_id[some_some_id]) {
                        if (cur_ans == -1 || cur_ans > e[some_id].w + e[some_some_id].w) {
                            cur_ans = e[some_id].w + e[some_some_id].w;
                            cur_ans_ids = {some_id, some_some_id};
                        }
                    }
                }

                not_allowed.clear();
            }
        }
    }

    cout << cur_ans << endl;
    if (cur_ans >= 0) {
        cout << cur_ans_ids.size() << endl;
        for (int x: cur_ans_ids) {
            cout << x + 1 << " ";
        }
    }

}