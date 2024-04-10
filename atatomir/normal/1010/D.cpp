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

const int maxN = 1000011;

struct node {
    int tp;
    int son[2];
};

int n, i, x, y, cnt;
char s[11];
node data[maxN];

vector<int> stor[maxN * 4];
int id[maxN][2], here[maxN];
int ans[maxN];

int Merge(int id1, int id2) {
    if (stor[id1].size() < stor[id2].size()) swap(id1, id2);
    for (auto e : stor[id2]) stor[id1].pb(e);
    stor[id2].clear();
    return id1;
}

void solve(int node) {
    int s0, s1, tmp;

    s0 = data[node].son[0];
    s1 = data[node].son[1];

    id[node][0] = ++cnt;
    id[node][1] = ++cnt;

    if (data[node].tp == 4) {
        here[node] = s0;
        stor[ id[node][ 1 ^ s0 ] ].pb(node);
        return;
    }

    if (data[node].tp == 3) {
        solve(s0);

        id[node][0] = id[s0][1];
        id[node][1] = id[s0][0];
        here[node] = here[s0] ^ 1;
        return;
    }

    solve(s0);
    solve(s1);

    if (data[node].tp == 2) {
        for (tmp = 0; tmp < 2; tmp++) {

            id[node][0 ^ here[s1]] = Merge(id[node][0 ^ here[s1]], id[s0][0]);
            id[node][1 ^ here[s1]] = Merge(id[node][1 ^ here[s1]], id[s0][1]);

            swap(s0, s1);
        }

        here[node] = (here[s0] ^ here[s1]);
        return;
    }

    if (data[node].tp == 1) {
        for (tmp = 0; tmp < 2; tmp++) {

            id[node][0 | here[s1]] = Merge(id[node][0 | here[s1]], id[s0][0]);
            id[node][1 | here[s1]] = Merge(id[node][1 | here[s1]], id[s0][1]);

            swap(s0, s1);
        }
        here[node] = (here[s0] | here[s1]);
        return;
    }

    if (data[node].tp == 0) {
        for (tmp = 0; tmp < 2; tmp++) {

            id[node][0 & here[s1]] = Merge(id[node][0 & here[s1]], id[s0][0]);
            id[node][1 & here[s1]] = Merge(id[node][1 & here[s1]], id[s0][1]);

            swap(s0, s1);
        }
        here[node] = (here[s0] & here[s1]);
        return;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s%d", s + 1, &x);
        if (s[1] == 'A') data[i].tp = 0;
        if (s[1] == 'O') data[i].tp = 1;
        if (s[1] == 'X') data[i].tp = 2;
        if (s[1] == 'N') data[i].tp = 3;
        if (s[1] == 'I') data[i].tp = 4;

        data[i].son[0] = x;
        if (data[i].tp <= 2) scanf("%d", &data[i].son[1]);
        scanf("\n");
    }

    solve(1);
    for (auto e : stor[id[1][1]]) ans[e] = 1;

    for (i = 1; i <= n; i++)
        if (data[i].tp == 4)
            printf("%d", ans[i]);



    return 0;
}