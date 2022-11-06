#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define lSon (node << 1)
#define rSon (lSon | 1)

#define maxN 200011
#define inf 1000000000

struct aint {
    int n;
    vector<ll> add, mini;

    void init(int _n) {
        n = _n;
        add = mini = vector<ll>(n << 2, 0);
    }

    void upd(int node, int l, int r, int qL, int qR, ll v) {
        if (qL <= l && r <= qR) {
            add[node] += v;
            mini[node] += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, v);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, v);

        mini[node] = min(mini[lSon], mini[rSon]) + add[node];
    }

    int last_lower(int node, int l, int r, int qL, int qR, ll up, ll k) {
        if (up + mini[node] > k) return inf;
        if (l == r) return l;

        int mid = (l + r) >> 1;
        int ans = inf;

        if (qR > mid) ans = last_lower(rSon, mid + 1, r, qL, qR, up + add[node], k);
        if (ans != inf) return ans;
        return last_lower(lSon, l, mid, qL, qR, up + add[node], k);
    }

    ll get_val(int node, int l, int r, int pos) {
        if (l == r) return add[node];
        int mid = (l + r) >> 1;
        if (pos <= mid) return add[node] + get_val(lSon, l, mid, pos);
        return add[node] + get_val(rSon, mid + 1, r, pos);
    }
};

ll bonus = 2LL * inf;

ll n, k, d, i, j, ans_l, ans_r;
ll a[maxN], data[maxN], far[maxN];
map<ll, bool> M;
stack< pair<ll, ll> > maxi, mini;
aint work;

void solve_zero() {
    int l, r;
    int i, j;

    l = r = 1;
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (a[i] != a[j])
                break;

        if (j - i > r - l + 1) {
            l = i;
            r = j - 1;
        }
    }

    printf("%d %d", l, r);
    exit(0);
}

void solve(int l, int r) {
    ll i, j, dim;

    dim = r - l + 1;
    for (i = l; i <= r; i++) data[i - l + 1] = a[i] / d;

    //! compute far
    M.clear();
    for (i = j = 1; i <= dim; i++) {
        j = max(i, j);
        M[data[i]] = true;

        while (j + 1 <= dim && M[data[j + 1]] == false) {
            j++;
            M[data[j]] = true;
        }
        far[i] = j;
        M[data[i]] = false;
    }

    //! compute solution
    while (!maxi.empty()) maxi.pop();
    while (!mini.empty()) mini.pop();
    work.init(dim);



    for (i = dim; i >= 1; i--) {
        //cerr << work.get_val(1, 1, dim, 2) << '\n';

        // maxi stack
        pair<ll, ll> act = mp(i, i);
        while (!maxi.empty()) {
            auto who = maxi.top();
            if (data[i] <= data[who.first]) break;

            work.upd(1, 1, dim, who.first, who.second, data[i] - data[who.first]);
            act.second = who.second;
            maxi.pop();
        }
        maxi.push(act);
        work.upd(1, 1, dim, i, i, data[i]);

        //cerr << work.get_val(1, 1, dim, 2) << '\n';

        // mini stack
        act = mp(i, i);
        while (!mini.empty()) {
            auto who = mini.top();
            if (data[i] >= data[who.first]) break;

            work.upd(1, 1, dim, who.first, who.second, data[who.first] - data[i]);
            act.second = who.second;
            mini.pop();
        }
        mini.push(act);
        work.upd(1, 1, dim, i, i, -data[i]);

        //cerr << work.get_val(1, 1, dim, 2) << '\n';


        // find best
        j = work.last_lower(1, 1, dim, i, far[i], 0, k);
        if (j - i + 1 > ans_r - ans_l + 1) {
            ans_l = l + i - 1;
            ans_r = l + j - 1;
        }

        if (j - i + 1 == ans_r - ans_l + 1 && l + i - 1 < ans_l) {
            ans_l = l + i - 1;
            ans_r = l + j - 1;
        }

        work.upd(1, 1, dim, i, dim, -1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &k, &d);
    if (d != 0) bonus -= bonus % d;
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += bonus;

    if (d == 0) solve_zero();

    ans_l = ans_r = 1;
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (a[i] % d != a[j] % d)
                break;

        solve(i, j - 1);
    }

    printf("%lld %lld", ans_l, ans_r);

    return 0;
}