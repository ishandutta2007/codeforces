#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//21:27
const int NMAX = 500005;
int n;

vector <int> graph[NMAX];
int father[NMAX];

int parc[NMAX];
int pos;

int first[NMAX];
int last[NMAX];

void dfs(int node) {
    parc[++ pos] = node;
    first[node] = pos;
    for (auto it: graph[node])
        if (it != father[node]) {
            father[it] = node;
            dfs(it);
        }
    last[node] = pos;
}

int last_erase[NMAX];

#define lsb(x) ((x) & (-(x)))
int aib[NMAX];

void update(int pos, int val) {
    for (; pos <= n; pos += lsb(pos))
        aib[pos] = max(aib[pos], val);
}

int query(int a, int b) {
    int ans = 0;
    while (a <= b) {
        if (a <= b - lsb(b) + 1) {
            ans = max(ans, aib[b]);
            b -= lsb(b);
        }
        else {
            ans = max(ans, last_erase[b]);
            -- b;
        }
    }

    return ans;
}

struct Node {
    int st, dr;
    int maxim;
    int lazy;
} tree[4 * NMAX];

void build(int st, int dr, int node) {
    tree[node].st = st, tree[node].dr = dr;
    if (st == dr)
        return ;

    int mid = (st + dr) >> 1;
    build(st, mid, node << 1);
    build(mid + 1, dr, (node << 1) + 1);
}

void update_aint(int st, int dr, int val, int node) {
    if (tree[node].st == st && tree[node].dr == dr) {
        tree[node].maxim = val;
        tree[node].lazy = val;

        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        update_aint(st, dr, val, node << 1);
    else if (st > mid)
        update_aint(st, dr, val, (node << 1) + 1);
    else {
        update_aint(st, mid, val, node << 1);
        update_aint(mid + 1, dr, val, (node << 1) + 1);
    }

    tree[node].maxim = max(max(tree[node << 1].maxim, tree[(node << 1) + 1].maxim), tree[node].maxim);
}

int query_aint(int st, int dr, int node) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].maxim;

    int ans = tree[node].lazy;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        ans = max(ans, query_aint(st, dr, node << 1));
    else if (st > mid)
        ans = max(ans, query_aint(st, dr, (node << 1) + 1));
    else
        ans = max(max(query_aint(st, mid, node << 1),
                   query_aint(mid + 1, dr, (node << 1) + 1)),
                  ans);

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n;

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    build(1, n, 1);

    int q = 0;
    cin >> q;

    int c, v;
    for (int i = 1; i <= q; ++ i) {
        cin >> c >> v;

        if (c == 1)
            update_aint(first[v], last[v], i, 1);
        else if (c == 2) {
            last_erase[first[v]] = i;
            update(first[v], i);
        }
        else {
            int add = query_aint(first[v], first[v], 1);
            int del = query(first[v], last[v]);

            if (del < add)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}