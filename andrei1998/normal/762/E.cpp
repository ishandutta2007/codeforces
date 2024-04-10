#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int NMAX = 100000 + 5;

struct Tower {
    int x, r, f;

    friend bool operator<(const Tower &a, const Tower &b) {
        return a.r > b.r;
    }
} towers[NMAX];

vector <int> allX;

int N, K;

const int FREQMAX = 10000 + 5;

struct Node {
    int st, dr;
    int sum;

    int left, right;

    Node(int _st = 0, int _dr = 0): st(_st), dr(_dr) {
        sum = 0;
        left = right = 0;
    }
} roots[FREQMAX], nodes[FREQMAX + NMAX * 2 * 20];

int cntNodes;

int getNewNode(int st, int dr) {
    nodes[++ cntNodes] = Node(st, dr);
    return cntNodes;
}

void insert(int node, int where) {
    ++ nodes[node].sum;
    if (nodes[node].st == nodes[node].dr)
        return ;

    int mid = (nodes[node].st + nodes[node].dr) >> 1;
    if (where <= mid) {
        if (nodes[node].left == 0)
            nodes[node].left = getNewNode(nodes[node].st, mid);
        insert(nodes[node].left, where);
    }
    else {
        if (nodes[node].right == 0)
            nodes[node].right = getNewNode(mid + 1, nodes[node].dr);
        insert(nodes[node].right, where);
    }
}

long long int ans;
void query(int node, int st, int dr) {
    if (node == NULL)
        return ;

    if (nodes[node].st == st && nodes[node].dr == dr) {
        ans += nodes[node].sum;
        return ;
    }

    int mid = (nodes[node].st + nodes[node].dr) >> 1;
    if (dr <= mid)
        query(nodes[node].left, st, dr);
    else if (st > mid)
        query(nodes[node].right, st, dr);
    else {
        query(nodes[node].left, st, mid);
        query(nodes[node].right, mid + 1, dr);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; ++ i) {
        cin >> towers[i].x >> towers[i].r >> towers[i].f;

        allX.push_back(towers[i].x - towers[i].r);
        allX.push_back(towers[i].x);
        allX.push_back(towers[i].x + towers[i].r);
    }

    sort(allX.begin(), allX.end());
    allX.resize(unique(allX.begin(), allX.end()) - allX.begin());
    sort(towers + 1, towers + N + 1);

    for (int i = 1; i <= FREQMAX - 5; ++ i)
        roots[i] = getNewNode(1, allX.size());

    for (int i = 1; i <= N; ++ i) {
        int st = lower_bound(allX.begin(), allX.end(), towers[i].x - towers[i].r) - allX.begin() + 1;
        int dr = lower_bound(allX.begin(), allX.end(), towers[i].x + towers[i].r) - allX.begin() + 1;
        int pos = lower_bound(allX.begin(), allX.end(), towers[i].x) - allX.begin() + 1;

        for (int j = -K; j <= K; ++ j)
            if (towers[i].f + j > 0 && towers[i].f + j <= FREQMAX - 5)
                query(towers[i].f + j, st, dr);

        insert(towers[i].f, pos);
    }

    cout << ans << '\n';
    return 0;
}