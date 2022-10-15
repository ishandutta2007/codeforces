#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct node {
    int b, i, r;
};

bool cmp(node x, node y) {
    return x.b > y.b;
}

const int MN = 500005;

int n, st[8 * MN], ans = 0;
node a[MN];
map<int, int> mp;
vector<int> v;

void upd(int l, int r, int x, int val, int idx) {
    if (l == r) {
        st[idx] = max(st[idx], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, val, idx * 2);
    else upd(mid + 1, r, x, val, idx * 2 + 1);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return max(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].b;
    for (int i = 1; i <= n; i++) cin >> a[i].i, v.push_back(a[i].i);
    for (int i = 1; i <= n; i++) cin >> a[i].r;
    sort(a + 1, a + n + 1, cmp);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) mp[v[i]] = i + 1;
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        a[i].i = mp[a[i].i];
        if (qry(1, MN, a[i].i + 1, MN, 1) > a[i].r) ans++;
        if (a[i + 1].b != a[i].b) {
            for (; pre <= i; pre++) upd(1, MN, a[pre].i, a[pre].r, 1);
        }
    }
    printf("%d\n", ans);

    return 0;
}