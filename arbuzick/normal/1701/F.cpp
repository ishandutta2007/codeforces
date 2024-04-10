#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    Node *l, *r;
    int x, y;
    int sum, sz;
    long long pr, suf, pr_sum, suf_sum, pr_push, suf_push;

    Node(int _x) {
        x = _x;
        y = rnd();
        l = r = nullptr;
        pr = suf = pr_sum = suf_sum = pr_push = suf_push = 0;
        sum = sz = 1;
    }
};

int sz(Node *root) {
    if (!root) {
        return 0;
    }
    return root->sz;
}

int sum(Node *root) {
    if (!root) {
        return 0;
    }
    return root->sum;
}

long long pr_sum(Node *root) {
    if (!root) {
        return 0;
    }
    return root->pr_sum;
}

long long suf_sum(Node *root) {
    if (!root) {
        return 0;
    }
    return root->suf_sum;
}

void relax(Node *root) {
    if (!root) {
        return;
    }
    root->sz = sz(root->l) + 1 + sz(root->r);
    root->sum = sum(root->l) + 1 + sum(root->r);
    root->pr_sum = pr_sum(root->l) + root->pr + pr_sum(root->r);
    root->suf_sum = suf_sum(root->l) + root->suf + suf_sum(root->r);
}

void push(Node *root) {
    if (!root) {
        return;
    }
    if (root->l) {
        root->l->pr += root->pr_push;
        root->l->pr_sum += root->pr_push * sz(root->l);
        root->l->pr_push += root->pr_push;
        root->l->suf += root->suf_push;
        root->l->suf_sum += root->suf_push * sz(root->l);
        root->l->suf_push += root->suf_push;
    }
    if (root->r) {
        root->r->pr += root->pr_push;
        root->r->pr_sum += root->pr_push * sz(root->r);
        root->r->pr_push += root->pr_push;
        root->r->suf += root->suf_push;
        root->r->suf_sum += root->suf_push * sz(root->r);
        root->r->suf_push += root->suf_push;
    }
    root->pr_push = root->suf_push = 0;
}

pair<Node *, Node *> split(Node *root, int val) {
    if (!root) {
        return {nullptr, nullptr};
    }
    push(root);
    if (root->x <= val) {
        auto [root1, root2] = split(root->r, val);
        root->r = root1;
        relax(root);
        return {root, root2};
    } else {
        auto [root1, root2] = split(root->l, val);
        root->l = root2;
        relax(root);
        return {root1, root};
    }
}

Node *merge(Node *root1, Node *root2) {
    if (!root1) {
        return root2;
    }
    if (!root2) {
        return root1;
    }
    if (root1->y < root2->y) {
        push(root1);
        root1->r = merge(root1->r, root2);
        relax(root1);
        return root1;
    } else {
        push(root2);
        root2->l = merge(root1, root2->l);
        relax(root2);
        return root2;
    }
}

void solve() {
    int q, d;
    cin >> q >> d;
    long long ans = 0;
    Node *root = nullptr;
    while (q--) {
        int a;
        cin >> a;
        auto [root_lm, root_r] = split(root, a);
        auto [root_l, root_m] = split(root_lm, a - 1);
        if (!root_m) {
            ans -= pr_sum(root_l) + suf_sum(root_r);
            root = merge(root_l, root_r);
            ans += pr_sum(root);
            auto [root_l, root_r] = split(root, a);
            auto nw = new Node(a);
            auto [root_l1, root_l2] = split(root_l, a - d - 1);
            ans += sz(root_l2) * 1LL * (sz(root_l2) - 1) / 2;
            nw->pr = sz(root_l2);
            nw->pr_sum = sz(root_l2);
            if (root_l2) {
                root_l2->suf++;
                root_l2->suf_push++;
                root_l2->suf_sum += sz(root_l2);
            }
            root_l = merge(root_l1, root_l2);
            auto [root_r1, root_r2] = split(root_r, a + d);
            ans += sz(root_r1) * 1LL * (sz(root_r1) - 1) / 2;
            nw->suf = sz(root_r1);
            nw->suf_sum = sz(root_r1);
            if (root_r1) {
                root_r1->pr++;
                root_r1->pr_push++;
                root_r1->pr_sum += sz(root_r1);
            }
            root_r = merge(root_r1, root_r2);
            root = merge(merge(root_l, nw), root_r);
        } else {
            root = merge(root_l, root_r);
            auto [root_l, root_r] = split(root, a);
            auto [root_l1, root_l2] = split(root_l, a - d - 1);
            ans -= sz(root_l2) * 1LL * (sz(root_l2) - 1) / 2;
            if (root_l2) {
                root_l2->suf--;
                root_l2->suf_push--;
                root_l2->suf_sum -= sz(root_l2);
            }
            root_l = merge(root_l1, root_l2);
            auto [root_r1, root_r2] = split(root_r, a + d);
            ans -= sz(root_r1) * 1LL * (sz(root_r1) - 1) / 2;
            if (root_r1) {
                root_r1->pr--;
                root_r1->pr_push--;
                root_r1->pr_sum -= sz(root_r1);
            }
            root_r = merge(root_r1, root_r2);
            ans += pr_sum(root_l) + suf_sum(root_r);
            root = merge(root_l, root_r);
            ans -= pr_sum(root);
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}