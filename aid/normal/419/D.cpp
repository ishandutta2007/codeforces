#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int pr, x, pos, ts;
    Node *l, *r;
    
    Node(int pos): pr((rand() << 16) + rand()), x(-1),
                   pos(pos), ts(1), l(0), r(0) {}
};

const int MAXN = 1000 * 1000 + 5;
int ans[MAXN];
char used[MAXN];

void recalc(Node *v) {
    v->ts = 1 + (v->l? v->l->ts : 0) + (v->r? v->r->ts : 0);
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

pair<Node *, Node *> ctsplit(Node *root, int k) {
    if(!root)
        return pair<Node *, Node *>();
    int ls = (root->l? root->l->ts : 0) + 1;
    if(ls <= k) {
        pair<Node *, Node *> p = ctsplit(root->r, k - ls);
        root->r = p.first;
        recalc(root);
        return make_pair(root, p.second);
    }
    else {
        pair<Node *, Node *> p = ctsplit(root->l, k);
        root->l = p.second;
        recalc(root);
        return make_pair(p.first, root);
    }
}

bool dfs(Node *v) {
    if(!v)
        return true;
    bool res = dfs(v->l) && dfs(v->r) && (v->x == -1 || !used[v->x]);
    ans[v->pos] = v->x;
    if(v->x != -1)
        used[v->x] = true;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Node *root = 0;
    for(int i = 0; i < n; i++) {
        Node *v = new Node(i);
        root = ctmerge(root, v);
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        pair<Node *, Node *> p1 = ctsplit(root, y);
        pair<Node *, Node *> p2 = ctsplit(p1.first, y - 1);
        if(p2.second->x != -1 && p2.second->x != x) {
            cout << -1 << '\n';
            return 0;
        }
        p2.second->x = x;
        root = ctmerge(ctmerge(p2.second, p2.first), p1.second);
    }
    bool b = dfs(root);
    if(!b) {
        cout << -1 << '\n';
        return 0;
    }
    int j = 0;
    for(int i = 0; i < n; i++)
        if(ans[i] == -1) {
            while(used[j])
                j++;
            ans[i] = j;
            used[j] = true;
        }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}