#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100000 + 5;

int N, K;

int rmq[17][NMAX];
int logar[NMAX];

void computeRmq() {
    for (int i = 2; i <= N; ++ i)
        logar[i] = 1 + logar[i >> 1];

    for (int i = 1; (1 << i) <= N; ++ i)
        for (int j = 0; j + (1 << i) - 1 < N; ++ j)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

int getRmq(int st, int dr) {
    int y = logar[dr - st + 1];
    return min(rmq[y][st], rmq[y][dr - (1 << y) + 1]);
}

int getMin(int st, int dr) {
    int bSt = st / N;
    int bDr = dr / N;

    if (bSt == bDr)
        return getRmq(st % N, dr % N);
    else if (bSt + 1 == bDr)
        return min(getRmq(st % N, N - 1),
                   getRmq(0, dr % N));
    else
        return getRmq(0, N - 1);
}

struct Node {
    int minimum;
    int lazy;
    Node *left, *right;

    Node(int _minimum = 1E9 + 15, int _lazy = -1, Node *_left = NULL, Node *_right = NULL):
        minimum(_minimum), lazy(_lazy), left(_left), right(_right) {}
} *root;

int getMinimum(Node *node) {
    if (node == NULL)
        return 1E9 + 15;
    else
        return node -> minimum;
}

void propagate(Node *node) {
    if (node -> lazy != -1) {
        if (node -> left == NULL)
            node -> left = new Node(node -> lazy, node -> lazy);
        if (node -> right == NULL)
            node -> right = new Node(node -> lazy, node -> lazy);
        node -> left -> minimum = node -> left -> lazy = node -> lazy;
        node -> right -> minimum = node -> right -> lazy = node -> lazy;
        node -> lazy = -1;
    }
}

void update(Node *node, int nodeSt, int nodeDr, int st, int dr, int val) {
    if (nodeSt == st && nodeDr == dr) {
        node -> minimum = node -> lazy = val;
        return ;
    }
    propagate(node);

    int nodeMid = (nodeSt + nodeDr) >> 1;
    if (node -> left == NULL)
        node -> left = new Node(getMin(nodeSt, nodeMid));
    if (node -> right == NULL)
        node -> right = new Node(getMin(nodeMid + 1, nodeDr));

    if (dr <= nodeMid)
        update(node -> left, nodeSt, nodeMid, st, dr, val);
    else if (st > nodeMid)
        update(node -> right, nodeMid + 1, nodeDr, st, dr, val);
    else {
        update(node -> left, nodeSt, nodeMid, st, nodeMid, val);
        update(node -> right, nodeMid + 1, nodeDr, nodeMid + 1, dr, val);
    }

    node -> minimum = min(getMinimum(node -> left), getMinimum(node -> right));
}

int query(Node *node, int nodeSt, int nodeDr, int st, int dr) {
    if (nodeSt == st && nodeDr == dr)
        return node -> minimum;
    propagate(node);

    int nodeMid = (nodeSt + nodeDr) >> 1;
    if (dr <= nodeMid) {
        if (node -> left == NULL)
            node -> left = new Node(getMin(nodeSt, nodeMid));
        return query(node -> left, nodeSt, nodeMid, st, dr);
    }
    else if (st > nodeMid) {
        if (node -> right == NULL)
            node -> right = new Node(getMin(nodeMid + 1, nodeDr));
        return query(node -> right, nodeMid + 1, nodeDr, st, dr);
    }
    else {
        if (node -> left == NULL)
            node -> left = new Node(getMin(nodeSt, nodeMid));
        if (node -> right == NULL)
            node -> right = new Node(getMin(nodeMid + 1, nodeDr));

        return min(query(node -> left, nodeSt, nodeMid, st, nodeMid),
                   query(node -> right, nodeMid + 1, nodeDr, nodeMid + 1, dr));
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++ i)
        cin >> rmq[0][i];
    computeRmq();

    root = new Node(getMin(0, N * K - 1), -1);

    int Q = 0;
    cin >> Q;

    while (Q --) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            -- l, -- r;
            update(root, 0, N * K - 1, l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            -- l, -- r;
            cout << query(root, 0, N * K - 1, l, r) << '\n';
        }
    }

    return 0;
}