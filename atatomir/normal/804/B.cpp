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
#define mod 1000000007

int n, i, cnt;
char s[maxN];
ll pre[maxN];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    pre[0] = 1;
    for (i = 1; i <= n; i++) pre[i] = (pre[i - 1] * 2) % mod;

    ans = mod;
    for (i = 1; i <= n; i++) {
        if (s[i] == 'a') {
            cnt++;
        } else {
            ans += pre[cnt] - 1;
        }
    }

    ans %= mod;
    cout << ans;

    return 0;
}