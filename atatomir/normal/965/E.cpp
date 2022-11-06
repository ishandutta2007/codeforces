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

const int sigma = 26;
const int maxN = 100011;
const int limit = 100001;

struct node {
    node* son[sigma];
    node* dad;
    int lvl;
    bool used;

    node() {
        memset(son, 0, sizeof(son));
        dad = NULL;
        lvl = 0;
        used = false;
    }
};

int n, i, j, m;
char s[maxN];
node* Head;
vector<node*> to_do[maxN];
int ans;

void add_word() {
    int i, go;
    node* act;

    act = Head;
    for (i = 1; i <= m; i++) {
        go = s[i] - 'a';

        if (act->son[go] == NULL) {
            act->son[go] = new node();
            act->son[go]->lvl = act->lvl + 1;
            act->son[go]->dad = act;
        }
        act = act->son[go];
    }

    to_do[act->lvl].pb(act);
    act->used = true;
}

void mv(node* act) {
    node* aux;

    for (aux = act; aux != Head && aux->used == true; aux = aux->dad);
    if (aux == Head) {
        ans += act->lvl;
        return;
    }

    act->used = false;
    aux->used = true;
    to_do[aux->lvl].pb(aux);
}

int main()
{
    //freopen("test.in","r",stdin);

    Head = new node();
    Head->dad = Head;

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        m = strlen(s + 1);

        add_word();

        memset(s, 0, m + 3);
    }

    for (i = limit; i >= 1; i--) {
        for (auto act : to_do[i])
            mv(act);
        to_do[i].clear();
    }

    printf("%d", ans);


    return 0;
}