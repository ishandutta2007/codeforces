#include <iostream>

using namespace std;

const int MOD = 777777777;
const int NMAX = 100000 + 5;

struct Node {
    int st, dr;

    int mat[4][4];
} tree[4 * NMAX];

int n, m;
bool good[4][4];

void unite(Node &res, const Node &a, const Node &b) {
    for (int i = 1; i <= 3; ++ i)
        for (int j = 1; j <= 3; ++ j)
            res.mat[i][j] = 0;

    for (int i = 1; i <= 3; ++ i)
        for (int j = 1; j <= 3; ++ j)
            for (int k = 1; k <= 3; ++ k)
                if (good[j][k])
                    for (int l = 1; l <= 3; ++ l)
                        res.mat[i][l] = (res.mat[i][l] + 1LL * a.mat[i][j] * b.mat[k][l]) % MOD;
}

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    if (st == dr) {
        for (int j = 1; j <= 3; ++ j)
            tree[node].mat[j][j] = 1;
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);

    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

void update(int node, int where, int val) {
    if (tree[node].st == tree[node].dr) {
        if (val == 0)
            for (int j = 1; j <= 3; ++ j)
                tree[node].mat[j][j] = 1;
        else {
            for (int j = 1; j <= 3; ++ j)
                tree[node].mat[j][j] = (val == j);
        }
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;

    if (where <= mid)
        update(node << 1, where, val);
    else
        update((node << 1) + 1, where, val);
    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= 3; ++ i)
        for (int j = 1; j <= 3; ++ j)
            cin >> good[i][j];

    build(1, 1, n);

    while (m --) {
        int where, val;
        cin >> where >> val;

        update(1, where, val);

        int ans = 0;
        for (int i = 1; i <= 3; ++ i)
            for (int j = 1; j <= 3; ++ j) {
                ans += tree[1].mat[i][j];
                if (ans >= MOD)
                    ans -= MOD;
            }
        cout << ans << '\n';
    }

    return 0;
}