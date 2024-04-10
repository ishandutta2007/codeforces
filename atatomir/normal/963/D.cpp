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

const int maxN = 100011;
const int sigma = 26;

struct node {
    node* son[sigma];
    node *fail, *fast;
    int qid;

    node() {
        memset(son, 0, sizeof(son));
        fail = fast = NULL;
        qid = 0;
    }
};

int n, q, i, m, j;
char s[maxN], data[maxN];
int cnt[maxN], sz[maxN];
vector<int> wh[maxN];

node* Head;
queue<node*> Q;

void add_word(int query_id) {
    int i, go;
    node* act;

    act = Head;
    for (i = 1; i <= m; i++) {
        go = data[i] - 'a';
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
    }

    act->qid = query_id;
}

node* get_next(node* act, int src) {
    while (act->son[src] == NULL && act != Head) act = act->fail;
    if (act->son[src] != NULL) return act->son[src];
    return Head;
}

void build_aho() {
    int i;

    Q.push(Head);
    Head->fail = Head->fast = Head;

    while (!Q.empty()) {
        node* act = Q.front(); Q.pop();

        for (i = 0; i < sigma; i++) {
            if (act->son[i] == NULL) continue;

            act->son[i]->fail = get_next(act->fail, i);
            if (act == Head) act->son[i]->fail = Head;
            Q.push(act->son[i]);

            if (act->son[i]->fail->qid != 0)
                act->son[i]->fast = act->son[i]->fail;
            else
                act->son[i]->fast = act->son[i]->fail->fast;
        }
    }
}

void run() {
    int i, go;
    node* act = Head;
    node* aux;

    for (i = 1; i <= n; i++) {
        go = s[i] - 'a';

        act = get_next(act, go);
        for (aux = act; aux != Head; aux = aux->fast)
            if (aux->qid != 0)
                wh[aux->qid].pb(i);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    Head = new node();

    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    for (i = 1; i <= q; i++) {
        scanf("%d %s", &cnt[i], data + 1);
        m = strlen(data + 1);
        sz[i] = m;
        add_word(i);
        memset(data, 0, m + 3);
    }

    build_aho();
    run();

    for (i = 1; i <= q; i++) {
        if (wh[i].size() < cnt[i]) {
            printf("-1\n");
        } else {
            int ans = n;
            for (j = cnt[i] - 1; j < wh[i].size(); j++)
                ans = min(ans, wh[i][j] - wh[i][j - cnt[i] + 1] + sz[i]);
            printf("%d\n", ans);
        }
    }



    return 0;
}