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

#define maxN 100011

int n, i, x;
int v[maxN];

vector<int> dvs[maxN];

int cnt[maxN];
int ans;

void pre() {
    ll i, j;

    for (i = 2; i <= 100000; i++) {
        if (dvs[i].size()) continue;

        for (j = i; j <= 100000; j += i)
            dvs[j].pb(i);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);

    pre();
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (auto e : dvs[x])
            cnt[e]++;
    }

    ans = 1;
    for (i = 2; i <= 100000; i++)
        ans = max(ans, cnt[i]);

    printf("%d", ans);


    return 0;
}