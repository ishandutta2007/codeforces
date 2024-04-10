#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;

struct tmp
{
    int x, y;
};

int a[100000];

main()
{

    int n, m;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    ll ans = max(0ll, 2 * s - 1);
    for (int i = 0; i < n - 1; i++)
        if (a[i] && a[i + 1])
            ans--;
    cout << ans;



}