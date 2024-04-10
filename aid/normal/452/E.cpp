#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Node {
    map<char, Node *> go;
    int l, *r, s0, s1, s2;
    Node *p, *suflink;
    
    Node(int l, int *r, Node *p): l(l), r(r), s0(0), s1(0), s2(0),
                                  p(p), suflink(0) {}
};

const int MAXN = 300 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int ans[MAXN], n, n0, n1, e = 1, j = 0;
string s;

pair<Node *, int> go(Node *v, int l, int len) {
    while(len > 0) {
        Node *u = v->go[s[l]];
        l += *u->r - u->l;
        len -= *u->r - u->l;
        v = u;
    }
    return make_pair(v, *v->r + len);
}

Node *splitEdge(Node *v, int pos) {
    Node *u = new Node(v->l, new int(pos), v->p);
    v->p->go[s[v->l]] = u;
    u->go[s[pos]] = v;
    v->p = u;
    v->l = pos;
    return u;
}

pair<Node *, int> add(int i, pair<Node *, int> p) {
    Node *v = p.first, *w = 0;
    while(j <= i) {
        Node *u = p.first;
        int pos = p.second;
        if(pos != *u->r) {
            if(s[i] == s[pos]) {
                p.second++;
                return p;
            }
            u = splitEdge(u, pos);
            v = new Node(i, &e, u);
            u->go[s[i]] = v;
            if(w)
                w->suflink = u;
            w = u;
        }
        else if(!u->go.empty()) {
            if(u->go.find(s[i]) != u->go.end()) {
                p.first = u->go[s[i]];
                p.second = p.first->l + 1;
                return p;
            }
            v = new Node(i, &e, u);
            u->go[s[i]] = v;
            if(w)
                w->suflink = u;
            w = 0;
        }
        j++;
        int len = 0, l = *v->r;
        Node *q = v;
        while(!q->suflink && q->p) {
            len += *q->r - q->l;
            l -= *q->r - q->l;
            q = q->p;
        }
        if(!q->p) {
            if(!len) {
                len++;
                l--;
            }
            p = go(q, l + 1, len - 1);
        }
        else
            p = go(q->suflink, l, len);
    }
    return p;
}

Node *buildSufTree() {
    Node *root = new Node(0, new int(0), 0);
    Node *v = new Node(0, &e, root);
    root->go[s[0]] = v;
    pair<Node *, int> p = make_pair(v, 1);
    for(int i = 1; i < n; i++) {
        p = add(i, p);
        e++;
    }
    e--;
    return root;
}

void dfs(Node *v, int dep) {
    if(v->l <= n0 && *v->r > n0) {
        v->s0++;
        return;
    }
    if(v->l <= n1 && *v->r > n1) {
        v->s1++;
        return;
    }
    if(v->go.empty()) {
        v->s2++;
        return;
    }
    for(map<char, Node *>::iterator it = v->go.begin();
        it != v->go.end(); it++) {
        dfs(it->second, dep + *it->second->r - it->second->l);
        v->s0 += it->second->s0;
        v->s1 += it->second->s1;
        v->s2 += it->second->s2;
    }
    int add = ((long long)v->s0 * v->s1 * v->s2) % MOD;
    ans[dep - *v->r + v->l + 1] += add;
    ans[dep - *v->r + v->l + 1] %= MOD;
    ans[dep + 1] += MOD - add;
    ans[dep + 1] %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    string t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    s = t0 + "#" + t1 + "$" + t2 + "%";
    n = s.length();
    n0 = t0.length();
    n1 = n0 + 1 + (int)t1.length();
    Node *root = buildSufTree();
    dfs(root, 0);
    int l = min(min((int)t0.length(), (int)t1.length()), (int)t2.length());
    for(int i = 1; i <= l; i++) {
        ans[i] = (ans[i] + ans[i - 1]) % MOD;
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}