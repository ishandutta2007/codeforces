#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Node
{
    Node *p, *ch[2];
    int val, sz;
    bool dir() { return this == p->ch[1]; }
    void set(Node *x, bool d) { ch[d] = x; x->p = this; }
    void upd() { sz = ch[0]->sz + ch[1]->sz + 1; }
} *null = new Node(), *root;

Node* genNode()
{
    Node *x = new Node();
    x->p = x->ch[0] = x->ch[1] = null; x->sz = 1; x->val = -1;
    return x;
}

void rot(Node *x)
{
    Node *p = x->p; bool d = x->dir();
    p->p->set(x, p->dir()); p->set(x->ch[!d], d); x->set(p, !d);
    if (p == root) root = x;
    p->upd(); x->upd();
}

void splay(Node *x)
{
    while (x != root) {
        if (x->p == root) rot(x);
        else if (x->dir() == x->p->dir()) rot(x->p), rot(x);
        else rot(x), rot(x);
    }
}

void search(int k)
{
	Node *x = root;
    while (true) {
        if (x->ch[1]->sz < k) k -= x->ch[1]->sz + 1, x = x->ch[0];
        else if (x->ch[1]->sz == k) { splay(x); return; }
        else x = x->ch[1];
    }
}

void split(int k, Node *&r2)
{
    if (k == 0) { r2 = root, root = null; return; }
    search(k-1);
    r2 = root->ch[0];
    r2->p = root->ch[0] = null; root->upd();
}

void join(Node *&r2) // join to root
{
    Node *x = root;
    while (x->ch[0] != null) x = x->ch[0];
    splay(x);
    root->set(r2, 0); root->upd();
}

const int MAX = 1000007;
Node *nodes[MAX], *r1, *r2, *r3;
bool occ[MAX];

//int nextint()
//{
//	int ans = 0, sgn = 1; char ch = getchar();
//    while (ch == ' ' || ch == '\n') ch = getchar();
//    if (ch == '-') sgn = -1, ch = getchar();
//    while (47 < ch && ch < 58) ans = ans * 10 + ch - 48, ch = getchar();
//    return ans * sgn;
//}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        nodes[i] = genNode();
        if (i > 1) nodes[i]->set(nodes[i-1], 1);
        nodes[i]->upd();
    }
    root = nodes[n];

    while (m--) {
        int x, y; cin >> x >> y;
        if (y > 1) {
            split(y, r3); split(y-1, r2); r1 = root;
			root = r2; join(r1); join(r3);
		}

		r1 = root;
		while (r1->ch[1] != null) r1 = r1->ch[1];
		if (r1->val >= 0 && r1->val != x) return cout << -1, 0;
		r1->val = x;
    }

    for (int i = 1; i <= n; ++i) {
        int val = nodes[i]->val;
        if (val >= 0) {
            if (occ[val]) return cout << -1, 0;
            occ[val] = 1;
        }
    }

    int x = 1;
    for (int i = 1; i <= n; ++i) {
		if (nodes[i]->val < 0) {
            while (occ[x]) ++x;
            nodes[i]->val = x++;
		}
		cout << nodes[i]->val << ' ';
    }
}