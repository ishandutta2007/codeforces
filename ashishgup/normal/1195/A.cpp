#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, k;
int a[N], f[N];

int32_t main()
{
    IOS;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    int reqdOdd = 0, ans = 0, rem = (n + 1) / 2;
    for(int i = 1; i <= k; i++)
    {
        reqdOdd += (f[i] % 2);
        ans += (f[i] / 2) * 2;
        rem -= f[i] / 2;
    }
    ans += rem;
    cout << ans;
    return 0;
}