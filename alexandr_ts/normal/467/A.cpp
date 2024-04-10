#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll h1[N], p[N], a[N], b[N];
ll h;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int t1, t2, ans = 0;
    for (int i = 0; i < n; i++)
        {cin >> t1 >> t2; if (t2 - t1 >= 2) ans++;}
    cout << ans;
}