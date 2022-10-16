#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2E5 + 15;

struct Node {
    int st, dr;
    int maximum;
} tree[4 * NMAX];

int N;
int v[NMAX];

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    if (st == dr) {
        tree[node].maximum = v[st];
        return ;
    }
    int mid = (tree[node].st + tree[node].dr) >> 1;

    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);

    tree[node].maximum = max(tree[node << 1].maximum, tree[(node << 1) + 1].maximum);
}

int getMax(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].maximum;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        return getMax(node << 1, st, dr);
    else if (st > mid)
        return getMax((node << 1) + 1, st, dr);
    else
        return max(getMax(node << 1, st, mid),
                   getMax((node << 1) + 1, mid + 1, dr));
}

void update(int node, int where, int val) {
    if (tree[node].st == where && tree[node].dr == where) {
        tree[node].maximum = val;
        v[where] = val;
        return ;
    }

    int mid = (tree[node].st + tree[node].dr ) >> 1;
    if (where <= mid)
        update(node << 1, where, val);
    else
        update((node << 1) + 1, where, val);

    tree[node].maximum = max(tree[node << 1].maximum, tree[(node << 1) + 1].maximum);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    build(1, 1, N);

    while (1) {
        int where = 0;
        int val = 0;

        vector <int> vv;
        while (1) {
            int st = where + 1;
            int dr = N;
            int ans = N + 1;
            while (st <= dr) {
                int mid = (st + dr) >> 1;
                if (getMax(1, where + 1, mid) > val) {
                    ans = mid;
                    dr = mid - 1;
                }
                else
                    st = mid + 1;
            }

            if (ans == N + 1)
                break;
            else {
                vv.push_back(v[ans]);
                where = ans;
                val = v[ans];
                update(1, ans, -1);
            }
        }

        if (vv.size() == 0)
            return 0;
        for (int i = 0; i < vv.size(); ++ i)
            cout << vv[i] << " \n"[i + 1 == vv.size()];
    }

    return 0;
}