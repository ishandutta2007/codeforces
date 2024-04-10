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
#define lSon (node << 1)
#define rSon (lSon | 1)
#define mod 1000000007


bool is_active[maxN];

struct barr {
    int u, l, r, s;

    bool operator<(const barr& who)const {
        return u < who.u;
    }
};

struct aint {
    int n, i;
    vector< vector<int> > data;

    void init(int _n) {
        n = _n;
        data = vector< vector<int> >(4 * n + 11, vector<int>(0));
    }

    void upd(int node, int l, int r, int qL, int qR, int v) {
        if (qL <= l && r <= qR) {
            data[node].pb(v);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            upd(lSon, l, mid, qL, qR, v);
        if (qR > mid)
            upd(rSon, mid + 1, r, qL, qR, v);
    }

    int que(int node, int l, int r, int pos) {
        while (!data[node].empty()) {
            if (is_active[data[node].back()]) break;
            data[node].pop_back();
        }

        int ans = 0;
        if (!data[node].empty()) ans = data[node].back();
        if (l == r) return ans;

        int mid = (l + r) >> 1;

        if (pos <= mid)
            return max(ans, que(lSon, l, mid, pos));
        else
            return max(ans, que(rSon, mid + 1, r, pos));
    }

};

int h, w, n, i, pos;
barr B[maxN];
vector< pair<int, int> > del;
ll dp[maxN];
aint work;

ll sol;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &h, &w, &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d%d%d", &B[i].u, &B[i].l, &B[i].r, &B[i].s);

    work.init(w);

    sort(B + 1, B + n + 1);
    for (i = 1; i <= n; i++)
        del.pb(mp(B[i].u + B[i].s + 1, i));

    dp[0] = 1;

    sort(del.begin(), del.end());
    for (i = 1; i <= n; i++) {
        int act_h = B[i].u;

        while (pos < del.size()) {
            if (del[pos].first > act_h) break;
            is_active[del[pos].second] = false;
            pos++;
        }

        work.upd(1, 1, w, B[i].l, B[i].r, i);
        is_active[i] = true;

        int p1 = B[i].l - 1;
        int p2 = B[i].r + 1;

        if (p1 == 0) p1 = p2;
        if (p2 == w + 1) p2 = p1;

        int ans = work.que(1, 1, w, p1);
        dp[i] += dp[ans];

        ans = work.que(1, 1, w, p2);
        dp[i] += dp[ans];

        dp[i] %= mod;
    }

    while (pos < del.size()) {
        if (del[pos].first > h + 1) break;
        is_active[del[pos].second] = false;
        pos++;
    }

    for (i = 1; i <= w; i++) {
        int ans = work.que(1, 1, w, i);
        sol += dp[ans];
    }

    sol %= mod;
    printf("%lld", sol);

    return 0;
}