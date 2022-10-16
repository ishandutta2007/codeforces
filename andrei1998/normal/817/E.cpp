#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000;

struct Node {
    int sz;
    int son[2];
} nodes[30 * NMAX];
int sz = 1;

void add(int nr, int val) {
    int node = 1;
    for (int i = 28; i >= 0; -- i) {
        nodes[node].sz += val;
        int type = 0;
        if (nr & (1 << i))
            type = 1;
        if (!nodes[node].son[type])
            nodes[node].son[type] = ++ sz;
        node = nodes[node].son[type];
    }
    nodes[node].sz += val;
}

int query(int p, int atMost) {
    int ans = 0;
    int node = 1;
    for (int i = 28; i >= 0 && node; -- i) {
        bool rev = false;
        if (p & (1 << i))
            rev = true;

        if (atMost & (1 << i)) {
            ans += nodes[nodes[node].son[rev]].sz;
            node = nodes[node].son[1 ^ rev];
        }
        else
            node = nodes[node].son[rev];
    }

    ans += nodes[node].sz;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    while (Q --) {
        int type, p;
        cin >> type >> p;
        if (type == 1)
            add(p, 1);
        else if (type == 2)
            add(p, -1);
        else {
            int l;
            cin >> l;
            cout << query(p, l - 1) << '\n';
        }
    }
    return 0;
}