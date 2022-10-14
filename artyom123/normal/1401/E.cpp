#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;
const int MAXC = 1e6 + 10;


mt19937 gen(time(0));

struct Node{
    int x, y, sz;
    Node *left, *right;
    Node(int _x) {
        x = _x;
        sz = 1;
        y = gen();
        left = right = nullptr;
    }
};

ll get_size(Node *root) {
    return (root == nullptr ? 0 : root->sz);
}

void update(Node *root) {
    root->sz = get_size(root->left) + get_size(root->right) + 1;
}

Node *merge(Node *L, Node *R) {
    if (L == nullptr) return R;
    if (R == nullptr) return L;
    if (L->y > R->y) {
        L->right = merge(L->right, R);
        update(L);
        return L;
    } else {
        R->left = merge(L, R->left);
        update(R);
        return R;
    }
}

pair<Node*, Node*> split(Node *root, int x) {
    if (root == nullptr) return {nullptr, nullptr};
    if (root->x <= x) {
        auto res = split(root->right, x);
        root->right = res.fi;
        update(root);
        return {root, res.se};
    } else {
        auto res = split(root->left, x);
        root->left = res.se;
        update(root);
        return {res.fi, root};
    }
}

bool exists(Node *root, int x) {
    if (root == nullptr) return false;
    if (root->x == x) return true;
    if (root->x < x) return exists(root->right, x);
    else return exists(root->left, x);
}

Node *insert(Node *root, Node *x) {
    if (root == nullptr) {
        return x;
    }
    if (x->y > root->y) {
        auto res = split(root, x->x);
        x->left = res.fi, x->right = res.se;
        update(x);
        return x;
    }
    if (x->x < root->x) {
        root->left = insert(root->left, x);
        update(root);
        return root;
    } else {
        root->right = insert(root->right, x);
        update(root);
        return root;
    }
}

Node *erase(Node *root, int x) {
    if (root == nullptr) return nullptr;
    if (root->x == x) return merge(root->left, root->right);
    if (x < root->x) {
        root->left = erase(root->left, x);
        update(root);
        return root;
    } else {
        root->right = erase(root->right, x);
        update(root);
        return root;
    }
}

vector<vector<int>> g;

struct hor_seg{
    int l, r, y;
    bool operator< (const hor_seg &a) {
        return y < a.y;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<hor_seg> a(n);
    for (auto &c : a) {
        cin >> c.y >> c.l >> c.r;
    }
    sort(all(a));
    vector<vector<int>> add(MAXC), del(MAXC);
    ll ans = 1;
    Node *root = nullptr;
    for (int i = 0; i < m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        if (l == 0 && r == (int)1e6) {
            ans++;
        } else {
            if (l == 0) del[r + 1].pb(x);
            else add[l].pb(x);
        }
        if (l == 0) {
            Node *tmp = new Node(x);
            root = insert(root, tmp);
        }
    }
    int i = 0;
    for (int y = 1; y < (int)1e6; y++) {
        for (auto &x : add[y]) {
            Node *tmp = new Node(x);
            root = insert(root, tmp);
        }
        for (auto &x : del[y]) {
            root = erase(root, x);
        }
        while (i < n && a[i].y == y) {
            if (a[i].l == 0) {
                auto tmp = split(root, a[i].r);
                ans += get_size(tmp.fi);
                root = merge(tmp.fi, tmp.se);
            } else {
                auto tmp = split(root, a[i].l - 1);
                ans += get_size(tmp.se);
                root = merge(tmp.fi, tmp.se);
            }
            if (a[i].l == 0 && a[i].r == (int)1e6) ans++;
            i++;
        }
    }
    cout << ans;
    return 0;
}