#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct SplayTree {
    using Data = int; //type can be changed
    Data none = -1; //default when not found
    struct Node {
        Node *l, *r, *p;
        int sz, cnt;
        Data v;
        explicit Node(Data val) {
            l = nullptr, r = nullptr, p = nullptr;
            v = val;
            sz = 1;
            cnt = 1;
        }
    };

    Node *root = nullptr;
    int sz = 0;

    SplayTree() {
        root = nullptr;
        sz = 0;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    static void rot_right(Node *x) {
        Node *p, *g;
        p = x->p, g = p->p;
        int a = x->l ? x->l->sz : 0, b = x->r ? x->r->sz : 0, c = p->r ? p->r->sz : 0;
        if ((p->l = x->r)) p->l->p = p;
        x->r = p, p->p = x;
        if ((x->p = g)) {
            if (p == g->l) g->l = x;
            else g->r = x;
        }
        p->sz = b + c + p->cnt;
        x->sz = p->sz + a + x->cnt;
    }

    static void rot_left(Node *x) {
        Node *p, *g;
        p = x->p, g = p->p;
        int a = x->l ? x->l->sz : 0, b = x->r ? x->r->sz : 0, c = p->l ? p->l->sz : 0;
        if ((p->r = x->l)) p->r->p = p;
        x->l = p, p->p = x;
        if ((x->p = g)) {
            if (p == g->l) g->l = x;
            else g->r = x;
        }
        p->sz = a + c + p->cnt;
        x->sz = p->sz + b + x->cnt;
    }

    void splay(Node *x) {
        Node *p, *g;
        while (x->p) {
            p = x->p;
            if (p->p == nullptr) {
                if (x == p->l) rot_right(x);
                else rot_left(x);
                break;
            }
            g = p->p;
            if (p == g->l) {
                if (x == p->l) rot_right(p), rot_right(x);
                else rot_left(x), rot_right(x);
            } else {
                if (x == p->r) rot_left(p), rot_left(x);
                else rot_right(x), rot_left(x);
            }
        }
        root = x;
    }

    void insert(Data v) {
        sz++;
        if (root == nullptr) {
            root = new Node(v);
            return;
        }
        Node *x = root;
        while (1) {
            if (v > x->v) {
                if (x->r) {
                    x = x->r;
                    continue;
                }
                else {
                    x->r = new Node(v);
                    x->r->p = x;
                    Node *p = x;
                    while (p) p->sz += 1, p = p->p;
                    splay(x->r);
                    return;
                }
            } else if (v < x->v) {
                if (x->l) {
                    x = x->l;
                    continue;
                }
                else {
                    x->l = new Node(v);
                    x->l->p = x;
                    Node *p = x;
                    while (p) p->sz += 1, p = p->p;
                    splay(x->l);
                    return;
                }
            } else {
                x->cnt += 1;
                Node *p = x;
                while (p) p->sz += 1, p = p->p;
                splay(x);
                return;
            }
        }
    }

    Node *find(Data v) {
        if (root == nullptr) return nullptr;
        Node *x = root;
        while (x) {
            if (v == x->v) break;
            if (v > x->v) {
                if (x->r) x = x->r;
                else break;
            } else {
                if (x->l) x = x->l;
                else break;
            }
        }
        splay(x);
        if (x->v == v) return x;
        return nullptr;
    }

    bool erase(Data v) {
        Node *x = find(v);
        if (x == nullptr) return false;
        sz--;
        x->cnt -= 1;
        if (x->cnt > 0) return true;
        if (x->l == nullptr && x->r == nullptr) {
            root = nullptr;
            free(x);
            return true;
        }
        Node *l = x->l;
        if (l == nullptr) {
            root = x->r;
            root->p = nullptr;
            free(x);
            return true;
        }
        l->p = nullptr;
        while (l->r) l = l->r;
        splay(l);
        if (x->r) {
            l->r = x->r;
            l->r->p = l;
            l->sz += l->r->sz;
        }
        root = l;
        root->p = nullptr;
        free(x);
        return true;
    }

    int order_of_key(Data v) {
        if (root == nullptr) return 1;
        int ret = 1;
        Node *x = root;
        while (x) {
            int a = x->l ? x->l->sz : 0;
            if (v == x->v) {ret += a; break;}
            if (v > x->v) {
                ret += a + x->cnt;
                if (x->r) x = x->r;
                else break;
            } else {
                if (x->l) x = x->l;
                else break;
            }
        }
        splay(x);
        return ret;
    }

    Data find_by_order(Node *x, int k) {
        if (x == nullptr) return none;
        int a = x->l ? x->l->sz : 0;
        if (k <= a) return find_by_order(x->l, k);
        else if (k <= a + x->cnt) {
            splay(x);
            return x->v;
        } else return find_by_order(x->r, k - a - x->cnt);
    }

    Data find_by_order(int k) {
        return find_by_order(root, k);
    }

    static void inorder(Node *x) {
        if (x == nullptr) return;
        inorder(x->l);
        for (int i = 1; i <= x->cnt; i++) cout << x->v << " ";
        inorder(x->r);
    }

    void print() {
        cout << "\n";
        cout << "Size: " << sz << "\nElements: ";
        inorder(root);
        cout << "\n\n";
    }
};

const int MN = 200005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p % 2) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, a[MN], ans, cnt, lft, rit, vis[MN];
SplayTree v, s;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], vis[a[i]] = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) v.insert(i), cnt++;
    ans += cnt * (cnt - 1) % MOD * fpow(4, MOD - 2); ans %= MOD;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {lft++; continue;}
        int want = v.size() - v.order_of_key(a[i]) + 1;
        ans += lft * want % MOD * fpow(cnt, MOD - 2); ans %= MOD;
    }
    for (int i = n; i > 0; i--) {
        if (a[i] == -1) {rit++; continue;}
        int want = v.order_of_key(a[i]) - 1;
        ans += rit * want % MOD * fpow(cnt, MOD - 2); ans %= MOD;
    }
    for (int i = n; i > 0; i--) {
        if (a[i] == -1) continue;
        ans += s.order_of_key(a[i]) - 1; ans %= MOD;
        s.insert(a[i]);
    }
    printf("%lld\n", ans % MOD);

    return 0;
}