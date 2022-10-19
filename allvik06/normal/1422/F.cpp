#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
#define ll long long
const int INF = 1e9;
const int MAXC = 2e5;
const ll mod = 1e9 + 7;

struct SegTreeMax {
    int n;
    vector <int> t;

    SegTreeMax(int n) : n(n) {
        t.resize(2 * n, 0);
    }

    inline void upd(int i, int x) {
        i += n;
        t[i] = x;
        i >>= 1;
        while (i > 0) {
            t[i] = max(t[2 * i], t[2 * i + 1]);
            i >>= 1;
        }
    }

    inline int get_max(int l, int r) {
        int ans = 0;
        l += n;
        r += n;
        while (l <= r) {
            if (l & 1) {
                ans = max(ans, t[l]);
                ++l;
            }
            if (!(r & 1)) {
                ans = max(ans, t[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};

struct node {
    node* l = nullptr;
    node* r = nullptr;
    ll pr = 1;
};

inline node* left_son(node* a) {
    if (a == nullptr) return nullptr;
    return a->l;
}

inline node* right_son(node* a) {
    if (a == nullptr) return nullptr;
    return a->r;
}

inline ll pr(node* a) {
    if (a == nullptr) return 1;
    return a->pr;
}

node* update(node* a, int l, int r, int i, int x) {
    if (l > i || i > r) return a;
    node* tmp = new node();
    if (l == r) {
        tmp->pr = x;
        return tmp;
    }
    int m = (l + r) / 2;
    tmp->l = update(left_son(a), l, m, i, x);
    tmp->r = update(right_son(a), m + 1, r, i, x);
    tmp->pr = pr(left_son(tmp)) * pr(right_son(tmp)) % mod;
    return tmp;
}

ll get_pr(node* a, int l, int r, int A, int B) {
    if (l > B || A > r || a == nullptr) return 1;
    if (A <= l && r <= B) return a->pr;
    int m = (l + r) / 2;
    return get_pr(a->l, l, m, A, B) * get_pr(a->r, m + 1, r, A, B) % mod;
}

inline ll power(ll x, int n) {
    if (n == 0) return 1;
    if (n & 1) return power(x, n - 1) * x % mod;
    return power((x * x) % mod, n >> 1);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector <int> small_pr;
    for (int i = 2; i * i <= MAXC; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ok = false;
            }
        }
        if (ok) {
            small_pr.push_back(i);
        }
    }
    int len = (int)small_pr.size(), n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <SegTreeMax> all(len, SegTreeMax(n));
    vector <node*> roots(n + 1, nullptr);
    roots[0] = new node();
    vector <int> last_in(MAXC + 1, -1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int num = 0; num < len; ++num) {
            int cnt = 0;
            while (x % small_pr[num] == 0) {
                x /= small_pr[num];
                ++cnt;
            }
            if (cnt > 0) all[num].upd(i, cnt);
        }
        roots[i + 1] = roots[i];
        if (x != 1) {
            if (last_in[x] != -1) roots[i + 1] = update(roots[i + 1], 0, n - 1, last_in[x], 1);
            roots[i + 1] = update(roots[i + 1], 0, n - 1, i, x);
            last_in[x] = i;
        }
    }
    int last = 0, q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = (last + x) % n, r = (last + y) % n;
        if (l > r) swap(l, r);
        ll ans = 1;
        for (int i = 0; i < len; ++i) {
            ans = ans * power(small_pr[i], all[i].get_max(l, r)) % mod;
        }
        ans = ans * get_pr(roots[r + 1], 0, n - 1, l, r) % mod;
        last = ans;
        cout << ans << "\n";
    }
}