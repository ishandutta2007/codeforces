#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

// [!] duplicates allowed
struct BST {

private:

    struct Node {
        int val, height = 0, cnt = 1;
        Node *left = nullptr, *right = nullptr;

        explicit Node(const int val) : val(val) {}

        void updateVars() {
            height = 0, cnt = 1;
            for (const Node *child : {left, right})
                if (child) {
                    height = max(height, child->height + 1);
                    cnt += child->cnt;
                }
        }
    };

    void rotateLeft(Node *&x) {
        Node *const y = x->right;
        x->right = y->left;
        y->left = x;
        x->updateVars();
        y->updateVars();
        x = y;
    }

    void rotateRight(Node *&x) {
        Node *const y = x->left;
        x->left = y->right;
        y->right = x;
        x->updateVars();
        y->updateVars();
        x = y;
    }

    void balance(Node *&node) {
        const auto height = [](const Node *node) {
            return node ? node->height : -1;
        };

        const int diff = height(node->left) - height(node->right);
        if (diff > 1) { // left heavy
            Node *&x = node->left;
            if (height(x->left) < height(x->right))
                rotateLeft(x);
            rotateRight(node);
        } else if (diff < -1) { // right heavy
            Node *&x = node->right;
            if (height(x->right) < height(x->left))
                rotateRight(x);
            rotateLeft(node);
        }
        assert((height(node->left) - height(node->right)) <= 1);
    }


    void insert(Node *&node, const int val) {
        if (node == nullptr)
            node = new Node(val);
        else {
            if (val < node->val)
                insert(node->left, val);
            else
                insert(node->right, val);
            node->updateVars();
            balance(node);
        }
    }

    int valAtRank(Node *node, int k) const {
        for (;;) {
            if (node->left) {
                if (k < node->left->cnt) {
                    node = node->left;
                    continue;
                }
                k -= node->left->cnt;
            }
            if (k == 0)
                return node->val;
            k--;
            node = node->right;
        }
    }

    Node *root = nullptr;

public:

    int size() const { return root ? root->cnt : 0; }

    void insert(const int val) {
        insert(root, val);
    }

    int valAtRank(const int k) const {
        assert(0 <= k && k < size());
        return valAtRank(root, k);
    }
};

const int MxN = (int) 5e5 + 9;
const int MxQ = (int) 5e5 + 9;
const ll MxK = (ll) 1e18 + 9;

struct Query {
    int i;
    ll k;

    bool operator<(const Query &other) const {
        return k < other.k;
    }
};


int a[MxN + 9]; // number of times city i hosted
int cnt[MxN + 9];
ll cs[MxN + 9];

Query queries[MxQ + 9];
int ans[MxQ + 9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= m; ++i)
        cnt[a[i]]++;

    for (int i = 0; i <= n; ++i) {
        cs[i] = (ll) cnt[i] * i;
        if (i) {
            cnt[i] += cnt[i - 1];
            cs[i] += cs[i - 1];
        }
    }

    for (int i = 0; i < q; ++i) {
        queries[i].i = i;
        cin >> queries[i].k;
    }

    sort(queries, queries + q);
    BST bst;


    for (int i = 0; i < q; ++i) {
        ll k = queries[i].k - n;

        const ll h = [&]() {
            ll lo = 0, hi = MxK / m + 9;
            for (;;) {
                const ll mid = (lo + hi + 1) / 2;
                const ll curr = mid * cnt[min<ll>(mid, n)] - cs[min<ll>(mid, n)];
                if (lo == hi) {
                    k -= curr + 1;
                    return lo + 1;
                }
                curr <= k - 1 ? lo = mid : hi = mid - 1;
            }
        }();

        {
            static vector<pair<int, int>> v;

            if (v.empty()) {
                for (int i = 1; i <= m; ++i)
                    v.emplace_back(a[i], i);
                sort(v.begin(), v.end());
            }

            static auto it = v.begin();
            while (it != v.end() && it->first < h) {
                bst.insert(it->second);
                it++;
            }
        }

        ans[queries[i].i] = bst.valAtRank(k);
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}