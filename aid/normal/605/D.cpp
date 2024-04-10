#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    int x, y, id, pr, mx, my, mid;
    Node *l, *r;

    Node(int _x, int _y, int _id): x(_x), y(_y), id(_id),
                                   pr((rand() << 15) + rand()),
                                   mx(_x), my(_y), mid(_id), l(0), r(0) {}
};

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int x[MAXN], y[MAXN], needx[MAXN], needy[MAXN], d[MAXN], par[MAXN];

void recalc(Node *v) {
    v->mx = v->x;
    v->my = v->y;
    v->mid = v->id;
    if(v->l && v->l->my > v->my) {
        v->mx = v->l->mx;
        v->my = v->l->my;
        v->mid = v->l->mid;
    }
    if(v->r && v->r->my > v->my) {
        v->mx = v->r->mx;
        v->my = v->r->my;
        v->mid = v->r->mid;
    }
}

Node *ctmerge(Node *l, Node *r) {
    if(!l)
        return r;
    if(!r)
        return l;
    if(l->pr < r->pr) {
        l->r = ctmerge(l->r, r);
        recalc(l);
        return l;
    }
    else {
        r->l = ctmerge(l, r->l);
        recalc(r);
        return r;
    }
}

pair<Node *, Node *> ctsplit(Node *v, int x, int y, int id) {
    if(!v)
        return pair<Node *, Node *>();
    if(v->x < x || (v->x == x && (v->y < y || (v->y == y && v->id < id)))) {
        pair<Node *, Node *> p = ctsplit(v->r, x, y, id);
        v->r = p.first;
        recalc(v);
        return make_pair(v, p.second);
    }
    else {
        pair<Node *, Node *> p = ctsplit(v->l, x, y, id);
        v->l = p.second;
        recalc(v);
        return make_pair(p.first, v);
    }
}

Node *ctadd(Node *root, Node *node) {
    pair<Node *, Node *> p = ctsplit(root, node->x, node->y, node->id);
    return ctmerge(ctmerge(p.first, node), p.second);
}

Node *ctdel(Node *root, int id) {
    pair<Node *, Node *> p0 = ctsplit(root, x[id], y[id], id),
        p1 = ctsplit(p0.second, x[id], y[id], id + 1);
    return ctmerge(p0.first, p1.second);
}

pair<int, Node *> ctget(Node *root, int x, int y) {
    pair<Node *, Node *> p = ctsplit(root, x, -1, -1);
    if(!p.second || p.second->my < y) {
        root = ctmerge(p.first, p.second);
        return make_pair(-1, root);
    }
    int id = p.second->mid;
    root = ctmerge(p.first, p.second);
    return make_pair(id, ctdel(root, id));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(16743671);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> needx[i] >> needy[i] >> x[i] >> y[i];
    needx[n] = 0;
    needy[n] = 0;
    x[n] = 0;
    y[n] = 0;
    n++;
    Node *root = 0;
    for(int i = 0; i < n; i++)
        if(i != n - 2)
            root = ctadd(root, new Node(x[i], y[i], i));
    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[n - 2] = 0;
    queue<int> q;
    q.push(n - 2);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        while(true) {
            pair<int, Node *> p = ctget(root, needx[v], needy[v]);
            root = p.second;
            int u = p.first;
            if(u == -1)
                break;
            d[u] = d[v] + 1;
            par[u] = v;
            q.push(u);
        }
    }
    if(d[n - 1] == INF)
        cout << -1 << '\n';
    else {
        cout << d[n - 1] << '\n';
        for(int v = n - 1; v != n - 2; v = par[v])
            cout << par[v] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}