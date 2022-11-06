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

struct trie {
    trie* son[2];
    int cnt;

    trie() {
        son[0] = son[1] = NULL;
        cnt = 0;
    }
};

int n, i, k, sol1;
int a[maxN], last[maxN], dif[maxN];
trie* Head[maxN];

trie* build(int node, int l, int r) {
    trie* act = new trie();

    if (l == r)
        return act;

    int mid = (l + r) >> 1;
    act->son[0] = build(lSon, l, mid);
    act->son[1] = build(rSon, mid + 1, r);

    return act;
}

trie* get_path(trie* node, int l, int r, int pos, int v) {
    trie* act = new trie();
    act->son[0] = node->son[0];
    act->son[1] = node->son[1];
    act->cnt = node->cnt + v;

    if (l == r)
        return act;

    int mid = (l + r) >> 1;
    if (pos <= mid) {
        act->son[0] = get_path(node->son[0], l, mid, pos, v);
        return act;
    } else {
        act->son[1] = get_path(node->son[1], mid + 1, r, pos, v);
        return act;
    }
}

int kth(trie* node, int l, int r, int cnt) {
    if (l == r) {
        if (node->cnt == 1 && cnt == 0)
            return l - 1;
        return l;
    }

    int mid = (l + r) >> 1;
    if (node->son[0]->cnt <= cnt) {
        cnt -= node->son[0]->cnt;
        return kth(node->son[1], mid + 1, r, cnt);
    } else {
        return kth(node->son[0], l, mid, cnt);
    }
}

int solve(int k) {
    int i;
    int ans = 0;
    int pos = n;

    while (pos > 0) {
        if (dif[pos] <= k)
            return ans + 1;

        ans++;
        pos = 1 + kth(Head[pos], 1, n, dif[pos] - k - 1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    Head[0] = build(1, 1, n);

    sol1 = 1;
    for (i = 2; i <= n; i++)
        if (a[i - 1] != a[i])
            sol1++;

    for (i = 1; i <= n; i++) {
        Head[i] = Head[i - 1];
        dif[i] = dif[i - 1];

        if (last[a[i]] != 0)
            Head[i] = get_path(Head[i], 1, n, last[a[i]], -1);
        else
            dif[i]++;

        last[a[i]] = i;
        Head[i] = get_path(Head[i], 1, n, i, +1);
    }

    printf("%d ", sol1);
    for (k = 2; k <= n; k++)
        printf("%d ", solve(k));


    return 0;
}