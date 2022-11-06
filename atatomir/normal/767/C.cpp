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

#define maxN 1000011

int n, i, x, sum, R;
int t[maxN], dad[maxN];
vector<int> list[maxN];

int dp[maxN];
int good[maxN];

void no_sol() {
    printf("-1");
    exit(0);
}

int abss(int x) {
    if (x < 0) return -x;
    return x;
}

void dfs(int node) {
    vector<int> aux = {};
    dp[node] = t[node];

    for (auto to : list[node]) {
        dfs(to);
        dp[node] += dp[to];

        if (good[to]) aux.pb(to);
    }


    if (aux.size() >= 2) {
        sort(aux.begin(), aux.end());
        printf("%d %d", good[aux[0]], good[aux[1]]);
        exit(0);
    }

	if (node == R) return;

    if (aux.size() >= 1 && dp[node] == 2 * sum) {
        sort(aux.begin(), aux.end());
        printf("%d %d", good[aux[0]], node);
        exit(0);
    }

    if (dp[node] == sum)
        good[node] = node;

    if (!aux.empty())
        good[node] = good[aux[0]];

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &dad[i], &t[i]);
        list[dad[i]].pb(i);

        sum += t[i];
        if (dad[i] == 0) R = i;
    }

    if (abss(sum) % 3 != 0)
        no_sol();

    sum /= 3;
    dfs(R);

    no_sol();



    return 0;
}