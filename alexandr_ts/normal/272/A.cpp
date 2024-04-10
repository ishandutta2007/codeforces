#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef long long ll;

int a[10000];
vector <int> b;

main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n = 0, s = 0, ans = 0;
    cin >> n;
    fr(i, n)
    {
        cin >> a[i];
        s += a[i];
    }
    frab(i, 1, 6)
    {
        if ((s + i) % (n + 1) != 1)
            ans++;
    }
    cout << ans;
}