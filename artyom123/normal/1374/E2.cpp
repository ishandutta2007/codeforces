#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

mt19937 gen(time(0));

struct Treap{
    struct Node{
        pair<int, int> val;
        int pr, sz, sum;
        Node *left, *right;
        Node(pair<int, int> _val) {
            val = _val;
            pr = gen();
            left = right = nullptr;
            sz = 1;
            sum = _val.fi;
        }
    };

    Node *root = nullptr;

    int get_size(Node* root) {
        if (root == nullptr) return 0;
        return root->sz;
    }

    int get_sum(Node *root) {
        if (root == nullptr) return 0;
        return root->sum;
    }

    void update(Node *root) {
        root->sz = 1 + get_size(root->left) + get_size(root->right);
        root->sum = root->val.fi + get_sum(root->left) + get_sum(root->right);
    }

    Node* merge(Node *L, Node *R) {
        if (L == nullptr) return R;
        if (R == nullptr) return L;
        if (L->pr < R->pr) {
            L->right = merge(L->right, R);
            update(L);
            return L;
        } else {
            R->left = merge(L, R->left);
            update(R);
            return R;
        }
    }

    pair<Node*, Node*> split_kth(Node *root, int k) {
        if (root == nullptr) return {nullptr, nullptr};
        if (get_size(root->left) >= k) {
            auto res = split_kth(root->left, k);
            root->left = res.se;
            update(root);
            return {res.fi, root};
        } else {
            auto res = split_kth(root->right, k - get_size(root->left) - 1);
            root->right = res.fi;
            update(root);
            return {root, res.se};
        }
    }

    pair<Node*, Node*> split(Node *root, pair<int, int> val) {
        if (root == nullptr) return {nullptr, nullptr};
        if (root->val <= val) {
            auto res = split(root->right, val);
            root->right = res.fi;
            update(root);
            return {root, res.se};
        } else {
            auto res = split(root->left, val);
            root->left = res.se;
            update(root);
            return {res.fi, root};
        }
    }

    Node* insert(Node *root, Node *x) {
        if (root == nullptr) return x;
        if (x->pr < root->pr) {
            auto res = split(root, x->val);
            x->left = res.fi;
            x->right = res.se;
            update(x);
            return x;
        }
        if (x->val < root->val) {
            auto res = insert(root->left, x);
            root->left = res;
            update(root);
            return root;
        } else {
            auto res = insert(root->right, x);
            root->right = res;
            update(root);
            return root;
        }
    }

    void insert(pair<int, int> val) {
        Node *x = new Node(val);
        root = insert(root, x);
    }

    Node* erase(Node *root, pair<int, int> val) {
        if (root->val == val) {
            return merge(root->left, root->right);
        }
        if (val < root->val) {
            root->left = erase(root->left, val);
            update(root);
            return root;
        } else {
            root->right = erase(root->right, val);
            update(root);
            return root;
        }
    }

    void erase(pair<int, int> val) {
        root = erase(root, val);
    }

    int sum_of_first_k(int k) {
        auto res = split_kth(root, k);
        int ans = get_sum(res.fi);
        root = merge(res.fi, res.se);
        return ans;
    }

    void dfs(Node *root) {
        if (root == nullptr) return;
        dfs(root->left);
        cout << root->val.se + 1 << " ";
        dfs(root->right);
    }

    void print_first_k(int k) {
        auto res = split_kth(root, k);
        dfs(res.fi);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Treap lol;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> both, f, s, no;
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a == 1 && b == 1) both.pb(t, i);
        if (a == 1 && b == 0) f.pb(t, i);
        if (a == 0 && b == 1) s.pb(t, i);
        if (a == 0 && b == 0) no.pb(t, i);
    }
    sort(all(both));
    sort(all(f));
    sort(all(s));
    sort(all(no));
    for (auto &c : no) lol.insert(c);
    for (auto &c : both) lol.insert(c);
    int ans = INF;
    int ho = f.size() - 1, ha = s.size() - 1;
    vector<int> prboth(both.size() + 1), prf(f.size() + 1), prs(s.size() + 1);
    for (int i = 0; i < (int)both.size(); i++) {
        prboth[i + 1] = prboth[i] + both[i].fi;
    }
    for (int i = 0; i < (int)f.size(); i++) {
        prf[i + 1] = prf[i] + f[i].fi;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        prs[i + 1] = prs[i] + s[i].fi;
    }
    for (int i = 0; i <= k && i <= (int)both.size(); i++) {
        if (i > 0) lol.erase(both[i - 1]);
        int kek = k - i;
        if (kek > (int)f.size() || kek > (int)s.size()) continue;
        /// 0...kek - 1
        while (ho >= kek) {
            lol.insert(f[ho]);
            ho--;
        }
        while (ha >= kek) {
            lol.insert(s[ha]);
            ha--;
        }
        int x = m - i - 2 * kek;
        if (x < 0) continue;
        ans = min(ans, lol.sum_of_first_k(x) + prboth[i] + prf[kek] + prs[kek]);
    }
    if (ans == INF) {
        cout << -1;
        return 0;
    }
    cout << ans << "\n";
    lol.root = nullptr;
    ho = f.size() - 1, ha = s.size() - 1;
    for (auto &c : no) lol.insert(c);
    for (auto &c : both) lol.insert(c);
    for (int i = 0; i <= k && i <= (int)both.size(); i++) {
        if (i > 0) lol.erase(both[i - 1]);
        int kek = k - i;
        if (kek > (int)f.size() || kek > (int)s.size()) continue;
        /// 0...kek - 1
        while (ho >= kek) {
            lol.insert(f[ho]);
            ho--;
        }
        while (ha >= kek) {
            lol.insert(s[ha]);
            ha--;
        }
        int x = m - i - 2 * kek;
        if (x < 0) continue;
        if (ans == lol.sum_of_first_k(x) + prboth[i] + prf[kek] + prs[kek]) {
            for (int j = 0; j < i; j++) cout << both[j].se + 1 << " ";
            for (int j = 0; j < kek; j++) cout << f[j].se + 1 << " ";
            for (int j = 0; j < kek; j++) cout << s[j].se + 1 << " ";
            lol.print_first_k(x);
            return 0;
        }
    }
    return 0;
}