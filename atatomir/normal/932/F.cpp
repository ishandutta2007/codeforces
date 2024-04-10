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

const int limit = 100000;

struct lee_node {
    ll m, n;
    lee_node* son[2];

    lee_node(ll _m, ll _n) {
        m = _m;
        n = _n;
        son[0] = son[1] = NULL;
    }

    ll compute(ll x, ll m, ll n) {
        return x * m + n;
    }

    void add_line(ll l, ll r, ll mm, ll nn) {
        if (compute(l, mm, nn) < compute(l, m, n)) {
            swap(m, mm);
            swap(n, nn);
        }

        if (compute(r, m, n) <= compute(r, mm, nn)) return;
        ll mid = (l + r) >> 1;

        if (compute(mid, m, n) < compute(mid, mm, nn)) {
            if (son[1] == NULL)
                son[1] = new lee_node(mm, nn);
            else
                son[1]->add_line(mid + 1, r, mm, nn);
        } else {
            swap(n, nn);
            swap(m, mm);

            if (son[0] == NULL)
                son[0] = new lee_node(mm, nn);
            else
                son[0]->add_line(l, mid, mm, nn);
        }
    }

    ll query(ll l, ll r, ll pos) {
        if (l == r) return compute(pos, m, n);
        ll ans = compute(pos, m, n);
        ll mid = (l + r) >> 1;

        if (pos <= mid && son[0] != NULL)
            ans = min(ans, son[0]->query(l, mid, pos));
        if (pos > mid && son[1] != NULL)
            ans = min(ans, son[1]->query(mid + 1, r, pos));

        return ans;
    }
};

struct p_vect {
    vector< pair<ll, ll> > data;

    p_vect() {
        data.clear();
    }
};

int n, i, x, y;
ll a[maxN], b[maxN], dp[maxN];
vector<int> list[maxN];

lee_node* head[maxN];
p_vect* rez[maxN];

void dfs(int node, int root) {
    int i, to;

    for (i = 0; i < list[node].size(); i++) {
        to = list[node][i];
        if (to == root) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            i--;
            continue;
        }

        dfs(to, node);
    }

    if (list[node].empty()) {
        dp[node] = 0;
        head[node] = new lee_node(b[node], 0);
        rez[node] = new p_vect();
        rez[node]->data.pb(mp(b[node], 0));
        return;
    }

    sort(list[node].begin(), list[node].end(), [](int a, int b)->bool const {
        return rez[a]->data.size() > rez[b]->data.size();
    });

    head[node] = head[ list[node][0] ];
    rez[node] = rez[ list[node][0] ];

    for (i = 1; i < list[node].size(); i++) {
        to = list[node][i];

        for (auto ec : rez[to]->data) {
            rez[node]->data.pb(ec);
            head[node]->add_line(-limit, +limit, ec.first, ec.second);
        }
    }

    dp[node] = head[node]->query(-limit, +limit, a[node]);
    rez[node]->data.pb(mp(b[node], dp[node]));
    head[node]->add_line(-limit, +limit, b[node], dp[node]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &b[i]);

    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);
    for (i = 1; i <= n; i++)
        printf("%lld ", dp[i]);


    return 0;
}