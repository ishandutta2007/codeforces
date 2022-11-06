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

#define maxN 100011
#define maxSQRT 411
#define lSon (node << 1)
#define rSon (lSon | 1)

const int bucket = 400;

struct aint {
    int dim;
    int data[maxN * 4 + 11];

    void init(int _dim) {
        dim = _dim;
    }

    void upd(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, v);
        else            upd(rSon, mid + 1, r, pos, v);
        data[node] = max(data[lSon], data[rSon]);
    }

    int que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int ans = 0;
        int mid = (l + r) >> 1;
        if (qL <= mid) ans = max(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = max(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

int n, m, i, l, r, q;
int from[maxN];
vector<int> list[maxN];
aint work;

int to[maxN][maxSQRT];
int go[maxN][maxSQRT];
vector<int> st;

void pre() {
    int i, j, limit;

    for (j = 1; j * bucket <= n; j++) {
        limit = j * bucket;
        for (i = limit; i > 0; i--) {
            to[i][j] = max(i, to[i][j]);
            if (from[i] == 0) continue;
            to[from[i]][j] = max(to[from[i]][j], to[i][j]);
        }

        st = {limit + 1};
        for (i = limit; i > 0; i--) {
            if (to[i][j] == i) {
                st.pb(i);
                go[i][j] = i;
                continue;
            }
            while (st.back() + 1 <= to[i][j]) st.pop_back();
            go[i][j] = st.back();
        }
    }
}

int solve() {
    int pos, x, j, i;

    pos = x = l;
    if (r - l + 1 >= bucket) {
        for (j = 1; (j + 1) * bucket <= r; j++);
        pos = j * bucket;
        x = go[l][j];
    }

    for (i = pos + 1; i <= r; i++) {
        if (from[i] == 0) continue;
        if (from[i] >= l && from[i] <= x)
            x = i;
    }

    return x;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        if (l == r) continue;
        list[l].pb(r);
        from[r] = l;
    }

    pre();

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", solve());
    }




    return 0;
}