#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 300005;

class Node {
public:
    int key, pry, xnode, maxNode;
    Node *left, *right;
 
    Node(int _key, int _node):
        key(_key), pry(get_random()),
        xnode(_node), maxNode(_node),
        left(NULL), right(NULL) {}
private:
    int get_random() {
        return (rand() << 16) + rand();
    }
};

int nodeValues[NMAX];

void update(Node* node) {
    node->maxNode = node->xnode;
    if (node->left != nullptr &&
            nodeValues[node->left->maxNode] > nodeValues[node->maxNode]) {
        node->maxNode = node->left->maxNode;
    }
    if (node->right != nullptr &&
            nodeValues[node->right->maxNode] > nodeValues[node->maxNode]) {
        node->maxNode = node->right->maxNode;
    }
}
 
pair<Node*, Node*> split(Node *node, int val) {
    if (node == NULL)
        return make_pair((Node*) NULL, (Node*) NULL);
 
    if (val <= node->key) {
        pair<Node*, Node*> spl = split(node->left, val);
        node->left = spl.second;
        update(node);
        spl.second = node;
        return spl;
    } else {
        pair<Node*, Node*> spl = split(node->right, val);
        node->right = spl.first;
        update(node);
        spl.first = node;
        return spl;
    }
}
 
Node *merge(Node *left, Node *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
 
    if (left->pry > right->pry) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

Node *insert(Node *root, int val, int node) {
    pair<Node*, Node*> spl = split(root, val);
    return merge(merge(spl.first, new Node(val, node)), spl.second);
}

Node *insert(Node *root, Node *p) {
    pair<Node*, Node*> spl = split(root, p->key);
    p->left = p->right = NULL;
    update(p);
    return merge(merge(spl.first, p), spl.second);
}

int father[NMAX];
vector<int> tree[NMAX];
int treeSize[NMAX];

Node *roots[NMAX];
int answers[NMAX];

void getNodes(vector<Node*> a, Node *node) {
    if (node == nullptr) {
        return;
    }
    getNodes(a, node->left);
    a.push_back(node);
    getNodes(a, node->right);
}

void dfs(int node) {
    treeSize[node] = 1;
    int maxSubtree = 0;
    int leaf = -1;
    for (int to: tree[node]) {
        dfs(to);
        treeSize[node] += treeSize[to];
        if (treeSize[to] > maxSubtree) {
            maxSubtree = treeSize[to];
            leaf = to;
        }
    }
    nodeValues[node] = treeSize[node];
    Node *croot = leaf != -1 ? roots[leaf]: nullptr;
    croot = insert(croot, maxSubtree, node);
    for (int to: tree[node]) {
        if (to != leaf) {
            vector<Node*> a;
            getNodes(a, roots[to]);
            for (Node* p: a) {
                croot = insert(croot, p);
            }
        }
    }

    pair<Node*, Node*> spl = split(croot, treeSize[node] / 2 + 1);
    answers[node] = spl.first->maxNode;
    croot = merge(spl.first, spl.second);

    roots[node] = croot;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(875927L);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        cin >> father[i];
        father[i]--;
        tree[father[i]].push_back(i);
    }
    dfs(0);

    while (q-- > 0) {
        int node;
        cin >> node;
        node--;

        cout << answers[node] + 1 << '\n';
    }
}