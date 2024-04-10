#include <bits/stdc++.h>

using namespace std;

char arr[200010];
const int mod = 998244353;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d%s", &n, arr);


    int cnt1 = 0;
    for(i = 0; i < n; i++)
    {
        cnt1++;
        if(arr[i] != arr[0])
            break;
    }
    int cnt2 = 0;
    for(i = n - 1; i >= 0; i--)
    {
        cnt2++;
        if(arr[i] != arr[n - 1])
            break;
    }

    if(arr[0] == arr[n - 1])
    {
        int r = 1LL * cnt1 * cnt2 % mod;
        printf("%d\n", r);
    }
    else
    {
        int r = cnt1 + cnt2 - 1;
        printf("%d\n", r);
    }

    return 0;
}