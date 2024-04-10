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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        b[a[i]]++;
    ll s = 0;
    for (int i = 1; i < 1000000; i++)
    {
        if (i == 1)
            ans[i] = b[i] * i;
        else
            ans[i] = max(ans[i - 1], ans[i - 2] + b[i] * i);
    }
    cout << ans[999999];


//    int n;
//    cin >> n;
//    if (n <= 2)
//    {
//        cout << -1;
//    }
//    else
//    {
//        for (int i = n; i >= 1; i--)
//            cout << i << " ";
//    }





}