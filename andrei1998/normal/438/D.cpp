#include <iostream>

#define lint long long int
using namespace std;

const int NMAX = 100000 + 5;

struct Node {
    int st, dr;
    lint sum;
    int maximum;
} tree[4 * NMAX];

int a[NMAX];

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;

    if (st == dr) {
        tree[node].sum = tree[node].maximum = a[st];
        return ;
    }

    int mid = (st + dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);

    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    tree[node].maximum = max(tree[node << 1].maximum, tree[(node << 1) + 1].maximum);
}

lint sum(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].sum;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        return sum(node << 1, st, dr);
    else if (st > mid)
        return sum((node << 1) + 1, st, dr);
    else
        return sum(node << 1, st, mid) +
               sum((node << 1) + 1, mid + 1, dr);
}

void update_pos(int node, int where) {
    if (tree[node].st == tree[node].dr) {
        tree[node].sum = tree[node].maximum = a[where];
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (where <= mid)
        update_pos(node << 1, where);
    else
        update_pos((node << 1) + 1, where);

    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    tree[node].maximum = max(tree[node << 1].maximum, tree[(node << 1) + 1].maximum);
}

void update_mod(int node, int st, int dr, int val) {
    if (tree[node].maximum < val)
        return ;

    if (tree[node].st == tree[node].dr) {
        a[st] = a[st] % val;
        tree[node].sum = tree[node].maximum = a[st];
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        update_mod(node << 1, st, dr, val);
    else if (st > mid)
        update_mod((node << 1) + 1, st, dr, val);
    else {
        update_mod(node << 1, st, mid, val);
        update_mod((node << 1) + 1, mid + 1, dr, val);
    }

    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    tree[node].maximum = max(tree[node << 1].maximum, tree[(node << 1) + 1].maximum);
}
int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    build(1, 1, n);

    int type;
    while (m --) {
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;

            cout << sum(1, l, r) << '\n';
        }
        else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            update_mod(1, l, r, x);
        }
        else {
            int k, x;
            cin >> k >> x;
            a[k] = x;
            update_pos(1, k);
        }
    }

    return 0;
}