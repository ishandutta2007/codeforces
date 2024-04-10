#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct StNode {
    int val;
    StNode *l, *r;

    StNode(int _val): val(_val), l(0), r(0) {}

    StNode(StNode *_l, StNode *_r):
        val((_l? _l->val : 0) + (_r? _r->val : 0)), l(_l), r(_r) {}
};

StNode *buildSt() {
    StNode *res = new StNode(0);
    for(int i = 0; i < 20; i++)
        res = new StNode(res, res);
    return res;
}

StNode *update(StNode *v, int tl, int tr, int pos, int add) {
    if(tl == tr - 1)
        return new StNode(v->val + add);
    int tm = (tl + tr) / 2;
    if(pos < tm)
        return new StNode(update(v->l, tl, tm, pos, add), v->r);
    else
        return new StNode(v->l, update(v->r, tm, tr, pos, add));
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

struct Node {
    map<int, Node *> go;
    int l, r;
    Node *p, *link;
    StNode *st;
    vector<int> t;
    int cnt;

    Node(int _l, int _r, Node *_p): l(_l), r(_r), p(_p),
                                    link(0), st(0), cnt(0) {}
};

int nn, curSuf;
vector<int> a, sid;

Node *splitEdge(Node *v, int pos) {
    Node *res = new Node(v->l, pos, v->p);
    v->p->go[a[v->l]] = res;
    res->go[a[pos]] = v;
    v->p = res;
    v->l = pos;
    return res;
}

pair<Node *, int> go(Node *v, int l, int len) {
    while(len > 0) {
        v = v->go[a[l]];
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
            if(a[i] == a[pos]) {
                p.second++;
                return;
            }
            v = splitEdge(v, pos);
            Node *u = new Node(i, nn, v);
            v->go[a[i]] = u;
            if(w)
                w->link = v;
            w = v;
        }
        else {
            if(w)
                w->link = v;
            w = 0;
            if(v->go.find(a[i]) != v->go.end()) {
                p.first = v->go[a[i]];
                p.second = p.first->l + 1;
                return;
            }
            Node *u = new Node(i, nn, v);
            v->go[a[i]] = u;
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
    nn = a.size();
    Node *root = new Node(0, 0, 0);
    pair<Node *, int> p = make_pair(root, 0);
    curSuf = 0;
    for(int i = 0; i < nn; i++)
        add(i, p);
    return root;
}

const int MAXN = 100 * 1000 + 5, K = 100, S = 1000;
long long ans[MAXN], cnt[MAXN], scnt[MAXN];
int n;
vector< pair<pair<int, int>, int> > qq[MAXN];
vector<Node *> leafs[MAXN];
string s[MAXN];

void dfs(Node *v, int dep = 0) {
    if(v->go.empty() && dep) {
        leafs[sid[nn - dep]].push_back(v);
    }
    for(size_t i = 0; i < v->t.size(); i++)
        v->st = update(v->st, 0, n, v->t[i], 1);
    for(map<int, Node *>::iterator it = v->go.begin();
        it != v->go.end(); it++) {
        it->second->st = v->st;
        dfs(it->second, dep + it->second->r - it->second->l);
    }
}

void dfs0(Node *v) {
    v->cnt = v->go.empty();
    for(map<int, Node *>::iterator it = v->go.begin();
        it != v->go.end(); it++) {
        dfs0(it->second);
        v->cnt += it->second->cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        k--;
        qq[k].push_back(make_pair(make_pair(l, r), i));
    }
    for(int i = 0; i < n; i++)
        if((int)s[i].length() < K) {
            for(size_t j = 0; j < s[i].length(); j++) {
                a.push_back((unsigned char)(s[i][j]));
                sid.push_back(i);
            }
            a.push_back(S + i);
            sid.push_back(i);
        }
    Node *root = buildSufTree();
    for(int i = 0; i < n; i++)
        if((int)s[i].length() < K) {
            Node *v = root;
            int pos = 0;
            for(size_t j = 0; j < s[i].length(); j++)
                if(pos != v->r)
                    pos++;
                else {
                    v = v->go[(unsigned char)(s[i][j])];
                    pos = v->l + 1;
                }
            v->t.push_back(i);
        }
    root->st = buildSt();
    dfs(root);
    for(int i = 0; i < n; i++)
        if((int)s[i].length() < K) {
            for(size_t j = 0; j < qq[i].size(); j++) {
                int l = qq[i][j].first.first, r = qq[i][j].first.second;
                for(size_t k = 0; k < leafs[i].size(); k++)
                    ans[qq[i][j].second] += get(leafs[i][k]->st, 0, n, l, r);
            }
        }
    for(int i = 0; i < n; i++)
        if((int)s[i].length() >= K) {
            a.clear();
            for(size_t j = 0; j < s[i].length(); j++)
                a.push_back((unsigned char)(s[i][j]));
            a.push_back(S);
            root = buildSufTree();
            dfs0(root);
            for(int j = 0; j < n; j++) {
                cnt[j] = 0;
                Node *v = root;
                int pos = 0;
                bool bad = false;
                for(size_t k = 0; k < s[j].length(); k++)
                    if(pos != v->r) {
                        if((unsigned char)(s[j][k]) != a[pos]) {
                            bad = true;
                            break;
                        }
                        pos++;
                    }
                    else {
                        if(v->go.find((unsigned char)(s[j][k])) == v->go.end()) {
                            bad = true;
                            break;
                        }
                        v = v->go[(unsigned char)(s[j][k])];
                        pos = v->l + 1;
                    }
                if(bad)
                    continue;
                cnt[j] = v->cnt;
            }
            scnt[0] = 0;
            for(int j = 0; j < n; j++)
                scnt[j + 1] = scnt[j] + cnt[j];
            for(size_t j = 0; j < qq[i].size(); j++) {
                int l = qq[i][j].first.first, r = qq[i][j].first.second;
                ans[qq[i][j].second] = scnt[r] - scnt[l];
            }
        }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}