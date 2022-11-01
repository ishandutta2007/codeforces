#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

const int Nmax = 100005, Inf = 0x3f3f3f3f;

 int getrand() {
    int ret = rand() * 32700 + rand();
    if (ret < 0) ret = -ret;
    if (ret == 0) ++ret;
    return ret;
}

struct Node {
    int pos, priority, ans;
    pair<int, int> key;
    Node *left, *right;

    Node(const pair<int, int>& key, int pos) {
        this->key = key;
        this->pos = pos;
        ans = key.second;
        priority = getrand();
        left = right = NULL;
    }
};

int getAns(Node* node) {
    return node == NULL ? Inf: node->ans;
}

void Update(Node* node) {
    if (node == NULL) return;
    node->ans = node->key.second;
    if (getAns(node->left) < node->ans)
        node->ans = getAns(node->left);
    if (getAns(node->right) < node->ans)
        node->ans = getAns(node->right);
}

Node* Root;

pair<Node*, Node*> Split(Node* Root, const pair<int, int>& key) {
    if (Root == NULL)
        return make_pair((Node*) NULL, (Node*) NULL);

    if (key < Root->key) {
        pair<Node*, Node*> split = Split(Root->left, key);
        Root->left = split.second;
        Update(Root);
        split.second = Root;
        return split;
    } else {
        pair<Node*, Node*> split = Split(Root->right, key);
        Root->right = split.first;
        Update(Root);
        split.first = Root;
        return split;
    }
}

Node* Merge(Node* Left, Node *Right) {
    if (Left == NULL)
        return Right;

    if (Right == NULL)
        return Left;

    if (Left->priority > Right->priority) {
        Left->right = Merge(Left->right, Right);
        Update(Left);
        return Left;
    } else {
        Right->left = Merge(Left, Right->left);
        Update(Right);
        return Right;
    }
}

Node* Insert(Node* Root, const pair<int, int>& key, int val) {
    pair<Node*, Node*> split = Split(Root, key);
    return Merge(Merge(split.first, new Node(key, val)), split.second);
}

struct Quad {
    int left, right, time, pos;
    Quad() {}
    Quad(int _left, int _right, int _time, int _pos) {
        left = _left;
        right = _right;
        time = _time;
        pos = _pos;
    }
    bool operator < (const Quad& other) const {
        return time < other.time;
    }
};

Quad buses[Nmax], queries[Nmax];
int Ans[Nmax];

Node *Dfs(Node* node, int right, int pos) {
    if (node == NULL)
        return NULL;

    if (node->key.second <= right) {
        Node* aux = node;
        Ans[node->pos] = pos;
        node = Merge(node->left, node->right);
        delete aux;
        return (node = Dfs(node, right, pos));
    }
    if (getAns(node->left) <= right) node->left = Dfs(node->left, right, pos);
    if (getAns(node->right) <= right) node->right = Dfs(node->right, right, pos);
    Update(node);
    return node;
}

void getAnswer(int left, int right, int pos) {
    Node *Left, *Mid, *Right;
    tie(Left, Mid) = Split(Root, {left, -1});
    tie(Mid, Right) = Split(Mid, {right + 1, -1});
    Mid = Dfs(Mid, right, pos);
    Root = Merge(Merge(Left, Mid), Right);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    srand(time(0));

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        buses[i] = Quad(x, y, z, i + 1);
    }
    sort(buses, buses + N);

    for (int i = 0; i < M; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        queries[i] = Quad(x, y, z, i);
    }
    sort(queries, queries + M);

    for (int i = 0, j = 0; i < N; ++i) {
        for (; j < M && queries[j].time <= buses[i].time; ++j)
            Root = Insert(Root, make_pair(queries[j].left, queries[j].right), queries[j].pos);
        getAnswer(buses[i].left, buses[i].right, buses[i].pos);
    }

    for (int i = 0; i < M; ++i)
        printf("%d\n", (Ans[i] == 0 ? -1: Ans[i]));
}