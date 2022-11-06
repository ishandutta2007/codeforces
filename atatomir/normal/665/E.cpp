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

#define maxN 1000011
#define bits 30
#define sigma 2

struct node {
    int cnt;
    node* son[sigma];

    node() {
        cnt = 0;
        memset(son, 0, sizeof(son));
    }
};

int n, i, k;
int a[maxN];

node *Head;
ll ans;

void add_nr(int x) {
    node* act = Head;

    for (int bit = (1 << bits) >> 1; bit; bit >>= 1) {
        if (x & bit) {
            if (act->son[1] == NULL) act->son[1] = new node();
            act = act->son[1];
        } else {
            if (act->son[0] == NULL) act->son[0] = new node();
            act = act->son[0];
        }

        act->cnt++;
    }
}

int query(node* act, int bit, int seed, int l, int r, int k) {
    if (act == NULL)
        return 0;
    if (k <= l)
        return act->cnt;

    int rev = ((seed & bit) > 0 ? 1 : 0);
    int mid = (l + r) >> 1;

    int ans = 0;

    if (k <= mid)
        ans += query(act->son[rev], bit >> 1, seed, l, mid, k);
    ans += query(act->son[1 ^ rev], bit >> 1, seed, mid + 1, r, k);

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);
    Head = new node();

    scanf("%d%d", &n, &k);

    add_nr(0);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];

        ans += 1LL * query(Head, (1 << (bits - 1)), a[i], 0, (1 << bits) - 1, k);
        add_nr(a[i]);
    }

    printf("%lld", ans);


    return 0;
}