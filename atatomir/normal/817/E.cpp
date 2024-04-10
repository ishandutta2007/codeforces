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

const int bts = 28;

struct node {
    node* son[2];
    int cnt;

    node() {
        son[0] = son[1] = 0;
        cnt = 0;
    }
};

int n, i, op, p, l, frs;
node* Head;

void add_nr(int x, int rat) {
    int i;
    node* act = Head;

    //if (frs == 3 && n == 100) return;

    for (i = bts; i >= 0; i--) {
        int go = (x >> i) & 1;
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
        act->cnt += rat;
    }
}

int solve(int p, int l) {
    int i;
    node* act = Head;
    int ans = 0;

    //if (frs == 3 && n == 100) return 0;

    for (i = bts; i >= 0; i--) {
        int p_bit = (p >> i) & 1;
        int l_bit = (l >> i) & 1;

        if (l_bit == 1 && act->son[p_bit] != NULL)
            ans += act->son[p_bit]->cnt;

        if (act->son[l_bit ^ p_bit] == NULL) return ans;
        act = act->son[l_bit ^ p_bit];
    }

    //ans += act->cnt;
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    Head = new node();
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &op, &p);
        if (frs == 0) frs = op;

        if (op == 1)
            add_nr(p, +1);

        if (op == 2)
            add_nr(p, -1);

        if (op == 3) {
            scanf("%d", &l);
            printf("%d\n", solve(p, l));
        }
    }


    return 0;
}