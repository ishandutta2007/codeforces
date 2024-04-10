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

#define maxN 211
#define inf 1000000LL

int cnt;
ll d1[maxN][maxN], d2[maxN][maxN];

struct way {
    int i, j, k;
    ll dp[maxN][maxN];

    void operator*=(way &who) {
        memcpy(d1, dp, sizeof(d1));
        memcpy(d2, who.dp, sizeof(d2));

        for (i = 1; i <= cnt; i++) {
            for (j = 1; j <= cnt; j++) {
                dp[i][j] = -inf;
                for (k = 1; k <= cnt; k++)
                    if (d1[i][k] != -inf && d2[k][j] != -inf)
                        dp[i][j] = max(dp[i][j], d1[i][k] + d2[k][j]);
            }
        }
    }
};

struct node {
    node *son[26];
    node *fail;
    int id;

    node(int _id) {
        memset(son, 0, sizeof(son));
        fail = NULL;
        id = _id;
    }
};

int n, i, j, dim;
ll lung;
int a[maxN];
char s[maxN];

int enjoy[maxN];
node* Head;
queue<node*> Q;

way ini;
ll ans;


void add_word(int pas) {
    int i;
    node* act;

    act = Head;
    for (i = 1; i <= dim; i++) {
        int go = s[i] - 'a';

        if (act->son[go] == NULL)
            act->son[go] = new node(++cnt);
        act = act->son[go];
    }

    enjoy[act->id] += a[pas];
}

node* get_node(node* act, int go) {
    while (act != Head && act->son[go] == NULL)
        act = act->fail;
    if (act->son[go] != NULL)
        act = act->son[go];
    return act;
}

void pre() {
    int i;

    Head->fail = Head;
    Q.push(Head);

    while (!Q.empty()) {
        node* act = Q.front(); Q.pop();

        for (i = 0; i < 26; i++) {
            if (act->son[i] == NULL) {
                node* aux = get_node(act, i);
                ini.dp[act->id][aux->id] = enjoy[aux->id];
                continue;
            }

            Q.push(act->son[i]);
            if (act == Head)
                act->son[i]->fail = Head;
            else
                act->son[i]->fail = get_node(act->fail, i);

            enjoy[act->son[i]->id] += enjoy[act->son[i]->fail->id];
            ini.dp[act->id][act->son[i]->id] = enjoy[act->son[i]->id];
        }
    }
}

way poww(way ini, ll how) {
    way ans = ini;
    how--;

    while (how) {
        if (how & 1) ans *= ini;
        how >>= 1;
        ini *= ini;
    }

    return ans;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &lung);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("\n");

    cnt = 1;
    Head = new node(1);

    for (i = 1; i <= n; i++) {
        memset(s, 0, dim + 3);
        scanf("%s\n", s + 1);
        dim = strlen(s + 1);

        add_word(i);
    }

    memset(ini.dp, 0, sizeof(ini.dp));
    for (i = 1; i < maxN; i++)
        for (j = 1; j < maxN; j++)
            ini.dp[i][j] = -inf;
    pre();

    ini = poww(ini, lung);
    for (i = 2; i <= cnt; i++)
        ans = max(ans, ini.dp[1][i]);

    printf("%lld", ans);

    return 0;
}