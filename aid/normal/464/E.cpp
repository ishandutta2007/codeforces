#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 100 * 1000 + 5, LOGX = 17,
    MAXX = (1 << LOGX), MOD = 1000 * 1000 * 1000 + 7, P = 179;
int p[MAXX], p2[MAXX], par[MAXN];
char used[MAXN];
vector< pair<int, int> > g[MAXN];

struct Node {
    int hash;
    char zero;
    Node *l, *r;

    Node(Node *l, Node *r, int k): hash((l? l->hash : 0)+
                                        (r? r->hash : 0) * p[k]),
                                   zero((l? l->zero : false) ||
                                        (r? r->zero : false)), l(l), r(r) {}

    Node(bool b): hash(b), zero(!b), l(0), r(0) {}
};

Node *ones[LOGX + 1], *zeroes[LOGX + 1], *d[MAXN];

pair<Node *, bool> add(Node *v, int tl, int tr, int th, int x) {
    if(tl < x) {
        int tm = (tl + tr) / 2;
        Node *l = v->l, *r = v->r;
        pair<Node *, bool> p;
        if(x < tm) {
            p = add(v->l, tl, tm, th - 1, x);
            l = p.first;
        }
        if(x >= tm || !p.second) {
            p = add(v->r, tm, tr, th - 1, x);
            r = p.first;
        }
        return make_pair(new Node(l, r, tm - tl), p.second);
    }
    if(!v->zero)
        return make_pair(zeroes[th], false);
    if(tl == tr - 1)
        return make_pair(ones[th], true);
    int tm = (tl + tr) / 2;
    pair<Node *, bool> p = add(v->l, tl, tm, th - 1, x);
    Node *l = p.first, *r = v->r;
    if(!p.second) {
        p = add(v->r, tm, tr, th - 1, x);
        r = p.first;
    }
    return make_pair(new Node(l, r, tm - tl), p.second);
}

bool isLess(Node *v, Node *u, int tl, int tr) {
    if(tl == tr - 1)
        return v->zero && !u->zero;
    int tm = (tl + tr) / 2;
    if(v->r->hash == u->r->hash)
        return isLess(v->l, u->l, tl, tm);
    return isLess(v->r, u->r, tm, tr);
}

struct Cmp {
    bool operator() (int v, int u) {
        return isLess(d[v], d[u], 0, MAXX) ||
            (!isLess(d[u], d[v], 0, MAXX) && v < u);
    }
};

int getMod(Node *v, int tl, int tr) {
    if(tl == tr - 1)
        return !v->zero;
    int tm = (tl + tr) / 2,
        res0 = getMod(v->l, tl, tm),
        res1 = getMod(v->r, tm, tr);
    return (res0 + (long long)p2[tm - tl] * res1) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    p[0] = 1;
    for(int i = 1; i < MAXX; i++)
        p[i] = p[i - 1] * P;
    p2[0] = 1;
    for(int i = 1; i < MAXX; i++)
        p2[i] = (2 * p2[i - 1]) % MOD;
    ones[0] = new Node(true);
    for(int i = 1, len = 1; i <= LOGX; i++, len *= 2)
        ones[i] = new Node(ones[i - 1], ones[i - 1], len);
    zeroes[0] = new Node(false);
    for(int i = 1, len = 1; i <= LOGX; i++, len *= 2)
        zeroes[i] = new Node(zeroes[i - 1], zeroes[i - 1], len);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u, x;
        cin >> v >> u >> x;
        v--;
        u--;
        g[v].push_back(make_pair(u, x));
        g[u].push_back(make_pair(v, x));
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    for(int i = 0; i < n; i++)
        d[i] = ones[LOGX];
    d[s] = zeroes[LOGX];
    for(int i = 0; i < n; i++)
        par[i] = -1;
    set<int, Cmp> st;
    st.insert(s);
    while(!st.empty()) {
        int v = *st.begin();
        used[v] = true;
        st.erase(st.begin());
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, x = g[v][i].second;
            Node *newd = add(d[v], 0, MAXX, LOGX, x).first;
            if(isLess(newd, d[u], 0, MAXX)) {
                st.erase(u);
                d[u] = newd;
                par[u] = v;
                st.insert(u);
            }
        }
    }
    if(d[t] == ones[LOGX])
        cout << -1 << '\n';
    else {
        cout << getMod(d[t], 0, MAXX) << '\n';
        vector<int> ans;
        for(int i = t; i != -1; i = par[i])
            ans.push_back(i);
        cout << ans.size() << '\n';
        for(int i = (int)ans.size() - 1; i >= 0; i--)
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}