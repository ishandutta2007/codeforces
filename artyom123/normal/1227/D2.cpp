#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

mt19937 gen(time(0));

struct Treap {
    struct Node {
        int val, pr, sz;
        Node *left, *right;
        Node(int _val) {
            val = _val;
            pr = gen();
            left = right = nullptr;
            sz = 1;
        }
    };

    Node *root = nullptr;

    int get_sz(Node *root) {
        if (root == nullptr) return 0;
        return root->sz;
    }

    void update(Node *root) {
        root->sz = get_sz(root->left) + get_sz(root->right) + 1;
    }

    pair<Node*, Node*> split(Node *root, int x) {
        if (root == nullptr) return {nullptr, nullptr};
        if (root->val < x) {
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

    Node *insert(Node *root, Node *x) {
        if (root == nullptr) return x;
        if (x->pr > root->pr) {
            auto res = split(root, x->val);
            x->left = res.fi; x->right = res.se;
            update(x);
            return x;
        }
        if (root->val > x->val) {
            root->left = insert(root->left, x);
            update(root);
            return root;
        } else {
            root->right = insert(root->right, x);
            update(root);
            return root;
        }
    }

    void insert(int x) {
        Node *tmp = new Node(x);
        root = insert(root, tmp);
    }

    int find_kth(Node *root, int k) {
        if (get_sz(root->left) > k) return find_kth(root->left, k);
        else if (get_sz(root->left) == k) return root->val;
        else return find_kth(root->right, k - 1 - get_sz(root->left));
    }
};

bool cmp(pii &a, pii &b) {
    if (a.fi != b.fi) return a.fi > b.fi;
    return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<pii> kek(n);
    for (int i = 0; i < n; i++) kek[i] = {a[i], i};
    sort(all(kek), cmp);
    vector<vector<pii>> lol(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos; k--; pos--;
        lol[k].pb(pos, i);
    }
    Treap lalala;
    vector<int> ans(m);
    for (int i = 0; i < n; i++) {
        lalala.insert(kek[i].se);
        for (auto &c : lol[i]) {
            ans[c.se] = a[lalala.find_kth(lalala.root, c.fi)];
        }
    }
    for (auto &c : ans) cout << c << "\n";
    return 0;
}