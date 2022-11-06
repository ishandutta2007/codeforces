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

#define maxN 777
#define maxLen 10000011

struct node {
    node* son[2];
    node *fail, *last;
    short id;

    node() {
        son[0] = son[1] = NULL;
        fail = last = NULL;
        id = 0;
    }
};

int n, i, j, k;
string s[maxN];
node* Head;
queue<node*> Q;

bool edg[maxN][maxN];
int l[maxN], r[maxN];
bool us[maxN];
bool dead[maxN];
vector<int> ans;

bool on_l[maxN], on_r[maxN];

void add_word(int id) {
    int i;
    node* act = Head;

    for (i = 0; i < s[id].size(); i++) {
        int go = s[id][i] - 'a';
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
    }

    act->id = id;
}

node* get_fail(node* act, int go) {
    while (act != Head && act->son[go] == NULL) act = act->fail;
    if (act->son[go] != NULL) act = act->son[go];
    return act;
}

void build() {
    node* act;
    int i;

    Q.push(Head);

    while (!Q.empty()) {
        act = Q.front(); Q.pop();

        for (i = 0; i < 2; i++) {
            if (act->son[i] == NULL) continue;

            if (act == Head) {
                act->son[i]->fail = Head;
                act->son[i]->last = (act->son[i]->id > 0 ? act->son[i] : Head);
            } else {
                act->son[i]->fail = get_fail(act->fail, i);
                act->son[i]->last = (act->son[i]->id > 0 ? act->son[i] : act->son[i]->fail->last);
            }

            Q.push(act->son[i]);
        }
    }
}

void add_edges(int id) {
    int i, go;
    node* act = Head;

    for (i = 0; i < s[id].size(); i++) {
        if (act->last != Head)
            edg[id][act->last->id] = true;

        go = s[id][i] - 'a';
        act = act->son[go];
    }

    if (act->fail->last != Head)
        edg[id][act->fail->last->id] = true;
}

bool pairUp(int x) {
    if (us[x] == true) return false;
    us[x] = true;

    for (int i = 1; i <= n; i++) {
        if (!edg[x][i]) continue;
        if (r[i] == 0) {
            l[x] = i;
            r[i] = x;
            return true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!edg[x][i]) continue;
        if (pairUp(r[i])) {
            l[x] = i;
            r[i] = x;
            return true;
        }
    }

    return false;
}

void support(int x) {
    int i;

    for (i = 1; i <= n; i++) {
        if (!edg[x][i]) continue;
        if (on_r[i] == true) continue;
        on_r[i] = true;
        on_l[r[i]] = false;
        support(r[i]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    Head = new node();
    Head->fail = Head->last = Head;

    for (i = 1; i <= n; i++) {
        cin >> s[i];
        add_word(i);
    }

    build();
    for (i = 1; i <= n; i++)
        add_edges(i);

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                edg[i][j] |= edg[i][k] && edg[k][j];

    bool ok = true;
    while (ok) {
        ok = false;
        memset(us, 0, sizeof(us));

        for (i = 1; i <= n; i++)
            if (!l[i])
                ok |= pairUp(i);
    }

    for (i = 1; i <= n; i++)
        if (l[i])
            on_l[i] = true;

    for (i = 1; i <= n; i++)
        if (!on_l[i])
            support(i);

    for (i = 1; i <= n; i++)
        if (!on_l[i] && !on_r[i])
            ans.pb(i);

    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);


    return 0;
}