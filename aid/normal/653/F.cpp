#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

struct Node {
    int l, r;
    Node *p, *link;
    map<char, Node *> go;

    Node(int _l, int _r, Node *_p): l(_l), r(_r), p(_p), link(0) {}
};

int curSuf, n;
string s;

Node *splitEdge(Node *v, int pos) {
    Node *res = new Node(v->l, pos, v->p);
    v->p->go[s[v->l]] = res;
    res->go[s[pos]] = v;
    v->l = pos;
    v->p = res;
    return res;
}

pair<Node *, int> go(Node *v, int l, int len) {
    while(len > 0) {
        v = v->go[s[l]];
        l += v->r - v->l;
        len -= v->r - v->l;
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
        Node *q = v;
        int l = q->r, len = 0;
        while(!q->link && q->p) {
            l -= q->r - q->l;
            len += q->r - q->l;
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
    Node *root = new Node(0, 0, 0);
    pair<Node *, int> p(root, 0);
    curSuf = 0;
    for(int i = 0; i < n; i++)
        add(i, p);
    return root;
}

const int MAXN = 500 * 1000 + 5;
int a[MAXN];
set< pair<int, int> > st[2 * MAXN];

int getCnt(int l, int r, int bal) {
    bal += a[l];
    set< pair<int, int> >::iterator
        itl = st[MAXN + bal].lower_bound(make_pair(l + 1, 0)),
        itr = st[MAXN + bal].lower_bound(make_pair(r + 1, 0));
    return itr->second - itl->second;
}

int getLeftest(int l, int bal) {
    bal += a[l];
    return st[MAXN + bal].lower_bound(make_pair(l + 1, 0))->first;
}

long long dfs(Node *v, int bal) {
    long long res = 0;
    for(map<char, Node *>::iterator it = v->go.begin();
        it != v->go.end(); it++) {
        Node *u = it->second;
        if(getCnt(u->l, u->r, -bal - 1)) {
            int rr = getLeftest(u->l, -bal - 1);
            res += getCnt(u->l, rr - 1, -bal);
            continue;
        }
        res += getCnt(u->l, u->r, -bal);
        res += dfs(u, bal + a[u->r] - a[u->l]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    s += '$';
    n++;
    a[0] = 0;
    for(int i = 0; i < n - 1; i++)
        a[i + 1] = a[i] + (s[i] == '('? 1 : -1);
    for(int i = 0; i < n; i++) {
        int sz = st[MAXN + a[i]].size();
        st[MAXN + a[i]].insert(make_pair(i, sz));
    }
    for(int i = 0; i < 2 * MAXN; i++) {
        int sz = st[i].size();
        st[i].insert(make_pair(n + 1, sz));
    }
    cout << dfs(buildSufTree(), 0) << '\n';
    return 0;
}