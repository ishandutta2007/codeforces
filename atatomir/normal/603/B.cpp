#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 1000011
#define ll long long
#define mod 1000000007

ll n, k, i;
bool us[maxN];
int cnt = 0;

void dfs(ll node) {
    us[node] = true;

    ll to = (k * node) % n;
    if (!us[to])
        dfs(to);
}

long long ans = 1;

long long myPow(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        b--;

        ans = (ans * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d%I64d", &n, &k);

    if (k == 0) {
        printf("%I64d", myPow(n, n - 1));
        return 0;
    }
    if (k == 1) {
        printf("%I64d", myPow(n, n));
        return 0;
    }

    for (i = 1; i < n; i++) {
        if (us[i]) continue;
        cnt++;
        dfs(i);
    }

    printf("%I64d", myPow(n, cnt));

    return 0;
}