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

#define maxN 300011
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aint {
    int dim;
    vector<int> data;

    void init(int _dim) {
        dim = _dim;
        data = vector<int>(4 * dim + 11, 0);
    }

    void upd(int node, int l, int r, int qL, int qR, int val) {
        if (qL <= l && r <= qR) {
            data[node] = max(data[node], val);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, val);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, val);
    }

    int que(int node, int l, int r, int pos) {
        if (l == r)
            return data[node];

        int mid = (l + r) >> 1;
        if (pos <= mid)
            return max(data[node], que(lSon, l, mid, pos));
        if (pos > mid)
            return max(data[node], que(rSon, mid + 1, r, pos));
    }
};

int n, i;
int p[maxN];
int ans[maxN];
aint even, odd;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> p[i];
    even.init(n);
    odd.init(n);

    for (i = 1; i <= n; i++) ans[1] = max(ans[1], p[i]);
    for (i = 1; i + 1 <= n; i++) {
        int aux = max(p[i], p[i + 1]);
        int bonus = min(n - i - 1, i - 1);

        even.upd(1, 1, n, 2, 2 + 2 * bonus, aux);
    }
    for (i = 1; i + 2 <= n; i++) {
        int aux = min(p[i + 1], max(p[i], p[i + 2]));
        int bonus = min(i - 1, n - i - 2);

        odd.upd(1, 1, n, 3, 3 + 2 * bonus, aux);
    }

    for (i = 2; i <= n; i++) {
        if (i & 1) {
            ans[i] = odd.que(1, 1, n, i);
        } else {
            ans[i] = even.que(1, 1, n, i);
        }
    }

    for (i = n; i > 0; i--)
        cout << ans[i] << ' ';

    return 0;
}