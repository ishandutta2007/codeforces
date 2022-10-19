//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;
#define bint __int128_t
#define int long long
#define ll long long
const int INF = 2e15;
mt19937 rnd(1303);

struct node {
    node* l = nullptr;
    node* r = nullptr;
    ll sum;
    int x, y, sz = 1, p = -1;

    node(int x) : x(x), sum(x), y(rnd()) {}
};

inline ll sum(node* a) {
    if (a == nullptr) return 0;
    return a->sum;
}

inline int sz(node* a) {
    if (a == nullptr) return 0;
    return a->sz;
}

void update(node* a) {
    a->sum = a->x + sum(a->l) + sum(a->r);
    a->sz = 1 + sz(a->l) + sz(a->r);
}

inline void push(node* a) {
    if (a->p == -1) return;
    if (a->l != nullptr) {
        a->l->p = a->p;
        a->l->sum = (ll)a->p * a->l->sz;
        a->l->x = a->p;
    }
    if (a->r != nullptr) {
        a->r->p = a->p;
        a->r->sum = (ll)a->p * a->r->sz;
        a->r->x = a->p;
    }
    a->p = -1;
}

node* merge(node* a, node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    push(a);
    push(b);
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        update(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        update(b);
        return b;
    }
}

pair <node*, node*> split(node* a, int x) {
    if (a == nullptr) return make_pair(nullptr, nullptr);
    push(a);
    if (a->x <= x) {
        auto now = split(a->r, x);
        a->r = now.first;
        update(a);
        return make_pair(a, now.second);
    } else {
        auto now = split(a->l, x);
        a->l = now.second;
        update(a);
        return make_pair(now.first, a);
    }
}
const int MASK = (1 << 30) - 1;

struct SegTree {
    int n;
    vector <int> t;

    SegTree(int n) : n(n) {
        t.resize(4 * n, INF);
    }

    void update(int v, int l, int r, int i, int x) {
        if (l > i || i > r) return;
        if (l == r) {
            t[v] = x;
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x);
        update(2 * v + 1, m + 1, r, i, x);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int get_min(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return INF;
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return min(get_min(2 * v, l, m, A, B), get_min(2 * v + 1, m + 1, r, A, B));
    }
};

node* remove(node* a, int x) {
    auto now1 = split(a, x);
    auto now2 = split(now1.first, x - 1);
    push(now2.second);
    return merge(merge(now2.first, now2.second->l), merge(now2.second->r, now1.second));
}

node* add(node* a, int x) {
    auto now = split(a, x);
    return merge(merge(now.first, new node(x)), now.second);
}

node* min_eq(node* a, int x) {
    auto now = split(a, x);
    if (now.second != nullptr) {
        now.second->p = x;
        now.second->sum = (ll)now.second->sz * x;
        now.second->x = x;
    }
    return merge(now.first, now.second);
}

void print(bint a) {
    vector <int> ans;
    while (a) {
        ans.push_back((int)(a % 10));
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i;
    cout << "\n";
}

void solve() {
    srand(1303);
    int n;
    bint ans = 0;
    cin >> n;
    vector <int> p(n);
    vector <vector <int>> bp(n + 1, vector <int> (20, n));
    SegTree t(n);
    node* root = nullptr;
    string s;
    for (int i = 0; i < n; ++i) {
        char c;
        int w;
        cin >> c >> w;
        int d = ans % 26;
        int ord = c - 'a';
        c = 'a' + (d + ord) % 26;
        w ^= (ans & MASK);
        s.push_back(c);
        t.update(1, 0, n - 1, i, w);
        if (i) {
            int k = p[i - 1];
            while (k) {
                if (s[k] == c) break;
                k = p[k - 1];
            }
            p[i] = k + (s[k] == c);
            if (p[i]) {
                bp[i][0] = p[i] - 1;
                for (int ln = 1; ln < 20; ++ln) {
                    bp[i][ln] = bp[bp[i][ln - 1]][ln - 1];
                }
            }
        } else {
            ans += w;
            cout << w << "\n";
            continue;
        }
        ans += t.get_min(1, 0, n - 1, 0, i);
        int c1 = p[i];
        int c2 = p[i - 1];
        while (true) {
            while (c2 >= c1 && c2) {
                root = remove(root, t.get_min(1, 0, n - 1, i - c2, i - 1));
                c2 = p[c2 - 1];
            }
            if (c1 == 0 || c2 == 0) break;
            for (int ln = 19; ln >= 0; --ln) {
                if (bp[c1 - 1][ln] != n && bp[c1 - 1][ln] == bp[c2 - 1][ln] + 1) {
                    c1 = bp[c1 - 1][ln] + 1;
                    c2 = bp[c2 - 1][ln] + 1;
                }
            }
            if (bp[c1 - 1][0] == n) {
                c2 = p[c2 - 1];
                while (c2) {
                    root = remove(root, t.get_min(1, 0, n - 1, i - c2, i - 1));
                    c2 = p[c2 - 1];
                }
                break;
            }
            c1 = p[c1 - 1];
            c2 = p[c2 - 1];
        }
        if (s[0] == s[i]) {
            root = add(root, w);
        }
        root = min_eq(root, w);
        ans += sum(root);
        print(ans);
    }
}

void solve2() {
    int n;
    ll ans = 0;
    cin >> n;
    vector <int> a;
    string s;
    for (int i = 0; i < n; ++i) {
        char c;
        int w;
        cin >> c >> w;
        int d = ans % 26;
        int ord = c - 'a';
        c = 'a' + (d + ord) % 26;
        w ^= (ans & MASK);
        s.push_back(c);
        a.push_back(w);
        for (int len = 1; len <= i + 1; ++len) {
            if (s.substr(0, len) == s.substr(i - len + 1, len)) {
                int mn = INF;
                for (int j = i - len + 1; j <= i; ++j) mn = min(mn, a[j]);
                ans += mn;
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //  cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
=
 */