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

#define mod 1000000007

#define maxN 200011

int n, i, id;
int go[maxN];
bool us[maxN];
int when[maxN];
int st[maxN];

int sum;
vector<int> dims;

ll poww[maxN];

void dfs(int node, int pos) {
    us[node] = true;
    when[node] = id;
    st[node] = pos;

    if (us[go[node]]) {
        if (when[go[node]] == id) {
            // i found a cycle
            dims.pb(pos - st[ go[node] ] + 1);
            return;
        } else {
            return; // sad ...
        }
    } else {
        dfs(go[node], pos + 1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &go[i]);

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        id = i;
        dfs(i, 0);
    }

    for (auto e : dims) sum += e;
    sum = n - sum;

    poww[0] = 1;
    for (i = 1; i <= n; i++) poww[i] = (poww[i - 1] * 2) % mod;

    ll ans = poww[sum];
    for (auto e : dims)
        ans = (ans * (mod + poww[e] - 2)) % mod;

    printf("%lld", ans);

    return 0;
}