#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000005;

string A;
struct Node {
    int asc, desc, v1, v2;
    bool lazy;
    
    void swap() {
        ::swap(asc, desc);
        ::swap(v1, v2);
    }
};

Node aint[4 * NMAX];

void updateNode(int node) {
    aint[node].v1 = aint[2 * node + 1].v1 + aint[2 * node + 2].v1;
    aint[node].v2 = aint[2 * node + 1].v2 + aint[2 * node + 2].v2;
    aint[node].asc = max(aint[2 * node + 1].v1 + aint[2 * node + 2].asc,
                         aint[2 * node + 1].asc + aint[2 * node + 2].v2);
    aint[node].desc = max(aint[2 * node + 1].desc + aint[2 * node + 2].v1,
                          aint[2 * node + 1].v2 + aint[2 * node + 2].desc);
}

void build(int node, int left, int right) {
    if (left == right) {
        (A[left] == '4' ? aint[node].v1: aint[node].v2) = 1;
        aint[node].asc = aint[node].desc = 1;
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        updateNode(node);
    }
}

void split(int node, int left, int right) {
    if (aint[node].lazy) {
        if (left < right) {
            aint[2 * node + 1].lazy ^= true;
            aint[2 * node + 2].lazy ^= true;
        }
        aint[node].lazy = false;
        aint[node].swap();
    }
}

void update(int node, int left, int right, int lq, int rq) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        aint[node].lazy ^= true;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            update(2 * node + 1, left, mid, lq, rq);
        }
        if (rq > mid) {
            update(2 * node + 2, mid + 1, right, lq, rq);
        }
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        updateNode(node);
    }
}

int query(int n) {
    split(0, 0, n - 1);
    return aint[0].asc;
}

char op[10];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> A;

    build(0, 0, n - 1);

    while (m-- > 0) {
        cin >> op;
        if (op[0] == 'c') {
            cout << query(n) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            update(0, 0, n - 1, l - 1, r - 1);
        }
    }
}