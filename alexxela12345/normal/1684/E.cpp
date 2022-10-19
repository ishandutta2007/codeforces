#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

mt19937 rd(179);

struct node {
    node *l, *r;
    int sm;
    int sz;
    int x, y;

    node(int x) : x(x) {
        l = r = NULL;
        sm = x;
        sz = 1;
        y = rd();
    }
};

int get_sz(node *n) {
    return (n == NULL) ? 0 : n->sz;
}

int get_sm(node *n) {
    return (n == NULL) ? 0 : n->sm;
}

void pull(node *n) {
    n->sz = 1 + get_sz(n->l) + get_sz(n->r);
    n->sm = n->x + get_sm(n->l) + get_sm(n->r);
}

node *merge(node *a, node *b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}

pair<node *, node *> split_x(node *a, int x) { // {< x, >=x}
    if (a == NULL) {
        return {a, a};
    }
    if (a->x >= x) {
        auto pp = split_x(a->l, x);
        a->l = pp.second;
        pull(a);
        return {pp.first, a};
    }
    auto pp = split_x(a->r, x);
    a->r = pp.first;
    pull(a);
    return {a, pp.second};
}

pair<node *, node *> split_sz(node *a, int k) {
    if (a == NULL) {
        return {a, a};
    }
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

pair<node *, node *> split_sm(node *a, int k) {
    if (a == NULL) {
        return {a, a};
    }
    if (get_sm(a->l) + a->x <= k) {
        auto pp = split_sm(a->r, k - get_sm(a->l) - a->x);
        a->r = pp.first;
        pull(a);
        return {a, pp.second};
    }
    auto pp = split_sm(a->l, k);
    a->l = pp.second;
    pull(a);
    return {pp.first, a};
}

struct mdata {
    node *root;
    int sm;

    mdata() {
        root = NULL;
        sm = 0;
    }

    void insert(int x) {
        auto pp = split_x(root, x);
        root = merge(pp.first, merge(new node(x), pp.second));
        sm += x;
    }

    void erase(int x) {
        auto pp = split_x(root, x);
        auto pp2 = split_sz(pp.second, 1);
        root = merge(pp.first, pp2.second);
        sm -= x;
    }

    int get(int k) {
        auto pp = split_sm(root, k);
        int ans = get_sz(pp.second);
        root = merge(pp.first, pp.second);
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int min_ans = INT_MAX;
    map<int, int> cnt;
    for (int x : arr)
        cnt[x]++;
    mdata cntcnt;
    for (auto el : cnt) {
        cntcnt.insert(el.second);
    }
    if (cnt[0] <= k) {
        vector<int> arr;
        int left = k - cnt[0];
        for (auto el : cnt) {
            if (el.first != 0)
                arr.push_back(el.second);
        }
        sort(arr.begin(), arr.end());
        if (!arr.empty()) {
            arr.pop_back();
        }
        int cur_ans = arr.size() + 1;
        for (auto el : arr) {
            if (el > left)
                break;
            left -= el;
            cur_ans -= 1;
        }
        min_ans = min(min_ans, cur_ans);
    }
    int cntneed = 0;
    int cntad = 0;
    for (int mex = 1; mex <= n; mex++) {
        if (cnt[mex - 1]) {
            cntcnt.erase(cnt[mex - 1]);
        } else {
            cntneed++;
        }
        cntad += max(0, cnt[mex - 1] - 1);
        if (cntneed > k || cntcnt.sm + cntad < cntneed) {
            break;
        }
        int ans = cntcnt.get(k);
        min_ans = min(min_ans, ans);
    }
    cout << min_ans << endl;
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