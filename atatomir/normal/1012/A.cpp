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

const int maxN = 200011;

int n, i;
ll a[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= 2 * n; i++) cin >> a[i];
    sort(a + 1, a + 2 * n + 1);

    ll ans = 1LL * (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
    for (i = 2; i <= n; i++)
        ans = min(ans, 1LL * (a[i + n - 1] - a[i]) * (a[2 * n] - a[1]));

    cout << ans;


    return 0;
}