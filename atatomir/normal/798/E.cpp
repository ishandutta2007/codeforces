#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 500011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf 1000000000

struct aint {
    int dim;
    vector< pair<int, int> > data;

    void init(int _dim) {
        dim = _dim;
        data = vector< pair<int, int> >(4 * dim + 11, mp(0, 0));
    }

    void upd(int node, int l, int r, int pos, pair<int, int> val) {
        if (l == r) {
            data[node] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, val);
        if (pos > mid) upd(rSon, mid + 1, r, pos, val);
        data[node] = max(data[lSon], data[rSon]);
    }

    pair<int, int> que(int node, int l, int r, int qL, int qR) {
        if (qL > qR) return mp(0, 0);
        if (qL <= l && r <= qR) return data[node];


        int mid = (l + r) >> 1;
        pair<int, int> ans = mp(0, 0);
        if (qL <= mid) ans = max(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = max(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

int n, i;
int a[maxN], b[maxN];
vector<int> list[maxN];
aint work;
vector<int> ord;
bool us[maxN];
int ans[maxN];

void dfs(int node) {
    us[node] = true;
    work.upd(1, 1, n, node, mp(0, 0));

    for (auto to : list[node])
        if (!us[to])
            dfs(to);

    while (true) {
        int ans = work.que(1, 1, n, 1, a[node] - 1).second;
        if (ans == 0) break;
        if (b[ans] > node) {
            if (!us[ans])
                dfs(ans);
        } else {
            break;
        }
    }

    ord.pb(node);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) b[i] = n + 1;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != -1) {
            list[a[i]].pb(i);
        } else {
            a[i] = n + 1;
        }

        b[a[i]] = i;
    }

    work.init(n);
    for (i = 1; i <= n; i++) work.upd(1, 1, n, i, mp(b[i], i));

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        dfs(i);
    }

    for (i = 0; i < ord.size(); i++)
        ans[ord[i]] = i + 1;

    for (i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}