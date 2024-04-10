#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lint;

const int NMAX = 100000 + 5;
struct Query {
    int type;
    lint l, r;
} queries[NMAX];

struct Node {
    int st, dr;
    int firstZero;
    int firstOne;
    bool lazyZero;
    bool lazyOne;
    bool lazyFlip;

    void makeLazyZero() {
        lazyZero = true;
        lazyOne = lazyFlip = false;
        firstZero = st;
        firstOne = 256 * NMAX;
    }

    void makeLazyOne() {
        lazyOne = true;
        lazyZero = lazyFlip = false;
        firstOne = st;
        firstZero = 256 * NMAX;
    }

    void makeLazyFlip() {
        swap(firstZero, firstOne);
        if (lazyOne) {
            lazyOne = false;
            lazyZero = true;
        }
        else if (lazyZero) {
            lazyZero = false;
            lazyOne = true;
        }
        else
            lazyFlip ^= 1;
    }
} tree[2 * 3 * 4 * NMAX];

void propagate(int node) {
    Node &n = tree[node];
    if (n.lazyZero) {
        tree[node << 1].makeLazyZero();
        tree[(node << 1) + 1].makeLazyZero();
    }
    else if (n.lazyOne) {
        tree[node << 1].makeLazyOne();
        tree[(node << 1) + 1].makeLazyOne();
    }
    else if (n.lazyFlip) {
        tree[node << 1].makeLazyFlip();
        tree[(node << 1) + 1].makeLazyFlip();
    }
    n.lazyOne = n.lazyZero = n.lazyFlip = false;
}

void redo(int node) {
    tree[node].firstZero = min(tree[node << 1].firstZero, tree[(node << 1) + 1].firstZero);
    tree[node].firstOne = min(tree[node << 1].firstOne, tree[(node << 1) + 1].firstOne);
}

void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    tree[node].firstZero = st;
    tree[node].firstOne = 256 * NMAX;

    if (st == dr)
        return ;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);
}

void updateZero(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr) {
        tree[node].makeLazyZero();
        return ;
    }
    propagate(node);

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        updateZero(node << 1, st, dr);
    else if (st > mid)
        updateZero((node << 1) + 1, st, dr);
    else {
        updateZero(node << 1, st, mid);
        updateZero((node << 1) + 1, mid + 1, dr);
    }
    redo(node);
}

void updateOne(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr) {
        tree[node].makeLazyOne();
        return ;
    }
    propagate(node);

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        updateOne(node << 1, st, dr);
    else if (st > mid)
        updateOne((node << 1) + 1, st, dr);
    else {
        updateOne(node << 1, st, mid);
        updateOne((node << 1) + 1, mid + 1, dr);
    }
    redo(node);
}

void updateFlip(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr) {
        tree[node].makeLazyFlip();
        return ;
    }
    propagate(node);

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        updateFlip(node << 1, st, dr);
    else if (st > mid)
        updateFlip((node << 1) + 1, st, dr);
    else {
        updateFlip(node << 1, st, mid);
        updateFlip((node << 1) + 1, mid + 1, dr);
    }
    redo(node);
}

vector <lint> allVals;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    //freopen("data.in", "r", stdin);

    int N;
    cin >> N;

    allVals.push_back(1);
    for (int i = 1; i <= N; ++ i) {
        cin >> queries[i].type >> queries[i].l >> queries[i].r;

        if (queries[i].l >= 2)
            allVals.push_back(queries[i].l - 1);
        allVals.push_back(queries[i].l);
        allVals.push_back(queries[i].l + 1);


        if (queries[i].r >= 2)
            allVals.push_back(queries[i].r - 1);
        allVals.push_back(queries[i].r);
        allVals.push_back(queries[i].r + 1);
    }

    sort(allVals.begin(), allVals.end());
    allVals.resize(unique(allVals.begin(), allVals.end()) - allVals.begin());

    build(1, 1, allVals.size());

    for (int i = 1; i <= N; ++ i) {
        queries[i].l = lower_bound(allVals.begin(), allVals.end(), queries[i].l) - allVals.begin() + 1;
        queries[i].r = lower_bound(allVals.begin(), allVals.end(), queries[i].r) - allVals.begin() + 1;

        if (queries[i].type == 1)
            updateOne(1, queries[i].l, queries[i].r);
        else if (queries[i].type == 2)
            updateZero(1, queries[i].l, queries[i].r);
        else
            updateFlip(1, queries[i].l, queries[i].r);

        lint ans = tree[1].firstZero;
        ans = allVals[ans - 1];
        cout << ans << '\n';
    }

    return 0;
}