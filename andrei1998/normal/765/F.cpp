#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int a[NMAX];

struct Node {
    int st, dr;
    int minimum;
} tree[4 * NMAX];

const int INF = 2E9;

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    tree[node].minimum = INF;

    if (st == dr)
        return ;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);
}

void update(int node, int where, int val) {
    if (tree[node].st == tree[node].dr) {
        tree[node].minimum = min(tree[node].minimum, val);
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (where <= mid)
        update(node << 1, where, val);
    else
        update((node << 1) + 1, where, val);

    tree[node].minimum = min(tree[node << 1].minimum, tree[(node << 1) + 1].minimum);
}

int queryMin(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].minimum;

    int mid = (tree[node].st + tree[node].dr) >> 1;

    if (dr <= mid)
        return queryMin(node << 1, st, dr);
    else if (st > mid)
        return queryMin((node << 1) + 1, st, dr);
    else
        return min(queryMin(node << 1, st, mid),
                   queryMin((node << 1) + 1, mid + 1, dr));
}

int getNext(int node, int start, int atMost) {
    if (tree[node].st == start) {
        if (tree[node].minimum > atMost)
            return 0;
        if (tree[node].st == tree[node].dr)
            return tree[node].st;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;

    int ans = 0;
    if (start <= mid)
        ans = getNext(node << 1, start, atMost);
    if (!ans)
        ans = getNext((node << 1) + 1, max(start, mid + 1), atMost);
    return ans;
}

int getPrev(int node, int start, int atMost) {
    if (tree[node].dr == start) {
        if (tree[node].minimum > atMost)
            return 0;
        if (tree[node].st == tree[node].dr)
            return tree[node].dr;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;

    int ans = 0;
    if (start > mid)
        ans = getPrev((node << 1) + 1, start, atMost);
    if (!ans)
        ans = getPrev(node << 1, min(start, mid), atMost);
    return ans;
}

const int MMAX = 3 * NMAX;

struct Interv {
    bool type;
    int l;
    int val;
    int pos;

    Interv(bool _type = 0, int _l = 0, int _val = 0, int _pos = 0):
        type(_type), l(_l), val(_val), pos(_pos) {}

    friend bool operator<(const Interv &a, const Interv &b) {
        return a.type < b.type;
    }
};

vector <Interv> ops[NMAX];

int answers[MMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N;

    vector <pair <int, int> > allA(N);
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        allA[i - 1] = {-a[i], i};
    }

    sort(allA.begin(), allA.end());

    build(1, 1, N);
    for (int i = 1; i <= N; ++ i) {
        int where = allA[i - 1].second;

        //To right
        int atMost = INF - 1;
        int now = where;
        bool done = false;
        while (!done) {
            if (atMost == a[where])
                done = true;
            now = getNext(1, now, atMost);
            if (!now)
                break;
            atMost = (a[now] + a[where]) / 2;
            ops[now].push_back(Interv(0, where, a[now] - a[where]));
        }

        //To left
        atMost = INF - 1, now = where, done = false;
        while (!done) {
            if (atMost == a[where])
                done = true;
            now = getPrev(1, now, atMost);
            if (!now)
                break;

            atMost = (a[now] + a[where]) / 2;
            ops[where].push_back(Interv(0, now, a[now] - a[where]));
        }
        update(1, where, a[where]);
    }


    int Q = 0;
    cin >> Q;

    for (int i = 1; i <= Q; ++ i) {
        int l, r;
        cin >> l >> r;
        ops[r].push_back(Interv(1, l, 0, i));
    }

    build(1, 1, N);
    for (int i = 1; i <= N; ++ i) {
        sort(ops[i].begin(), ops[i].end());
        for (auto it: ops[i])
            if (it.type == 0)
                update(1, it.l, it.val);
            else
                answers[it.pos] = queryMin(1, it.l, i);
    }

    for (int i = 1; i <= Q; ++ i)
        cout << answers[i] << '\n';
    return 0;
}