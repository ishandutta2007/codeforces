#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

#define lint long long int
using namespace std;

const int NMAX = 100000 + 5;

const int MOD1 = 1000000000 + 7;
const int C1 = 2;
int pow_C1[NMAX]; // ?

const int MOD2 = 1000000000 + 9;
const int C2 = 73;
int pow_C2[NMAX];

void precalc_MOD() {
    pow_C1[0] = pow_C2[0] = 1;
    for (int i = 1; i < NMAX; ++ i) {
        pow_C1[i] = (1LL * pow_C1[i - 1] * C1) % MOD1;
        pow_C2[i] = (1LL * pow_C2[i - 1] * C2) % MOD2;
    }
}

struct Node {
    int st, dr;

    int sum;
    int hash1, hash2;

    Node *left, *right;

    Node(int _st = 0, int _dr = 0, int _sum = 0, int _hash1 = 0, int _hash2 = 0, Node *_left = NULL, Node *_right = NULL):
        st(_st), dr(_dr), sum(_sum), hash1(_hash1), hash2(_hash2), left(_left), right(_right) {}
} *full[2];

void unite(Node *res, Node *a, Node *b) {
    res -> sum = a -> sum + b -> sum;
    res -> hash1 = (a -> hash1 +
            1LL * b -> hash1 * pow_C1[a -> dr - a -> st + 1]) % MOD1;
    res -> hash2 = (a -> hash2 +
              1LL * b -> hash2 * pow_C2[a -> dr - a -> st + 1]) % MOD2;
}

Node* build(int st, int dr, int val) {
    Node *node = new Node(st, dr);

    if (st == dr) {
        node ->sum = val;
        node -> hash1 = node -> hash2 = val;
        return node;
    }

    int mid = (st + dr) >> 1;

    node -> left = build(st, mid, val);
    node -> right = build(mid + 1, dr, val);

    unite(node, node -> left, node -> right);
    return node;
}

bool NodeCmp(const Node* node1, const Node* node2) {
    if (node1 -> st == node1 -> dr)
        return node1 -> hash1 < node2 -> hash1;

    if (node1 -> right -> hash1 == node2 -> right -> hash1 &&
        node1 -> right -> hash2 == node2 -> right -> hash2)
        return NodeCmp(node1 -> left, node2 -> left);
    else
        return NodeCmp(node1 -> right, node2 -> right);
}

int last_erased;
Node* erase(Node *_node, Node *full, int where) {
    Node *node = new Node(*_node);

    int mid = (node -> st + node -> dr) >> 1;

    //Daca stanga nu a fost inca potrivit
    if (node -> st == where) {
        if (node -> sum == node -> dr - node -> st + 1) {
            last_erased = node -> dr;
            return full;
        }

        if (node -> st == node -> dr)
            return node;

        if (where <= mid) {
            node -> left = erase(node -> left, full -> left, where);
            if (last_erased < mid) {
                unite(node, node -> left, node -> right);
                return node;
            }
        }

        node -> right = erase(node -> right, full -> right, max(mid + 1, where));

        unite(node, node -> left, node -> right);
        return node;
    }

    //Acum capatul stanga este where
    if (where <= mid) {
        node -> left = erase(node -> left, full -> left, where);
        if (last_erased < mid) {
            unite(node, node -> left, node -> right);
            return node;
        }
    }

    node -> right = erase(node -> right, full -> right, max(mid + 1, where));

    unite(node, node -> left, node -> right);
    return node;
}

Node* add(Node *_node, int where) {
    Node *node = new Node(*_node);

    if (node -> st == node -> dr) {
        node -> sum = 1;
        node -> hash1 = node -> hash2 = 1;
        return node;
    }

    int mid = (node -> st + node -> dr) >> 1;


    if (where <= mid)
        node -> left = add(node -> left, where);
    else
        node -> right = add(node -> right, where);

    unite(node, node -> left, node -> right);
    return node;
}

Node* update(Node *_node, int where) {
    last_erased = where - 1;

    Node *node = erase(_node, full[0], where);
    node = add(node, last_erased + 1);

    return node;
}

struct QueueElem {
    Node *dist;
    int node;

    QueueElem(Node *_dist = NULL, int _node = 0):
        dist(_dist), node(_node) {}

    friend bool operator<(const QueueElem &a, const QueueElem &b) {
        return NodeCmp(b.dist, a.dist);
    }
};


int n, m;
vector <pair <int, int> > graph[NMAX];

int s, t;

bool vis[NMAX];
Node *dist[NMAX];
int father[NMAX];

priority_queue <QueueElem> _queue;

int Dijkstra() {
    precalc_MOD();
    full[0] = build(0, NMAX + 100, 0);
    full[1] = build(0, NMAX + 100, 1);

    for (int i = 1; i <= n; ++ i)
        dist[i] = full[1];
    dist[s] = full[0];

    _queue.push(QueueElem(dist[s], s));

    int node;
    while (!_queue.empty()) {
        node = _queue.top().node;
        _queue.pop();

        if (vis[node])
            continue;
        vis[node] = true;

        if (node == t)
            return dist[t] -> hash1;

        for (auto it: graph[node]) {
            Node *dst = update(dist[node], it.second);
            if (NodeCmp(dst, dist[it.first])) {
                dist[it.first] = dst;
                father[it.first] = node;
                _queue.push(QueueElem(dst, it.first));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    int a, b, c;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    cin >> s >> t;

    int dst = Dijkstra();
    cout << dst << '\n';

    vector <int> sol;
    if (dst != -1) {
        while (t != s) {
            sol.push_back(t);
            t = father[t];
        }
        sol.push_back(t);

        reverse(sol.begin(), sol.end());

        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); ++ i)
            cout << sol[i] << " \n"[i + 1 == sol.size()];
    }
    return 0;
}