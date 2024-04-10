#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005, KMAX = 10004;

struct Node {
    Node *left, *right;
    int sum;
    Node():
        left(NULL), right(NULL), sum(0) {}
};

int getSum(Node* node) {
    return node == NULL ? 0: node->sum;
}

struct Station {
    int x, r, f;
    bool operator<(const Station& o) const {
        return r > o.r;
    }
};

Node* aints[KMAX];

void update(Node* node, int left, int right, int pos) {
    if (left == right) {
        node->sum = 1;
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) {
            if (node->left == NULL) {
                node->left = new Node();
            }
            update(node->left, left, mid, pos);
        } else {
            if (node->right == NULL) {
                node->right = new Node();
            }
            update(node->right, mid + 1, right, pos);
        }
        node->sum = getSum(node->left) + getSum(node->right);
    }
}

void update(Node* &root, int n, int pos) {
    if (root == NULL) {
        root = new Node();
    }
    update(root, 0, n - 1, pos);
}

int query(Node* node, int left, int right, int lq, int rq) {
    if (node == NULL) {
        return 0;
    }
    if (lq <= left && right <= rq) {
        return node->sum;
    } else {
        int mid = (left + right) / 2;
        int ret = 0;
        if (lq <= mid) {
            ret += query(node->left, left, mid, lq, rq);
        }
        if (rq > mid) {
            ret += query(node->right, mid + 1, right, lq, rq);
        }
        return ret;
    }
}

int query(Node* root, int n, int left, int right) {
    return query(root, 0, n - 1, left, right);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<Station> A(n);
    vector<int> coords;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].r >> A[i].f;
        coords.push_back(A[i].x);
        coords.push_back(A[i].x + A[i].r);
        coords.push_back(A[i].x - A[i].r);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    sort(A.begin(), A.end());
    
    int64_t ans = 0;
    for (const Station& s: A) {
        int left = lower_bound(coords.begin(), coords.end(), s.x - s.r)
            - coords.begin();
        int right = lower_bound(coords.begin(), coords.end(), s.x + s.r)
            - coords.begin();
        for (int i = s.f - k; i <= s.f + k; ++i) {
            if (i >= 0 && i < KMAX) {
                ans += query(aints[i], SZ(coords), left, right);
            }
        }
        int pos = lower_bound(coords.begin(), coords.end(), s.x) - coords.begin();
        update(aints[s.f], SZ(coords), pos);
    }
    cout << ans << '\n';
}