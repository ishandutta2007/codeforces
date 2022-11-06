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

#define sigma 26
#define maxN 300011

struct node {
    int id;
    node* son[sigma];

    node(int _id) {
        id = _id;
        memset(son, 0, sizeof(son));
    }
};

int n, i, x, y;
char c;
node* nodes[maxN];
int cnt[maxN];

queue<int> Q;
vector<int> ord;
int lvl[maxN];
int diss[maxN];

int global;

pair<int, int> best;

void bfs() {
    int node, i;

    Q.push(1);
    while (!Q.empty()) {
        node = Q.front(); Q.pop();
        ord.pb(node);

        for (i = 0; i < sigma; i++) {
            if (nodes[node]->son[i] != NULL) {
                Q.push(nodes[node]->son[i]->id);
                lvl[nodes[node]->son[i]->id] = lvl[node] + 1;
            }
        }
    }
}

void virt_add(node* n1, node* n2) {
    int i;

    if (n1->id <= 0) n1->id--;

    for (i = 0; i < sigma; i++) {
        if (n1->son[i] == NULL && n2->son[i] == NULL)
            continue;

        if (n1->son[i] != NULL && n2->son[i] == NULL)
            continue;

        if (n1->son[i] != NULL && n2->son[i] != NULL) {
            virt_add(n1->son[i], n2->son[i]);
            continue;
        }

        // nu exista in n1, exista in n2
        n1->son[i] = new node(0);
        global--;

        virt_add(n1->son[i], n2->son[i]);
    }
}

void virt_rm(node* &n1, node* &n2) {
    int i;

    if (n1->id < 0) n1->id++;

    for (i = 0; i < sigma; i++) {
        if (n1->son[i] == NULL && n2->son[i] == NULL)
            continue;

        if (n1->son[i] != NULL && n2->son[i] == NULL)
            continue;

        if (n1->son[i] != NULL && n2->son[i] != NULL) {
            virt_rm(n1->son[i], n2->son[i]);
            continue;
        }

    }

    if(n1->id == 0) {
        delete n1;
        n1 = NULL;
    }

}

void solve() {
    int i;
    vector<int> aux;

    auto cmp = [](int a, int b)->bool const {
        return cnt[a] > cnt[b];
    };

    reverse(ord.begin(), ord.end());
    for (int node : ord) {

        cnt[node] = 1;
        aux.clear();

        for (i = 0; i < sigma; i++) {
            if (nodes[node]->son[i] != NULL) {
                cnt[node] += cnt[ nodes[node]->son[i]->id ];
                aux.pb(nodes[node]->son[i]->id);
            }
        }

        sort(aux.begin(), aux.end(), cmp);

        if (aux.empty())
            continue;


        global = cnt[node] - cnt[aux[0]];

        for (i = 1; i < aux.size(); i++)
            virt_add(nodes[aux[0]], nodes[aux[i]]);

        for (i = 1; i < aux.size(); i++)
            virt_rm(nodes[aux[0]], nodes[aux[i]]);

        diss[lvl[node]] += global;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) nodes[i] = new node(i);

    for (i = 1; i < n; i++) {
        scanf("%d%d %c", &x, &y, &c);
        nodes[x]->son[c - 'a'] = nodes[y];
    }

    bfs();
    solve();

    for (i = 0; i <= n; i++)
        best = max(best, mp(diss[i], -i));

    printf("%d\n%d", n - best.first, -best.second + 1);




    return 0;
}