#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

mt19937 rd(228);

struct node {
    node *l, *r;
    char c;
    int y;
    char mn;
    int sz;
    node(char c) : c(c) {
        l = r = NULL;
        mn = c;
        y = rd();
        sz = 1;
    }
};

char get_mn(node *a) {
    return (a == NULL) ? CHAR_MAX : a->mn;
}
int get_sz(node *a) {
    return (a == NULL) ? 0 : a->sz;
}

void pull(node *a) {
    a->mn = min({a->c, get_mn(a->l), get_mn(a->r)});
    a->sz = 1 + get_sz(a->l) + get_sz(a->r);
}

node *merge(node *a, node *b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}

pair<node *, node*> split_mn(node *a, char c) { // {mn>c, mn <=c}
    if (a == NULL)
        return {a, a};
    if (min(get_mn(a->l), a->c) <= c) {
        auto pp = split_mn(a->l, c);
        a->l = pp.second;
        pull(a);
        return {pp.first, a};
    }
    auto pp = split_mn(a->r, c);
    a->r = pp.first;
    pull(a);
    return {a, pp.second};
}

pair<node *, node *> split_sz(node *a, int k) {
    if (a == NULL)
        return {a, a};
    if (get_sz(a->l) >= k) {
        auto pp = split_sz(a->l, k);
        a->l = pp.second;
        pull(a);
        return {pp.first, a};
    }
    auto pp = split_sz(a->r, k - 1 - get_sz(a->l));
    a->r = pp.first;
    pull(a);
    return {a, pp.second};
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    node *root = NULL;
    for (char c : s) {
        root = merge(root, new node(c));
    }
    ll min_ans = LLONG_MAX;
    ll cur_ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (root->mn > t[i]) {
            break;
        }
        if (root->mn < t[i]) {
            auto pp = split_mn(root, t[i] - 1);
            min_ans = min(min_ans, cur_ans + get_sz(pp.first));
            root = merge(pp.first, pp.second);
        }
        auto pp = split_mn(root, t[i]);
        assert(pp.second != NULL);
        auto pp2 = split_sz(pp.second, 1);
        cur_ans += get_sz(pp.first);
        if (pp2.first->c < t[i]) {
            break;
        }
        assert(pp2.first->c == t[i]);
        root = merge(pp.first, pp2.second);
    }

    if (min_ans == LLONG_MAX)
        min_ans = -1;
    cout << min_ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}