#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000000];
ll b[1000000];
ll d[100000];
ll ans[2000000];

main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= m - cur)
            cur += a[i];
        else
            q++, cur = a[i];
    }
    if (cur > 0)
        q++;
    cout << q;

}