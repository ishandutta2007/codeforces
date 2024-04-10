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

#define maxN 111

int n, i, fr, cnt;
int to[maxN];
bool us[maxN];
ll ans = 1;

void dfs(int node) {
    us[node] = true;
    cnt++;

    if (to[node] == fr) return;
    if (us[to[node]]) {
        printf("-1");
        exit(0);
    }

    dfs(to[node]);
}

ll cmmdc(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b != 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &to[i]);

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        fr = i; cnt = 0;
        dfs(i);

        if (cnt % 2 == 0) cnt >>= 1;
        ans = (ans * cnt) / cmmdc(ans, cnt);
    }

    printf("%lld", ans);


    return 0;
}