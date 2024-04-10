#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005, Inf = 0x3f3f3f3f;

int getrand() {
    int ret = rand() * 32768 + rand();
    if (ret < 0) ret = -ret;
    return ret;
}

struct Node {
    int key, pry, size, ans, rev;
    Node *left, *right;

    Node() {}

    Node(const int key, const int pry, const int size) {
        this->key = key;
        this->pry = pry;
        this->size = size;
        this->left = NULL;
        this->right = NULL;
        this->rev = 0;
        ans = key;
    }

    inline void update() {
        if (this == NULL)
            return;

        size = left->getsize() + 1 + right->getsize();
        ans = key + left->getans() + right->getans();

        if (rev) {
            rev = 0;
            swap(left, right);

            if (left != NULL)
                left->rev ^= 1;

            if (right != NULL)
                right->rev ^= 1;
        }
    }

    int getsize() const {
        return this == NULL ? 0: size;
    }

    int getans() const {
        return this == NULL ? 0: ans;
    }
};

pair<Node*, Node*> Split(Node* Root, const int pos) {
    if (Root == NULL)
        return make_pair((Node*) NULL, (Node*) NULL);

    Root->update();
    if (pos <= Root->left->getsize() + 1) {
        pair<Node*, Node*> leftsplit = Split(Root->left, pos);
        Root->left = leftsplit.second;
        Root->update();
        return make_pair(leftsplit.first, Root);
    } else {
        pair<Node*, Node*> rightsplit = Split(Root->right, pos - Root->left->getsize() - 1);
        Root->right = rightsplit.first;
        Root->update();
        return make_pair(Root, rightsplit.second);
    }
}

Node* Merge(Node* Left, Node* Right) {
    if (Left == NULL) {
        Right->update();
        return Right;
    }

    if (Right == NULL) {
        Left->update();
        return Left;
    }

    Left->update();
    Right->update();

    if (Left->pry > Right->pry) {
        Left->right = Merge(Left->right, Right);
        Left->update();
        return Left;
    } else {
        Right->left = Merge(Left, Right->left);
        Right->update();
        return Right;
    }
}

Node* Insert(Node* Root, int key) {
    Node* node = new Node(key, getrand(), 1);
    return Merge(Root, node);
}

Node* Root = NULL;
int Add[Nmax];

void GetElem(Node* Root) {
    if (Root == NULL)
        return;

    Root->update();

    GetElem(Root->left);
    Add[++Add[0]] = Root->key;
    GetElem(Root->right);
}

void AddElem(Node *Root, int cnt) {
    if (Root == NULL)
        return;

    Root->update();

    AddElem(Root->left, cnt);
    if (cnt + Root->left->getsize() + 1 <= Add[0])
        Root->key += Add[cnt + Root->left->getsize() + 1];

    if (cnt + Root->left->getsize() + 1 < Add[0])
        AddElem(Root->right, cnt + Root->left->getsize() + 1);

    Root->update();
}

void WriteNode(Node *Root) {
    if (Root == NULL)
        return;

    Root->update();
    WriteNode(Root->left);
    printf("%d ", Root->key);
    WriteNode(Root->right);
}

void Write(Node *Root) {
    WriteNode(Root);
    printf("\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 1; i <= N; ++i)
        Root = Insert(Root, 1);

    while (Q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int pos;
            scanf("%d", &pos);

            if (pos <= N / 2) {
                pair<Node*, Node*> split = Split(Root, pos + 1);
                Node *left = split.first, *right = split.second;

                Add[0] = 0;
                GetElem(left);

                reverse(Add + 1, Add + Add[0] + 1);

                AddElem(right, 0);
                Root = right;

                N -= pos;
            } else {
                pair<Node*, Node*> split = Split(Root, pos + 1);
                Node *left = split.first, *right = split.second;

                Add[0] = 0;
                GetElem(right);

                left->rev ^= 1;

                /*if (pos == 4) {
                    Write(left);
                    Write(right);
                }*/

                AddElem(left, 0);
                Root = left;

                N = pos;
            }

            //Write(Root);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            l++;

            pair<Node*, Node*> split;
            Node *left, *mid, *right;

            split = Split(Root, r + 1);
            mid = split.first;
            right = split.second;

            split = Split(mid, l);
            left = split.first;
            mid = split.second;

            printf("%d\n", mid->getans());

            Root = Merge(Merge(left, mid), right);
        }
    }
}