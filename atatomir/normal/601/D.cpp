#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 300011

struct Trie {
    Trie *son[26];

    Trie() {
        for (int i = 0; i < 26; i++)
            son[i] = NULL;
    }
};

int n, i, x, y;
int c[maxN];
char s[maxN];
vector<int> list[maxN];
int cnt[maxN];
bool us[maxN];
Trie *R[maxN];

int aux;
int ans, how;

void compact_trie(Trie *D, Trie *S) {
    for (int i = 0; i < 26; i++) {
        if (S->son[i] == NULL) continue;

        if (D->son[i] == NULL) {
            aux++;
            D->son[i] = new Trie();
        }

        compact_trie(D->son[i], S->son[i]);
    }

    delete S;
}

void dfs(int node) {
    int best = 0;
    us[node] = true;

    for (int i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (us[to]) {
            list[node][i] = list[node][ list[node].size() - 1 ];
            list[node].pop_back();
            i--;
            continue;
        }

        dfs(to);
        if (cnt[to] > cnt[ list[node][best] ])
            best = i;
    }

    if (list[node].size() == 0) {
        R[node] = new Trie();
        cnt[node] = 1;
        return;
    }

    swap(list[node][best], list[node][ list[node].size() - 1 ]);
    best = list[node][ list[node].size() - 1 ];
    list[node].pop_back();

    R[node] = new Trie();
    R[node]->son[ s[best] - 'a' ] = R[ best ];
    cnt[node] += 1 + cnt[ best ];

    aux = 0;
    for (auto to : list[node]) {
        Trie *act;

        if (R[node]->son[ s[to] - 'a' ] == NULL) {
            aux++;
            R[node]->son[ s[to] - 'a' ] = new Trie();
        }

        compact_trie(R[node]->son[ s[to] - 'a' ], R[to]);
    }
    cnt[node] += aux;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    scanf("\n%s\n", s + 1);

    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1);

    ans = -1;
    for (i = 1; i <= n; i++) {
        if (ans == c[i] + cnt[i])
            how++;
        else
        if (ans < c[i] + cnt[i]) {
            ans = c[i] + cnt[i];
            how = 1;
        }
    }

    printf("%d\n%d", ans, how);

    return 0;
}