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

#define maxN 50011
#define maxVal 1000011
#define sigma 2
#define inf 1000000000
#define bits 20

struct query {
    int l, r, id;
};

struct node {
    node* son[2];
    int lowest;

    node() {
        son[0] = son[1] = NULL;
        lowest = inf;
    }
};

void add_number(node *act, int nr, int tag) {
    act->lowest = min(act->lowest, tag);

    for (int i = bits - 1; i >= 0; i--) {
        int go = (nr >> i) & 1;

        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
        act->lowest = min(act->lowest, tag);
    }
}

int check(node* act, int nr, int tag) {
    if (act->lowest > tag) {
        //cerr << "no good number in trie";
        return nr;
    }

    for (int i = bits - 1; i >= 0; i--) {
        int go = (nr >> i) & 1;
        go ^= 1;

        if (act->son[go] == NULL) go ^= 1;
        if (act->son[go]->lowest > tag) go ^= 1;

        act = act->son[go];
        if (go) nr ^= (1 << i);
    }

    return nr;
}

void remove_nodes(node *act) {
    for (int i = 0; i < sigma; i++)
        if (act->son[i] != NULL)
            remove_nodes(act->son[i]);
    delete act;
}



int n, q, qbig, i, j, sz;
int a[maxN], pre[maxVal];
query Q[maxN];
int ans[maxN];

node *mini, *maxi;


bool cmp(const query& a, const query& b) {
    return mp(a.l / sz, a.r) < mp(b.l / sz, b.r);
}

int brute(int l, int r) {
    int i;
    node* Head;
    int ans = 0;

    Head = new node();
    for (i = l; i <= r; i++)
        add_number(Head, pre[a[i] - 1], a[i]);

    for (i = l; i <= r; i++)
        ans = max(ans, check(Head, pre[a[i]], a[i]));

    remove_nodes(Head);
    return ans;
}

void solve_brute() {
    int pos, i;

    pos = 0;
    for (i = 1; i <= q; i++) {
        if (Q[i].r - Q[i].l + 1 > sz) {
            Q[++pos] = Q[i];
            continue;
        }

        ans[Q[i].id] = brute(Q[i].l, Q[i].r);
    }

    qbig = q;
    q = pos;
}

int new_local_value(int pos) {
    add_number(mini, pre[ a[pos] - 1 ], a[pos]);
    add_number(maxi, pre[a[pos]], -a[pos]);

    int ans = 0;

    ans = max(ans, check(mini, pre[a[pos]], a[pos]));
    ans = max(ans, check(maxi, pre[a[pos] - 1], -a[pos]));

    return ans;
}

void solve_bucket(int l, int r) {
    int i, j, pos, local;
    int bg = sz * (Q[l].l / sz) + sz;
    node *aux;

    mini = new node();
    maxi = new node();

    pos = bg - 1;
    local = 0;

    for (i = l; i <= r; i++) {
        while (pos < Q[i].r)
            local = max(local, new_local_value(++pos));

        ans[Q[i].id] = local;

        aux = new node();
        for (j = Q[i].l; j < bg; j++)
            add_number(aux, pre[a[j] - 1], a[j]);

        for (j = Q[i].l; j < bg; j++) {
            ans[Q[i].id] = max(ans[Q[i].id], check(aux, pre[a[j]], a[j]));
            ans[Q[i].id] = max(ans[Q[i].id], check(mini, pre[a[j]], a[j]));
            ans[Q[i].id] = max(ans[Q[i].id], check(maxi, pre[a[j] - 1], -a[j]));
        }

        remove_nodes(aux);
    }

    remove_nodes(mini);
    remove_nodes(maxi);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= q; i++) scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].id = i;
    for (i = 1; i < maxVal; i++) pre[i] = pre[i - 1] ^ i;

    sz = sqrt(n);
    solve_brute();

    sort (Q + 1, Q + q + 1, cmp);

    for (i = 1; i <= q; i = j) {
        for (j = i; j <= q && Q[i].l / sz == Q[j].l / sz; j++);
        solve_bucket(i, j - 1);
    }

    for (i = 1; i <= qbig; i++)
        printf("%d\n", ans[i]);

    return 0;
}