#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

vector <int> col, sz;

struct Node{
    int prior, size, val;
    Node *l, *r;
};

int size(Node *a) {
    if (!a) return 0;
    return (a -> size);
}

void upd(Node *a) {
    a -> size = size(a -> l) + size(a -> r) + 1;
}

Node *merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a -> prior > b -> prior) {
        a -> r = merge(a -> r, b);
        upd(a);
        return a;
    } else {
        b -> l = merge(a, b -> l);
        upd(b);
        return b;
    }
}

pair <Node*, Node*> split(Node *a, int k) {
    if (!a) return {0, 0};
    if (size(a -> l) + 1 <= k) {
        pair <Node*, Node*> b = split(a -> r, k - size(a -> l) - 1);
        a -> r = b.first;
        upd(a);
        return {a, b.second};
    } else {
        pair <Node*, Node*> b = split(a -> l, k);
        a -> l = b.second;
        upd(a);
        return {b.first, a};
    }
}

Node *init(int i) {
    Node *a = new Node;
    a -> prior = rand();
    a -> size = 1;
    a -> val = i;
    a -> l = a -> r = 0;
    return a;
}

void output(Node *a) {
    if (!a) return;
    output(a -> l);
    cout << a -> val + 1 << " ";
    output(a -> r);
}

unordered_map <int, Node*> ans;

int find(int v) {
    if (col[v] == -1)
        return v;
    return col[v] = find(col[v]);
}

void unite(int v, int u) {
    v = find(v), u = find(u);
    if (sz[v] > sz[u])
        swap(v, u);
    col[v] = u;
    sz[u] += sz[v];
    ans[u] = merge(ans[u], ans[v]);
    ans.erase(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    col.resize(n, -1);
    sz.resize(n);
    forn (i, 0, n)
        ans[i] = merge(ans[i], init(i));
    forn (i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(a, b);
    }
    forn (i, 0, n)
        if (ans[i])
            output(ans[i]);
    return 0;
}