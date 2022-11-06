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

#define maxN 200011
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aint {
    int dim;
    int sum[maxN * 4 + 11], *ini;
    bool op[maxN * 4 + 11];

    void build(int node, int l, int r) {
        if (l == r) {
            if (ini[l]) {
                sum[node] = 1;
                op[node] = true;
            }
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        sum[node] = sum[lSon] + sum[rSon];
    }

    void init(int _dim, int *_ini) {
        dim = _dim;
        ini = _ini;
        memset(sum, 0, sizeof(sum));
        build(1, 1, dim);
    }

    void upd(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            sum[node] = r - l + 1 - sum[node];
            op[node] ^= 1;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            upd(lSon, l, mid, qL, qR);
        if (qR > mid)
            upd(rSon, mid + 1, r, qL, qR);

        sum[node] = sum[lSon] + sum[rSon];
        if (op[node]) sum[node] = r - l + 1 - sum[node];
    }

    int que(int node, int l, int r, int qL, int qR, bool bef) {
        if (qL <= l && r <= qR) {
            if (bef == false)
                return sum[node];
            else
                return r - l + 1 - sum[node];
        }

        int mid = (l + r) >> 1;
        int ans = 0;

        if (qL <= mid) ans += que(lSon, l, mid, qL, qR, bef ^ op[node]);
        if (qR > mid) ans += que(rSon, mid + 1, r, qL, qR, bef ^ op[node]);

        return ans;
    }
};

int n, i, q, x, l[maxN], r[maxN], cnt;
vector<int> list[maxN];
int ini[maxN], aux[maxN];
aint work;
string s;

void dfs(int node) {
    l[node] = ++cnt;
    aux[cnt] = ini[node];

    for (auto to : list[node])
        dfs(to);

    r[node] = cnt;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 2; i <= n; i++) {
        cin >> x;
        list[x].pb(i);
    }

    for (i = 1; i <= n; i++)
        cin >> ini[i];

    dfs(1);
    work.init(n, aux);

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> s >> x;

        if (s[0] == 'p') {
            work.upd(1, 1, n, l[x], r[x]);
        }

        if (s[0] == 'g') {
            cout << work.que(1, 1, n, l[x], r[x], false) << '\n';
        }
    }


    return 0;
}