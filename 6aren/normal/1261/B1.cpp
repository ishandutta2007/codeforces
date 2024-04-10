#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

struct Query {
    int k, pos, id;
} q[N];

vector<ii> v;
int n, m, a[N], res[N], bit[N];

bool cmp(ii x, ii y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x > y.x;
}

bool cmp2(Query x, Query y) {
    return x.k < y.k;
}

void update(int k, int val) {
    for (int i = k; i < N; i += (i & (-i))) {
        bit[i] += val;
    }
}

int get(int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= (i & (-i))) {
        ans += bit[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v.pb({1e9 + 2, 1e9});
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.pb({a[i], i});
    }
    sort(all(v), cmp);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].k >> q[i].pos;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp2);
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < q[i].k) {
            cur++;
            update(v[cur].y, 1);
        }
        int l = 1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get(mid) >= q[i].pos) {
                r = mid;
            } else l = mid;
        }
        for (int j = l; j <= r; j++) {
            if (get(j) == q[i].pos) {
                res[q[i].id] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << a[res[i]] << '\n';
    return 0;
}