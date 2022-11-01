#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 300005;

struct Node {
    Node *links[26] = {0};
    int size = 1, tsize = 1;
    int c;

    Node() {}
    Node(int _c):
        c(_c) {}
};

vector<int> graph[NMAX];
string S;
int sizes[NMAX];

void setSize(Node* a) {
    a->size = 1;
    for (int i = 0; i < 26; ++i)
        if (a->links[i])
            a->size += a->links[i]->size;
}

void *merge(Node* &a, Node* b) {
    for (int i = 0; i < 26; ++i) {
        if (a->links[i] && b->links[i]) {
            merge(a->links[i], b->links[i]);
        } else if (b->links[i]) {
            a->links[i] = b->links[i];
        }
    }
    setSize(a);
}

Node* dfs(int node, int prev) {
    vector<Node*> sons;
    for (int p: graph[node])
        if (p != prev)
            sons.push_back(dfs(p, node));
    if (sons.empty()) {
        sizes[node] = 1;
        return new Node(S[node] - 'a');
    }

    Node *root = new Node(S[node] - 'a');
    for (Node* p: sons) root->tsize += p->tsize;
    for (int i = 0; i < 26; ++i) {
        Node* nmax = NULL;
        for (Node* current: sons) {
            if (current->c == i &&
                    (!nmax || current->tsize > nmax->tsize))
                        nmax = current;
        }
        if (!nmax) continue;
        Node *cson = nmax;
        for (Node* current: sons) {
            if (current->c == i && current != nmax)
                merge(cson, current);
            root->links[i] = cson;
        }
    }
    setSize(root);
    sizes[node] = root->size;
    return root;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cin >> S;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(0, -1);

    int vmax = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] + sizes[i] > vmax) {
            vmax = A[i] + sizes[i];
            cnt = 1;
        } else if (A[i] + sizes[i] == vmax) {
            cnt++;
        }
    }
    cout << vmax << endl << cnt << endl;
}