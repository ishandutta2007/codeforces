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

const int bts = 30;

struct node {
    int cnt;
    node* son[2];

    node() {
        cnt = 0;
        son[0] = son[1] = NULL;
    }
};

int n, i;
int A[maxN];
int P[maxN];

node* Head;

void add_key(int x) {
    int i, go;
    node* act;

    act = Head;
    for (i = bts - 1; i >= 0; i--) {
        act->cnt++;
        go = (x >> i) & 1;
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
    }
    act->cnt++;
}

int get_best(int x) {
    int i, go;
    node* act;

    act = Head;
    for (i = bts - 1; i >= 0; i--) {
        act->cnt--;
        go = (x >> i) & 1;

        if (act->son[go] == NULL) go ^= 1;
        if (act->son[go]->cnt == 0) go ^= 1;

        x ^= (go << i);
        act = act->son[go];
    }
    act->cnt--;

    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    Head = new node();

    for (i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        add_key(P[i]);
    }

    for (i = 1; i <= n; i++) {
        printf("%d ", get_best(A[i]));
    }

    return 0;
}