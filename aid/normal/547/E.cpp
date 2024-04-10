#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    map<char, Node *> go;
    int l, r;
    Node *p, *link;
    vector<int> t;

    Node(int _l, int _r, Node *_p): l(_l), r(_r), p(_p), link(0) {}
};

struct StNode {
    int val;
    StNode *l, *r;

    StNode() {}

    StNode(StNode *_l, StNode *_r): val((_l? _l->val : 0) + (_r? _r->val : 0)),
                              l(_l), r(_r) {}

    StNode(int _val): val(_val), l(0), r(0) {}
};

const int MAXM = 400 * 1000 + 5;
int l[MAXM], r[MAXM], sid[MAXM], n, curSuf, freeNode;
StNode *st[MAXM], nodes[20 * MAXM];
pair<int, int> p[MAXM];
string t[MAXM], s;
vector<int> leafs;

Node *splitEdge(Node *v, int pos) {
    Node *res = new Node(v->l, pos, v->p);
    v->p->go[s[v->l]] = res;
    res->go[s[pos]] = v;
    v->p = res;
    v->l = pos;
    return res;
}

pair<Node *, int> go(Node *v, int l, int len) {
    while(len > 0) {
        v = v->go[s[l]];
        len -= v->r - v->l;
        l += v->r - v->l;
    }
    return make_pair(v, v->r + len);
}

void add(int i, pair<Node *, int> &p) {
    Node *w = 0;
    while(curSuf <= i) {
        Node *v = p.first;
        int pos = p.second;
        if(pos != v->r) {
            if(s[i] == s[pos]) {
                p.second++;
                return;
            }
            v = splitEdge(v, pos);
            Node *u = new Node(i, n, v);
            v->go[s[i]] = u;
            if(w)
                w->link = v;
            w = v;
        }
        else {
            if(w)
                w->link = v;
            w = 0;
            if(v->go.find(s[i]) != v->go.end()) {
                p.first = v->go[s[i]];
                p.second = p.first->l + 1;
                return;
            }
            Node *u = new Node(i, n, v);
            v->go[s[i]] = u;
        }
        int len = 0, l = v->r;
        Node *q = v;
        while(!q->link && q->p) {
            len += q->r - q->l;
            l -= q->r - q->l;
            q = q->p;
        }
        if(!q->p) {
            if(len)
                p = go(q, l + 1, len - 1);
        }
        else
            p = go(q->link, l, len);
        curSuf++;
    }
}

Node *buildSufTree() {
    s += '$';
    n = s.length();
    Node *root = new Node(0, 0, 0);
    pair<Node *, int> p = make_pair(root, 0);
    curSuf = 0;
    for(int i = 0; i < n; i++)
        add(i, p);
    return root;
}

void dfs(Node *v, int dep) {
    for(size_t i = 0; i < v->t.size(); i++)
        l[v->t[i]] = leafs.size();
    if(v->go.empty())
        leafs.push_back(sid[n - dep]);
    for(map<char, Node *>::iterator it = v->go.begin(); it != v->go.end(); it++)
        dfs(it->second, dep + it->second->r - it->second->l);
    for(size_t i = 0; i < v->t.size(); i++)
        r[v->t[i]] = leafs.size();
}

StNode *newStNode(StNode *l, StNode *r) {
    nodes[freeNode] = StNode(l, r);
    return &nodes[freeNode++];
}

StNode *newStNode(int val) {
    nodes[freeNode] = StNode(val);
    return &nodes[freeNode++];
}

StNode *buildst() {
    StNode *res = newStNode(0);
    for(int i = 0; i < 20; i++)
        res = newStNode(res, res);
    return res;
}

StNode *update(StNode *v, int tl, int tr, int pos, int val) {
    if(tl == tr - 1)
        return newStNode(val);
    int tm = (tl + tr) / 2;
    if(pos < tm)
       return newStNode(update(v->l, tl, tm, pos, val), v->r);
    else
        return newStNode(v->l, update(v->r, tm, tr, pos, val));
}

int get(StNode *v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return v->val;
    int tm = (tl + tr) / 2, res = 0;
    if(l < tm)
        res += get(v->l, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(v->r, tm, tr, max(l, tm), r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, q;
    cin >> m >> q;
    for(int i = 0; i < m; i++) {
        cin >> t[i];
        s += t[i] + '#';
    }
    Node *root = buildSufTree();
    int pp = 0;
    for(int i = 0; i < n; i++) {
        sid[i] = pp;
        if(s[i] == '#')
            pp++;
    }
    for(int i = 0; i < m; i++) {
        Node *v = root;
        for(size_t j = 0; j < t[i].length();) {
            v = v->go[t[i][j]];
            j += v->r - v->l;
        }
        v->t.push_back(i);
    }
    dfs(root, 0);
    for(int i = 0; i < n; i++)
        p[i] = make_pair(leafs[i], i);
    sort(p, p + n);
    st[0] = buildst();
    for(int i = 0, j = 0; i < n; i++)
        if(i == 0 || p[i].first != p[i - 1].first) {
            st[j + 1] = update(st[j], 0, n, p[i].second, 1);
            j++;
        }
        else
            st[j] = update(st[j], 0, n, p[i].second, 1);
    for(int i = 0; i < q; i++) {
        int ll, rr, k;
        cin >> ll >> rr >> k;
        ll--;
        k--;
        cout << get(st[rr], 0, n, l[k], r[k]) -
            get(st[ll], 0, n, l[k], r[k]) << '\n';
    }
    return 0;
}