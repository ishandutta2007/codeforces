#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <unordered_set>
#include <bits/unordered_map.h>
#include <assert.h>
#include <fstream>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

struct node {
    node *nxt[26];
    node *lnk;
    vector<node*> adj;
    int tin, tout;
    int used;
    node() {
        fill(nxt, nxt + 26, nullptr);
        lnk = nullptr;
        used = 0;
    }
};

node *root = new node();
vector<node*> was({root});

node* add(string s) {
    auto v = root;
    for (char ch : s) {
        ch -= 'a';
        if (!v->nxt[ch]) {
            v->nxt[ch] = new node();
            was.pb(v->nxt[ch]);
        }
        v = v->nxt[ch];
    }
    return v;
}

void buildLinks() {
    queue<node*> q;
    root->lnk = root;
    q.push(root);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (v->nxt[i]) {
                v->nxt[i]->lnk = v->lnk;
                while (true) {
                    if (v->nxt[i]->lnk->nxt[i]) {
                        v->nxt[i]->lnk = v->nxt[i]->lnk->nxt[i];
                        break;
                    }

                    if (v->nxt[i]->lnk == root) {
                        break;
                    }
                    v->nxt[i]->lnk = v->nxt[i]->lnk->lnk;
                }

                if (v == root) {
                    v->nxt[i]->lnk = root;
                }

                v->nxt[i]->lnk->adj.pb(v->nxt[i]);
                q.push(v->nxt[i]);
            }
        }
    }
}

const int maxn = 5e5 + 5;

int timer = 1;
void dfs(node *v) {
    v->tin = timer++;
    v->used = 1;
    for (auto to : v->adj) {
        dfs(to);
    }
    v->tout = timer;
}

int ft[maxn];

void inc(int i) {
    while (i < maxn) {
        ft[i]++;
        i = i | (i + 1);
    }
}

int sum(int r) {
    int res = 0;
    while (r >= 0) {
        res += ft[r];
        r = (r & (r + 1)) - 1;
    }
    return res;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

char tmp[maxn];
int ans[maxn];
int qk[maxn];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d\n", &n, &m);

    vector<string> a;
    vector<node*> ends;

    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        a.pb(tmp);
        ends.pb(add(tmp));
    }


    buildLinks();

    for (auto v : was) {
        if (!v->used) {
            dfs(v);
        }
    }

    vector<pair<int, int>> ev;
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d %d %d", &l, &r, qk + i);
        l--, r--, qk[i]--;
        ev.emplace_back(l - 1, -i);
        ev.emplace_back(r, i);
    }

    sort(ev.begin(), ev.end());


    int p = 0;
    for (auto e : ev) {
        while (p <= e.fst) {
            auto v = root;
            for (char ch : a[p]) {
                ch -= 'a';
                while (v != root && !v->nxt[ch]) {
                    v = v->lnk;
                }

                if (v->nxt[ch]) {
                    v = v->nxt[ch];
                }

                inc(v->tin);
            }
            p++;
        }

        int s = qk[abs(e.snd)];

        if (e.snd > 0) {
            ans[e.snd] += sum(ends[s]->tin, ends[s]->tout - 1);
        } else {
            e.snd = -e.snd;
            ans[e.snd] -= sum(ends[s]->tin, ends[s]->tout - 1);
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}