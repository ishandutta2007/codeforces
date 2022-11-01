#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int currentId = 0;

struct Node {
    int id = currentId++;
    int cost = 0;
    Node *links[26] = {0};
    Node *fail = nullptr;
};

vector<Node> nodes;

Node* newNode() {
    nodes.push_back(Node());
    return &nodes.back();
}

void add(const string& s, int pos, Node *node, int cost) {
    if (pos == SZ(s)) {
        node->cost += cost;
    } else {
        int x = s[pos] - 'a';
        if (node->links[x] == nullptr) {
            node->links[x] = newNode();
        }
        add(s, pos + 1, node->links[x], cost);
    }
}

void setFail(Node* root) {
    root->fail = root;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                Node* k;
                for (k = node->fail; k != root && !k->links[i]; k = k->fail);
                if (k->links[i] != node->links[i] && k->links[i]) {
                    k = k->links[i];
                }
                node->links[i]->fail = k;
                node->links[i]->cost += k->cost;
                q.push(node->links[i]);
            }
        }
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

    int n;
    int64_t m;
    cin >> n >> m;

    nodes.reserve(10000);

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    Node *root = newNode();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add(s, 0, root, costs[i]);
    }
    int k = currentId;
    const int64_t LINF = 1LL << 62;
    vector<vector<int64_t>> unit(k, vector<int64_t>(k, -LINF));
    setFail(root);
    vector<vector<int64_t>> fdist(k, vector<int64_t>(k, -LINF));
    for (int i = 0; i < k; ++i) {
        fdist[i][i] = 0;
        unit[i][i] = 0;
    }
    for (Node& node: nodes) {
        for (int i = 0; i < 26; ++i) {
            Node *p = &node;
            while (p != root && !p->links[i]) {
                p = p->fail;
            }
            if (p->links[i]) {
                p = p->links[i];
            }
            unit[node.id][p->id] = p->cost;
        }
    }
    while (m > 0) {
        if (m & 1) {
            vector<vector<int64_t>> ndist(k, vector<int64_t>(k, -LINF));
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    for (int l = 0; l < k; ++l) {
                        ndist[i][j] = max(ndist[i][j], fdist[i][l] + unit[l][j]);
                    }
                }
            }
            fdist = ndist;
        }
        vector<vector<int64_t>> ndist(k, vector<int64_t>(k, -LINF));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < k; ++l) {
                    ndist[i][j] = max(ndist[i][j], unit[i][l] + unit[l][j]);
                }
            }
        }
        unit = ndist;
        m /= 2;
    }

    int64_t ans = *max_element(fdist[0].begin(), fdist[0].end());
    cout << ans << '\n';
}