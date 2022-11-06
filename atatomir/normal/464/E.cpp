#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define lSon (node << 1)
#define rSon (lSon | 1)
#define maxN 155000
#define mod 1000000007
#define inf 1000000000

const int def = 131072;
const ll base = 2;
ll shl[maxN];

struct pers {
    pers* son[2];
    ll hsh;

    pers() {
        son[0] = son[1] = NULL;
        hsh = 0;
    }

    pers(int _hsh, pers *s0, pers *s1) {
        hsh = _hsh;
        son[0] = s0;
        son[1] = s1;
    }
};

void compute(pers* &act, int sz) {
    act->hsh = (act->son[1]->hsh * shl[sz / 2] + act->son[0]->hsh) % mod;
}

pers* build(int node, int l, int r, int hsh) {
    if (l == r)
        return new pers(hsh, NULL, NULL);

    pers* act = new pers();

    int mid = (l + r) >> 1;
    act->son[0] = build(lSon, l, mid, hsh);
    act->son[1] = build(rSon, mid + 1, r, hsh);
    compute(act, r - l + 1);

    return act;
}

pers* update(int node, int l, int r, int qL, int qR, pers* n1, pers* n2) {
    if (qL <= l && r <= qR)
        return n2;

    pers* act = new pers(n1->hsh, n1->son[0], n1->son[1]);
    int mid = (l + r) >> 1;
    if (qL <= mid) act->son[0] = update(lSon, l, mid, qL, qR, n1->son[0], n2->son[0]);
    if (qR >  mid) act->son[1] = update(rSon, mid + 1, r, qL, qR, n1->son[1], n2->son[1]);
    compute(act, r - l + 1);

    return act;
}

int first_dif(int node, int l, int r, int qL, int qR, pers* n1, pers* n2) {
    if (n1->hsh == n2->hsh) return inf;
    if (l == r) return l;


    int mid = (l + r) >> 1;
    int ans = inf;

    if (qL <= mid) ans = first_dif(lSon, l, mid, qL, qR, n1->son[0], n2->son[0]);
    if (ans < inf) return ans;
    return first_dif(rSon, mid + 1, r, qL, qR, n1->son[1], n2->son[1]);
}

int last_dif(int node, int l, int r, int qL, int qR, pers* n1, pers* n2) {
    if (n1->hsh == n2->hsh) return -1;
    if (l == r) return l;

    int mid = (l + r) >> 1;
    int ans = -1;

    if (qR > mid) ans = last_dif(rSon, mid + 1, r, qL, qR, n1->son[1], n2->son[1]);
    if (ans > -1) return ans;
    return last_dif(lSon, l, mid, qL, qR, n1->son[0], n2->son[0]);
}

int find_hsh(int node, int l, int r, int pos, pers* act) {
    if (l == r) return act->hsh;
    int mid = (l + r) >> 1;
    if (pos <= mid) return find_hsh(lSon, l, mid, pos, act->son[0]);
    return find_hsh(rSon, mid + 1, r, pos, act->son[1]);
}

int prov[maxN];
pers* Head[maxN];
bool done[maxN];

struct cmp {
    bool operator()(pair<int, pers*> a, pair<int, pers*> b) {
        static int pos, h1, h2;

        pos = last_dif(1, 1, def, 1, def, a.second, b.second);
        h1 = find_hsh(1, 1, def, pos, a.second);
        h2 = find_hsh(1, 1, def, pos, b.second);

        return h1 > h2;
    }
};

int n, m, x, y, z, i, S, T;
vector< pair<int, int> > list[maxN];
pers *H0, *H1, *aux;

cmp useful;
priority_queue< pair<int, pers*>, vector< pair<int, pers*> >, cmp> H;
vector<int> ans;

pers* sumi(pers* act, int bit) {
    int pos = first_dif(1, 1, def, bit, def, act, H1);
    if (pos != bit) act = update(1, 1, def, bit, pos - 1, act, H0);
    act = update(1, 1, def, pos, pos, act, H1);
    return act;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    shl[0] = 1;
    for (i = 1; i <= def; i++) shl[i] = (shl[i - 1] * base) % mod;

    H0 = build(1, 1, def, 0);
    H1 = build(1, 1, def, 1);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    for (i = 1; i <= n; i++) Head[i] = H1;
    scanf("%d%d", &S, &T);
    Head[S] = H0; prov[S] = S;
    H.push(mp(S, Head[S]));

    while (!H.empty()) {
        int node = H.top().first;
        H.pop();

        if (node == T) break;
        if (done[node]) continue;
        done[node] = true;

        for (auto to : list[node]) {
            if (done[to.first]) continue;
            Head[0] = sumi(Head[node], to.second + 1);

            if (!useful(mp(0, Head[0]), mp(to.first, Head[to.first]))) {
                Head[to.first] = Head[0];
                prov[to.first] = node;
                H.push(mp(to.first, Head[to.first]));
            }
        }
    }

    if (prov[T] == 0) {
        printf("-1");
        return 0;
    }

    for (int node = T; node != S; node = prov[node]) ans.pb(node);
    ans.pb(S);
    reverse(ans.begin(), ans.end());


    printf("%lld\n", Head[T]->hsh);
    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);




    return 0;
}