#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

#define M 1010
#define N 13
#define A 26
#define mod 1000000009

struct Node {
    Node* go[A];
    bool leaf;
    Node *link;
    Node *anc;
    char to_anc;
    Node *clink;
    int depth;
    Node() {
        leaf = false;
        link = nullptr;
        anc = nullptr;
        clink = nullptr;
        depth = 0;
    }
} t[M];

Node *root = t;
int tree_size = 1;

Node *go(Node *v, char c);
Node *link(Node *v);
Node *clink(Node *v);

Node* go(Node *v, char c) {
    //cerr << "go\n";
    if (v->go[c] == nullptr) {
        if (v == root)
            return v->go[c] = root;
        return v->go[c] = go(link(v), c);
    }
    return v->go[c];
}

Node* link(Node *v) {
    //cerr << "link\n";
    if (v->link == nullptr) {
        if (v == root || v->anc == root)
            return v->link = root;
        return v->link = go(link(v->anc), v->to_anc);
    }
    return v->link;
}

Node* clink(Node *v) {
    if (v->clink == nullptr) {
        if (v == root)
            return v->clink = root;
        if (link(v)->leaf)
            return v->clink = v->link;
        return v->clink = clink(v->link);
    }
    return v->clink;
}

void add(Node *v, Node *to, char c) {
    v->go[c] = to;
    to->anc = v;
    to->to_anc = c;
    to->depth = v->depth + 1;
}

int maxD(Node *v) {
    if (v->leaf)
        return v->depth;
    if (v == root)
        return 0;
    return clink(v)->depth;
}

void add(const string &s) {
    Node *v = root;
    for (char ch : s) {
        int c = ch - 'A';
        if (v->go[c] == nullptr) {
            add(v, t + tree_size, c);
            ++tree_size;
        }
        v = v->go[c];
    }
    v->leaf = true;
}

int n, m;
int d[M][N], h[M][N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        add(s);
    }
}

void next(int x, int y, char c, int &tx, int &ty) {
    tx = (int) (go(t + x, c) - t);
    ty = y + 1;
    int d = maxD(t + tx);
    if (d >= ty)
        ty = 0;
}

void din_step() {
    for (int i = 0; i < tree_size; ++i)
        for (int j = 0; j < N; ++j)
            if (d[i][j]) {
                int tx, ty;
                for (int k = 0; k < A; ++k) {
                    next(i, j, k, tx, ty);
                    if (ty >= N)
                        continue;
                    h[tx][ty] += d[i][j];
                    if (h[tx][ty] >= mod)
                        h[tx][ty] -= mod;
                }
            }
    for (int i = 0; i < tree_size; ++i)
        for (int j = 0; j < N; ++j) {
            d[i][j] = h[i][j];
            h[i][j] = 0;
        }
}

int main() {
    read();
    d[0][0] = 1;
    for (int i = 0; i < n; ++i)
        din_step();
    int ans = 0;
    for (int i = 0; i < tree_size; ++i) {
        ans += d[i][0];
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << "\n";
    return 0;
}