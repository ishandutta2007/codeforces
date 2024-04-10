#include <bits/stdc++.h>

using namespace std;

const int len = 17;

struct Node {
    Node *go[2];
    int val;

    Node() {
        go[0] = go[1] = nullptr;
        val = 0;
    }
};

void add_number(Node *root, int number) {
    Node *nw = root;
    for (int i = len - 1; i >= 0; --i) {
        if (!nw->go[(number >> i) & 1]) {
            nw->go[(number >> i) & 1] = new Node();
        }
        nw = nw->go[(number >> i) & 1];
    }
    nw->val = number;
}

int find_max(Node *root, int number) {
    Node *nw = root;
    for (int i = len - 1; i >= 0; --i) {
        if (!nw->go[((number >> i) & 1) ^ 1]) {
            nw = nw->go[(number >> i) & 1];
        } else {
            nw = nw->go[((number >> i) & 1) ^ 1];
        }
    }
    return nw->val ^ number;
}

int find_min(Node *root, int number) {
    Node *nw = root;
    for (int i = len - 1; i >= 0; --i) {
        if (!nw->go[(number >> i) & 1]) {
            nw = nw->go[((number >> i) & 1) ^ 1];
        } else {
            nw = nw->go[(number >> i) & 1];
        }
    }
    return nw->val ^ number;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    Node *root = new Node();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        add_number(root, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int x = a[i] ^ l;
        if (l <= find_min(root, x) && find_max(root, x) <= r) {
            cout << x << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}