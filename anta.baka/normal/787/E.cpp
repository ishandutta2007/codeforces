#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *l, *r;
};

typedef node *pnode;

pnode build(int l, int r) {
    pnode res = new node;
    if(l == r) {
        res->val = 0;
        res->l = res->r = NULL;
    } else {
        int m = (l + r) / 2;
        res->l = build(l, m);
        res->r = build(m + 1, r);
        res->val = res->l->val + res->r->val;
    }
    return res;
}

pnode update(pnode x, int l, int r, int pos, int val) {
    pnode res = new node;
    if(l == r) {
        res->val = val;
        res->l = res->r = NULL;
    } else {
        int m = (l + r) / 2;
        if(pos <= m) {
            res->l = update(x->l, l, m, pos, val);
            res->r = x->r;
        } else {
            res->l = x->l;
            res->r = update(x->r, m + 1, r, pos, val);
        }
        res->val = res->l->val + res->r->val;
    }
    return res;
}

int get(pnode x, int l, int r, int &k) {
    if(l == r) {
        k -= x->val;
        return l;
    }
    int m = (l + r) / 2;
    if(x->l->val >= k)
        return get(x->l, l, m, k);
    k -= x->l->val;
    return get(x->r, m + 1, r, k);
}

int n, a[100000];
vector<pnode> root;
map<int, int> last;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    root.push_back(build(0, n - 1));
    for(int i = n - 1; i >= 0; i--) {
        pnode x = root.back();
        if(last.count(a[i]))
            x = update(x, 0, n - 1, last[a[i]], 0);
        root.push_back(update(x, 0, n - 1, i, 1));
        last[a[i]] = i;
    }
    reverse(root.begin(), root.end());
    for(int k = 1; k <= n; k++) {
        int pt = 0;
        int ans = 0;
        while(pt < n) {
            int kk = k + 1;
            pt = get(root[pt], 0, n - 1, kk);
            if(kk != 0)
                pt++;
            ans++;
        }
        cout << ans << ' ';
    }
}