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

#define maxN 100011
#define sigma 26

const int bucket = 400;

struct que {
    int l, r, k, id;

    bool operator<(const que& who) const {
        return k < who.k;
    }
};

struct node {
    node *son[sigma];
    int cnt;
    node* fail;

    node() {
        memset(son, 0, sizeof(son));
        cnt = 0;
        fail = NULL;
    }
};

int n, m, i, j, l, r, k;
string s[maxN];
int sz[maxN];
vector< pair<int, int> > Q[maxN];
queue<node*> Que;

int p;
node* big_head, *small_head;
ll ans[maxN];

int dd;
char aux[maxN];
vector<que> sep;
vector<node*> order;
ll sums[maxN];


void add(node* act, string& s) {
    int i;
    for (i = 0; i < s.size(); i++) {
        int go = s[i] - 'a';
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
    }
    act->cnt++;
}

void add2(node* act, string& s) {
    int i;
    for (i = 0; i < s.size(); i++) {
        int go = s[i] - 'a';
        if (act->son[go] == NULL) act->son[go] = new node();
        act = act->son[go];
        act->cnt++;
    }
}

node* get(node * Head, node* act, int go) {
    while (act != Head && act->son[go] == NULL) act = act->fail;
    if (act->son[go] != NULL) act = act->son[go];
    return act;
}

void prop(node* Head, bool sumi = true) {
    Head->fail = Head;
    while (!Que.empty()) Que.pop();
    Que.push(Head);
    order.clear();

    while (!Que.empty()) {
        node* act = Que.front(); Que.pop();
        act->cnt += act->fail->cnt;
        order.pb(act);

        if (!sumi) act->cnt = 0;

        for (int i = 0; i < sigma; i++) {
            if (act->son[i] == NULL) continue;
            Que.push(act->son[i]);

            if (act == Head)
                act->son[i]->fail = act;
            else
                act->son[i]->fail = get(Head, act->fail, i);
        }
    }
}

ll sum(node* Head, string& s) {
    node* act = Head;
    ll ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int go = s[i] - 'a';
        act = get(Head, act, go);
        ans += 1LL * act->cnt;
    }

    return ans;
}

void rm(node* act) {
    for (int i = 0; i < sigma; i++)
        if (act->son[i] != NULL)
            rm(act->son[i]);
    delete act;
}

ll get_count(node* act, string& s) {
    for (int i = 0; i < s.size(); i++) {
        int go = s[i] - 'a';
        act = act->son[go];
    }
    return act->cnt;
}

void solve(int l, int r) {
    int i;
    int k;

    k = sep[l].k;

    if (big_head == NULL) {
        big_head = new node();
        for (i = 1; i <= n; i++)
            add(big_head, s[i]);

        prop(big_head, false);
        reverse(order.begin(), order.end());
    } else {
        for (auto e : order) e->cnt = 0;
    }

    add2(big_head, s[k]);

    for (auto e: order)
        e->fail->cnt += e->cnt;

    for (i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + get_count(big_head, s[i]);

    for (i = l; i <= r; i++)
        ans[sep[i].id] = sums[sep[i].r] - sums[sep[i].l - 1];

    //rm(big_head);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++)  {
        memset(aux, 0, dd + 3);
        scanf("%s\n", aux + 1);
        sz[i] = strlen(aux + 1);
        for (int j = 1; j <= sz[i]; j++)
            s[i].pb(aux[j]);
        sz[i] = sz[i - 1] + s[i].size();
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &l, &r, &k);

        if (s[k].size() > bucket) {
            sep.pb({l, r, k, i});
            continue;
        }

        Q[r].pb(mp(k, i));
        Q[l - 1].pb(mp(k, -i));
    }

    sort(sep.begin(), sep.end());
    for (i = 0; i < sep.size(); i = j) {
        for (j = i; j < sep.size(); j++)
            if (sep[j].k != sep[i].k)
                break;

        solve(i, j - 1);
    }

    big_head = new node();
    small_head = new node();
    prop(big_head);
    prop(small_head);

    p = 0;
    for (i = 1; i <= n; i++) {

        if (sz[i] - sz[p] > bucket) {
            p = i;
            rm(big_head);
            big_head = new node();
            for (j = 1; j <= p; j++) add(big_head, s[j]);
            prop(big_head);
        }

        rm(small_head);
        small_head = new node();
        for (j = p + 1; j <= i; j++)
            add(small_head, s[j]);
        prop(small_head);

        for (auto e : Q[i]) {
            if (e.second > 0) {
                ans[e.second] += sum(big_head, s[e.first]);
                ans[e.second] += sum(small_head, s[e.first]);
            } else {
                ans[-e.second] -= sum(big_head, s[e.first]);
                ans[-e.second] -= sum(small_head, s[e.first]);
            }
        }
    }

    for (i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);


    return 0;
}