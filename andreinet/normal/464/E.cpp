#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MOD1 = (int) 1e9 + 7, MOD2 = (int) 1e6 + 33;
const int NMAX = 100045, URIGHT = NMAX - 6;

int xh1[NMAX], xh2[NMAX];

class Hash {
public:
    int v1, v2, len;
    Hash():
        v1(0), v2(0), len(0) {}
    Hash(int _v1, int _v2, int _len):
        v1(_v1), v2(_v2), len(_len) {}
    
    bool operator==(const Hash& o) const {
        return v1 == o.v1 && v2 == o.v2;
    }
    Hash operator*(const Hash& o) const {
        return Hash(((int64_t) v1 * xh1[o.len] + o.v1) % MOD1,
                    ((int64_t) v2 * xh2[o.len] + o.v2) % MOD2,
                    len + o.len);
    }
};

struct Node {
    Node *left = nullptr, *right = nullptr;
    Hash h = Hash(0, 0, 0);
    int sum = 0;

    void update() {
        sum = 0;
        int plen = h.len;
        h = Hash(0, 0, plen / 2);
        if (right != nullptr) {
            sum = right->sum;
            h = right->h;
        }
        if (left != nullptr) {
            sum += left->sum;
            h = h * left->h;
        } else {
            h = h * Hash(0, 0, (plen + 1) / 2);
        }
    }
};

vector<Node> aintNodes;

Node* newNode(int len) {
    if (aintNodes.size() == aintNodes.capacity()) {
        cout << "-1337" << endl;
        exit(0);
    }
    aintNodes.push_back(Node());
    aintNodes.back().h.len = len;
    return &aintNodes.back();
}

int compare(const Node* a, const Node* b, int left, int right) {
    Hash h1 = a == nullptr ? Hash(): a->h;
    Hash h2 = b == nullptr ? Hash(): b->h;
    if (h1 == h2) {
        return 0;
    } else if (left == right) {
        return h1.v1 < h2.v1 ? -1: 1;
    } else if (a == nullptr) {
        return -1;
    } else if (b == nullptr) {
        return 1;
    } else {
        int mid = (left + right) / 2;
        int c = compare(a->right, b->right, mid + 1, right);
        if (c == 0) {
            return compare(a->left, b->left, left, mid);
        } else {
            return c;
        }
    }
}

struct cmp {
    bool operator()(const pair<Node*, int> a, const pair<Node*, int>& b) {
        return compare(a.first, b.first, 0, URIGHT) > 0;
    }
};

pair<Node*, bool> add(Node* node, int left, int right, int where) {
    if (where <= left) {
        if (node != nullptr && node->sum == right - left + 1) {
            return make_pair(newNode(right - left + 1), false);
        } else if (left == right) {
            Node *aux = newNode(right - left + 1);
            if (node != nullptr) {
                *aux = *node;
            }
            swap(aux, node);

            node->sum = 1;
            node->h = Hash(1, 1, 1);
            return make_pair(node, true);
        } else {
            Node *aux = newNode(right - left + 1);
            if (node != nullptr) {
                *aux = *node;
            }
            swap(aux, node);

            int mid = (left + right) / 2;
            pair<Node*, bool> leftq = add(node->left, left, mid, where);
            node->left = leftq.first;
            if (!leftq.second) {
                node->right = add(node->right, mid + 1, right, where).first;
            }
            node->update();
            return make_pair(node, true);
        }
    } else {
        Node *aux = newNode(right - left + 1);
        if (node != nullptr) {
            *aux = *node;
        }
        swap(aux, node);

        int mid = (left + right) / 2;
        bool did = false;
        if (where <= mid) {
            pair<Node*, int> leftq = add(node->left, left, mid, where);
            node->left = leftq.first;
            did = leftq.second;
        }
        if (!did) {
            pair<Node*, int> rightq = add(node->right, mid + 1, right, where);
            node->right = rightq.first;
            did = rightq.second;
        }
        node->update();
        return make_pair(node, did);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    aintNodes.reserve(300 * NMAX);

    int n, m;
    cin >> n >> m;

    xh1[0] = xh2[0] = 1;
    for (int i = 1; i < NMAX - 2; ++i) {
        xh1[i] = 2 * xh1[i - 1] % MOD1;
        xh2[i] = 2 * xh2[i - 1] % MOD2;
    }

    Node* root = newNode(URIGHT + 1);

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        graph[x].push_back(make_pair(y, c));
        graph[y].push_back(make_pair(x, c));
    }
    int s, t;
    cin >> s >> t;
    s--; t--;

    vector<Node*> dist(n, nullptr);
    dist[s] = root;
    vector<int> from(n, -1);
    priority_queue<pair<Node*, int>, vector<pair<Node*, int>>, cmp> q;
    q.push(make_pair(root, s));

    Node* ndist = add(root, 0, URIGHT, 2).first;
    
    while (!q.empty()) {
        int node = q.top().second;
        Node* cdist = q.top().first;
        q.pop();

        if (cdist != dist[node]) {
            continue;
        }

        if (node == t) {
            break;
        }

        for (const pair<int, int>& to: graph[node]) {
            int lastSize = SZ(aintNodes);
            Node* ndist = add(cdist, 0, URIGHT, to.second).first;
            if (dist[to.first] == nullptr ||
                    compare(ndist, dist[to.first], 0, URIGHT) < 0) {
                dist[to.first] = ndist;
                from[to.first] = node;
                q.push(make_pair(ndist, to.first));
            } else {
                aintNodes.resize(lastSize);
            }
        }
    }

    if (dist[t] == nullptr) {
        cout << "-1\n";
    } else {
        cout << dist[t]->h.v1 << '\n';
        vector<int> path;
        for (int i = t; i != -1; i = from[i]) {
            path.push_back(i);
        }
        cout << SZ(path) << '\n';
        reverse(path.begin(), path.end());
        for (int node: path) {
            cout << node + 1 << ' ';
        }
        cout << '\n';
    }
}