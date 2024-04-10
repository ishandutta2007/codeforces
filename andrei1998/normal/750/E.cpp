#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str;

const int NMAX = 200000 + 5;
const int INF = 5 * NMAX;

struct Node {
    int st, dr;
    int cnt[10];
    int ans[5][5];

} tree[4 * NMAX];

void unite(Node &res, const Node a, const Node &b) {
    if (a.st == -1) {
        res = b;
        return ;
    }

    for (int i = 0; i < 10; ++ i)
        res.cnt[i] = a.cnt[i] + b.cnt[i];

    for (int i = 0; i < 5; ++ i)
        for (int j = i + 1; j < 5; ++ j) {
            res.ans[i][j] = INF;
            for (int k = i; k <= j; ++ k)
                res.ans[i][j] = min(res.ans[i][j], a.ans[i][k] + b.ans[k][j]);
        }

    res.ans[0][0] = res.cnt[2];
    res.ans[1][1] = res.cnt[0];
    res.ans[2][2] = res.cnt[1];
    res.ans[3][3] = res.cnt[7] + res.cnt[6];
    res.ans[4][4] = res.cnt[6];
}

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;

    if (st == dr) {
        for (int i = 0; i < 10; ++ i)
            tree[node].cnt[i] = 0;
        tree[node].cnt[str[st] - '0'] = 1;

        for (int i = 0; i < 5; ++ i)
            for (int j = i + 1; j < 5; ++ j)
                tree[node].ans[i][j] = INF;

        tree[node].ans[0][0] = tree[node].cnt[2];
        tree[node].ans[1][1] = tree[node].cnt[0];
        tree[node].ans[2][2] = tree[node].cnt[1];
        tree[node].ans[3][3] = tree[node].cnt[7] + tree[node].cnt[6];
        tree[node].ans[4][4] = tree[node].cnt[6];

        if (tree[node].cnt[2] == 1)
            tree[node].ans[0][1] = 0;
        if (tree[node].cnt[0] == 1)
            tree[node].ans[1][2] = 0;
        if (tree[node].cnt[1] == 1)
            tree[node].ans[2][3] = 0;
        if (tree[node].cnt[7] == 1)
            tree[node].ans[3][4] = 0;

        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);

    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

Node ans;
void query(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr) {
        unite(ans, ans, tree[node]);
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        query(node << 1, st, dr);
    else if (st > mid)
        query((node << 1) + 1, st, dr);
    else {
        query(node << 1, st, mid);
        query((node << 1) + 1, mid + 1, dr);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    cin >> str;
    str = " " + str;

    build(1, 1, n);

    while (q --) {
        int a, b;
        cin >> a >> b;

        ans.st = -1;
        query(1, a, b);

        if (ans.ans[0][4] == INF)
            cout << "-1\n";
        else
            cout << ans.ans[0][4] << '\n';
    }

    return 0;
}