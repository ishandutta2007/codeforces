#include <iostream>

using namespace std;

const int NMAX = 100000 + 5;

struct Node {
    int st, dr;
    int sz;
    int underPops;
} tree[4 * NMAX];

int push[NMAX];

void unite(Node &res, const Node A, const Node &B) {
    if (B.underPops < A.sz) {
        res.sz = B.sz + A.sz - B.underPops;
        res.underPops = A.underPops;
    }
    else {
        res.sz = B.sz;
        res.underPops = A.underPops + B.underPops - A.sz;
    }
}

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    if (st == dr)
        return ;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);
}

void updatePush(int node, int where, int val) {
    if (tree[node].st == tree[node].dr) {
        push[where] = val;
        tree[node].sz = 1;
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (where <= mid)
        updatePush(node << 1, where, val);
    else
        updatePush((node << 1) + 1, where, val);
    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

void updatePop(int node, int where) {
    if (tree[node].st == tree[node].dr) {
        tree[node].underPops = 1;
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (where <= mid)
        updatePop(node << 1, where);
    else
        updatePop((node << 1) + 1, where);
    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

void print(int node, int pops) {
    if (tree[node].st == tree[node].dr) {
        cout << push[tree[node].st] << '\n';
        return ;
    }

    if (tree[(node << 1) + 1].sz - pops > 0)
        print((node << 1) + 1, pops);
    else
        print(node << 1, pops - tree[(node << 1) + 1].sz + tree[(node << 1) + 1].underPops);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int M;
    cin >> M;

    build(1, 1, M);

    for (int i = 1; i <= M; ++ i) {
        int where;
        bool type;
        cin >> where >> type;
        if (type == 0)
            updatePop(1, where);
        else {
            int val;
            cin >> val;
            updatePush(1, where, val);
        }

        if (tree[1].sz > 0)
            print(1, 0);
        else
            cout << "-1\n";
    }

    return 0;
}