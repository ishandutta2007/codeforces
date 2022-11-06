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

#define maxN 1000021
#define maxVal 10000021 // !ATENTIE
#define inf (1000000000)

#define lSon (node << 1)
#define rSon (lSon | 1)

const int def = 10000003;

ll k;

struct aint {
    int n, i;
    vector<int> data;

    void build(int node, int l, int r) {
        if (l == r) {
            data[node] = min(1LL * inf, k * l);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        data[node] = data[lSon];
    }

    void init(int _n) {
        n = _n;
        data.resize(4 * n + 11);
        build(1, 1, n);
    }

    void upd(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            data[node]--;
            return;
        }

        int mid = (l + r) >> 1;
        int last = min(data[lSon], data[rSon]);

        if (qL <= mid)
            upd(lSon, l, mid, qL, qR);
        if (qR > mid)
            upd(rSon, mid + 1, r, qL, qR);

        data[node] += min(data[lSon], data[rSon]) - last;
    }
};

int n, m, i, x;
int a[maxN];
vector< pair<int, int> > b;
aint work;


vector<int> sol;




int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%lld", &n, &m, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= m; i++) scanf("%d", &x), b.pb(mp(x, i));

    work.init(def);
    for (i = 1; i <= n; i++)
        work.upd(1, 1, def, a[i] + 1, def);

    if (work.data[1] < 0) {
        printf("-1");
        return 0;
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (auto e : b) {
        work.upd(1, 1, def, e.first + 1, def);
        if (work.data[1] < 0) break;
        sol.pb(e.second);
    }

    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    for (auto e : sol)
        printf("%d ", e);




    return 0;
}