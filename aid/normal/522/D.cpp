#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node *l, *r;

    Node() {}
    
    Node(int val): val(val), l(0), r(0) {}

    Node(Node *l, Node *r): val(min(l->val, r->val)), l(l), r(r) {}
};

const int MAXN = 500 * 1000 + 5, LOGN = 25, INF = 1000 * 1000 * 1000 + 5;
Node nodes[MAXN * LOGN];
int a[MAXN], prev[MAXN], freeNode;
Node *st[MAXN];
pair<int, int> p[MAXN];
map<int, int> mp;

Node *newNode(int val) {
    nodes[freeNode] = Node(val);
    return &nodes[freeNode++];
}

Node *newNode(Node *l, Node *r) {
    nodes[freeNode] = Node(l, r);
    return &nodes[freeNode++];
}

Node *buildst() {
    Node *root = newNode(INF);
    for(int i = 0; i < LOGN; i++)
        root = newNode(root, root);
    return root;
}

Node *update(Node *v, int tl, int tr, int pos, int x) {
    if(tl == tr - 1)
        return newNode(x);
    int tm = (tl + tr) / 2;
    if(pos < tm)
        return newNode(update(v->l, tl, tm, pos, x), v->r);
    else
        return newNode(v->l, update(v->r, tm, tr, pos, x));
}

int get(Node *v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return v->val;
    int tm = (tl + tr) / 2, res = INF;
    if(l < tm)
        res = min(res, get(v->l, tl, tm, l, min(r, tm)));
    if(r > tm)
        res = min(res, get(v->r, tm, tr, max(l, tm), r));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        if(mp.find(a[i]) == mp.end())
            prev[i] = -1;
        else
            prev[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    for(int i = 0; i < n; i++)
        p[i] = make_pair(prev[i], i);
    sort(p, p + n);
    st[n] = buildst();
    for(int i = n - 1; i >= 0; i--)
        st[i] = update(st[i + 1], 0, n, p[i].second, p[i].second - p[i].first);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int pos = lower_bound(p, p + n, make_pair(l, 0)) - p,
            ans = get(st[pos], 0, n, l, r);
        if(ans >= INF)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}