#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, m, len, leng;

struct sql {
    int k, in;
    vector<int> all;

    sql(int k, int in) : k(k), in(in) {}

    sql() {}

    void get() {
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            all.push_back(x - 1);
        }
    }
};

struct luc {
    int l, r, in;

    luc(int l, int r, int in) : l(l - 1), r(r - 1), in(in) {}

    luc() {}
};

struct omg {
    vector<int> all;
    int in, num;

    omg(int in, int num) : in(in), num(num) {}

    omg() {}

    void get() {
        for (int i = 0; i < 3; ++i) {
            int x;
            cin >> x;
            --x;
            all.push_back(x);
        }
    }
};

struct edge {
    int to, c, f = 0;
    edge *p = nullptr;

    edge(int to, int c) : to(to), c(c) {}

    edge() {}
};

map<string, int> delta;
vector<vector<edge *>> g;

void build(int v, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    {
        edge *tmp = new edge(delta["tree"] + 2 * v, INF);
        edge *tmp1 = new edge(delta["tree"] + v, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[delta["tree"] + v].push_back(tmp);
        g[delta["tree"] + 2 * v].push_back(tmp1);
    }
    {
        edge *tmp = new edge(delta["tree"] + 2 * v + 1, INF);
        edge *tmp1 = new edge(delta["tree"] + v, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[delta["tree"] + v].push_back(tmp);
        g[delta["tree"] + 2 * v + 1].push_back(tmp1);
    }

    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
}

void update(int v, int l, int r, int A, int B, int in) {
    if (l > B || A > r) return;
    if (A <= l && r <= B) {
        edge *tmp = new edge(delta["tree"] + v, 1);
        edge *tmp1 = new edge(delta["left"] + in, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[delta["left"] + in].push_back(tmp);
        g[delta["tree"] + v].push_back(tmp1);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * v, l, mid, A, B, in);
    update(2 * v + 1, mid + 1, r, A, B, in);
}

int get_in(int v, int l, int r, int i) {
    if (l > i || i > r) return -1;
    if (l == r) return v;
    int mid = (l + r) / 2;
    int kek = get_in(2 * v, l, mid, i);
    if (kek != -1) return kek;
    return get_in(2 * v + 1, mid + 1, r, i);
}

void update_sql(sql &a) {
    for (int i : a.all) {
        edge *tmp = new edge(delta["right"] + i, 1);
        edge *tmp1 = new edge(delta["left"] + a.in, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[delta["left"] + a.in].push_back(tmp);
        g[delta["right"] + i].push_back(tmp1);
    }
}

void update_omg(omg &a) {
    {
        {
            edge *tmp = new edge(delta["omg"] + a.num, 1);
            edge *tmp1 = new edge(0, 0);
            tmp->p = tmp1;
            tmp1->p = tmp;
            g[0].push_back(tmp);
            g[delta["omg"] + a.num].push_back(tmp1);
        }
        {
            edge *tmp = new edge(delta["left"] + a.in, 1);
            edge *tmp1 = new edge(delta["omg"] + a.num, 0);
            tmp->p = tmp1;
            tmp1->p = tmp;
            g[delta["omg"] + a.num].push_back(tmp);
            g[delta["left"] + a.in].push_back(tmp1);
        }
    }
    {
        {
            edge *tmp = new edge(delta["omg"] + a.num + 1, 1);
            edge *tmp1 = new edge(0, 0);
            tmp->p = tmp1;
            tmp1->p = tmp;
            g[0].push_back(tmp);
            g[delta["omg"] + a.num + 1].push_back(tmp1);
        }
        {
            edge *tmp = new edge(delta["left"] + a.in, 1);
            edge *tmp1 = new edge(delta["omg"] + a.num + 1, 0);
            tmp->p = tmp1;
            tmp1->p = tmp;
            g[delta["omg"] + a.num + 1].push_back(tmp);
            g[delta["left"] + a.in].push_back(tmp1);
        }
    }
    for (int i : a.all) {
        int in = delta["right"] + i;
        edge *tmp = new edge(in, 1);
        edge *tmp1 = new edge(delta["left"] + a.in, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[delta["left"] + a.in].push_back(tmp);
        g[in].push_back(tmp1);
    }
}

void update_k(vector<int> &a) {
    for (int i : a) {
        int in = delta["left"] + i;
        edge *tmp = new edge(in, 1);
        edge *tmp1 = new edge(0, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[0].push_back(tmp);
        g[in].push_back(tmp1);
    }
}

void update_s() {
    for (int i = 0; i < m; ++i) {
        int in = delta["right"] + i;
        edge *tmp = new edge(leng - 1, 1);
        edge *tmp1 = new edge(in, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[in].push_back(tmp);
        g[leng - 1].push_back(tmp1);
    }
}

void update_tree() {
    for (int i = 0; i < m; ++i) {
        int in = delta["tree"] + get_in(1, 0, len - 1, i);
        edge *tmp = new edge(delta["right"] + i, 1);
        edge *tmp1 = new edge(in, 0);
        tmp->p = tmp1;
        tmp1->p = tmp;
        g[in].push_back(tmp);
        g[delta["right"] + i].push_back(tmp1);
    }
}

int mash;
vector<int> dist, f;

int dfs(int v, int cmin) {
    if (v == leng - 1) return cmin;
    for (int u = f[v]; u < g[v].size(); ++u) {
        auto i = g[v][u];
        if (i->c - i->f < mash || dist[v] + 1 != dist[i->to]) ++f[v];
        else {
            int cha = dfs(i->to, min(cmin, i->c - i->f));
            if (cha != 0) {
                i->f += cha;
                i->p->f -= cha;
                return cha;
            } else {
                ++f[v];
            }
        }
    }
    return 0;
}

bool dinic() {
    dist.assign(leng, INF);
    dist[0] = 0;
    f.assign(leng, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i : g[now]) {
            if (i->c - i->f < mash) continue;
            if (dist[i->to] > dist[now] + 1) {
                dist[i->to] = dist[now] + 1;
                q.push(i->to);
            }
        }
    }
    if (dist[leng - 1] == INF) return false;
    while (dfs(0, INF)) {}
    return true;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> tree;
vector <bool> norm1;
int get(int v, int l, int r) {
    if (tree[v] == r - l + 1 || l >= m) return -1;
    if (l == r) {
        if (norm1[l]) return -1;
        return l;
    }
    int mid = (l + r) / 2;
    int ansl = get(2 * v, l, mid);
    if (ansl != -1) return ansl;
    return get(2 * v + 1, mid + 1, r);
}

void upd_tree(int v, int l, int r, int i, int x) {
    if (l > i || i > r) return;
    if (l == r) {
        tree[v] += x;
        return;
    }
    int mid = (l + r) / 2;
    upd_tree(2 * v, l, mid, i, x);
    upd_tree(2 * v + 1, mid + 1, r, i, x);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

pair <int, int> gr_tree(int v, int l, int r, int i) {
    if (v == i) return {l, r};
    if (l == r) return {-1, -1};
    int mid = (l + r) / 2;
    pair <int, int> tmp = gr_tree(2 * v, l, mid, i);
    if (tmp.first != -1) return tmp;
    return gr_tree(2 * v + 1, mid + 1, r, i);
}

signed main() {
    cin >> n >> m;
    vector<sql> all0;
    vector<luc> all1;
    vector<omg> all2;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int k;
            cin >> k;
            sql tmp(k, i);
            tmp.get();
            all0.push_back(tmp);
        } else if (type == 1) {
            int l, r;
            cin >> l >> r;
            luc tmp(l, r, i);
            all1.push_back(tmp);
        } else {
            omg tmp(i, all2.size());
            tmp.get();
            all2.push_back(tmp);
        }
    }
    len = 1 << (int) ceil(log2(m));
    delta["left"] = 1;
    delta["right"] = n + 1;
    delta["tree"] = n + m;
    delta["omg"] = n + m + 1 + 2 * len;
    leng = 2 + n + m + 2 * len + 2 * (int) all2.size();
    g.resize(leng);
    build(1, 0, len - 1);
    for (auto &i : all0) update_sql(i);
    for (auto &i : all1) update(1, 0, len - 1, i.l, i.r, i.in);
    for (auto &i : all2) update_omg(i);

    vector<bool> isiss(n);
    for (auto &i : all2) {
        isiss[i.in] = true;
    }
    vector<int> kek;
    for (int i = 0; i < n; ++i) {
        if (!isiss[i]) kek.push_back(i);
    }
    update_k(kek);
    update_s();
    update_tree();
    //mash = (1LL << (int) ceil(log2(INF)));
    mash = 1;
  //  while (mash > 0) {
    int kolr = 0;
    for (int i = 0; i < n; ++i) {
        kolr += g[i].size();
    }
        while (dinic()) {}
  //  }
    int maxflow = 0;
    for (auto i : g[0]) maxflow += i->f;
    cout << maxflow << "\n";
    vector<pair<int, int>> res;
    norm1.resize(m);
    for (auto &i : all2) {
        int kol = 0;
        for (auto &j : g[i.in + delta["left"]]) {
            if (j->f == 1) {
                norm1[j->to - delta["right"]] = true;
                res.emplace_back(i.in, j->to - delta["right"]);
                ++kol;
            }
        }
        if (kol == 1) {
            for (auto &j : g[i.in + delta["left"]]) {
                if (j->c == 1) {
                    if (norm1[j->to - delta["right"]]) continue;
                    norm1[j->to - delta["right"]] = true;
                    res.emplace_back(i.in, j->to - delta["right"]);
                    ++kol;
                    break;
                }
            }
        }
    }
    for (auto &i : all0) {
        for (auto j : g[delta["left"] + i.in]) {
            if (j->f == 1 && !norm1[j->to - delta["right"]]) {
                res.emplace_back(i.in, j->to - delta["right"]);
                norm1[j->to - delta["right"]] = true;
            }
        }
    }
    vector<pair<int, int>> drevo;
    for (auto &i : all1) {
        for (auto j : g[delta["left"] + i.in]) {
            if (j->f == 1) {
                drevo.emplace_back(i.in + delta["left"], j->to - delta["tree"]);
            }
        }
    }
    sort(drevo.begin(), drevo.end(), cmp);
    tree.resize(2 * len);
    for (auto i : drevo) {
        auto kek = gr_tree(1, 0, len - 1, i.second);
        int intree = get(i.second, kek.first, kek.second);
        if (intree == -1 || norm1[intree]) continue;
        upd_tree(1, 0, len - 1, intree, 1);
        res.emplace_back(i.first - delta["left"], intree);
    }
//    assert(res.size() == maxflow);
    for (auto i : res) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}