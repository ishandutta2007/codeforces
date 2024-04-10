#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 5111

int n, i, x, a, b, c, d;
vector<int> list[maxN];

int cnt[maxN];
int who[maxN];
int cnt_a, cnt_b, cnt_c, cnt_d;
vector<int> aux;

bitset<maxN> B;

void dfs(int node) {
    if (list[node].empty()) {
        cnt[node] = 1;
        if (node == a || node == b || node == c || node == d)
            who[node] = node;
        return;
    }

    for (auto to : list[node]) {
        dfs(to);
        cnt[node] += cnt[to];
        who[node] = max(who[node], who[to]);
    }
}

void dfs2(int node) {
    for (auto to : list[node]) {
        if (who[to] > 0) continue;
        aux.pb(cnt[to]);
    }

    for (auto to : list[node])
        if (who[to])
            dfs2(to);
}

bool knapsack(int n1, int n2, int need) {
    int i;

    if (need < 0) return false;
    aux.clear();
    for (auto to : list[1]) {
        if (who[to] == 0) {
            aux.pb(cnt[to]);
            continue;
        }

        if (who[to] != n1 && who[to] != n2) continue;
        dfs2(to);
    }

    B.reset();
    B[0] = 1;

    for (auto e : aux)
        B = B | (B << e);

    return B[need];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
    }

    dfs(1);
    if (cnt[1] % 2 == 1) {
        printf("NO");
        return 0;
    }

    for (auto to : list[1]) {
        if (who[to] == a) cnt_a = cnt[to];
        if (who[to] == b) cnt_b = cnt[to];
        if (who[to] == c) cnt_c = cnt[to];
        if (who[to] == d) cnt_d = cnt[to];
    }

    if (!knapsack(a, b, (cnt[1] - 2) / 2 - cnt_b)) {
        printf("NO");
        return 0;
    }

    if (!knapsack(c, d, (cnt[1] - 2) / 2 - cnt_b)) {
        printf("NO");
        return 0;
    }

    printf("YES");


    return 0;
}