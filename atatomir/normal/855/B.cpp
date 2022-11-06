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

ll n, i, p, q, r;
ll a[maxN], le[maxN], ri[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> p >> q >> r;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1)
            le[i] = a[i] * p;
        else
            le[i] = max(le[i - 1], a[i] * p);
    }

    ri[n] = r * a[n];
    for (i = n - 1; i > 0; i--)
        ri[i] = max(ri[i + 1], a[i] * r);

    ll ans = -(1LL << 63);
    for (i = 1; i <= n; i++)
        ans = max(ans, le[i] + ri[i] + a[i] * q);

    cout << ans;


    return 0;
}