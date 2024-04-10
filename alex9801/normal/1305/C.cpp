#include <bits/stdc++.h>
using namespace std;

int arr[200010];
bool chk[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        int t = arr[i] % m;
        if(chk[t])
        {
            puts("0");
            return 0;
        }
        chk[t] = 1;
    }
    assert(n <= 1010);

    int r = 1;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            r = 1LL * r * abs(arr[i] - arr[j]) % m;

    printf("%d\n", r);
    return 0;
}