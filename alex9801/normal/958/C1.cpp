#include<bits/stdc++.h>
using namespace std;

int arr[100010];
int sum[100010];

int main()
{
    int n, p, i;
    scanf("%d%d", &n, &p);
    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);
        
    for(i=1;i<=n;i++)
        sum[i] = (sum[i-1] + arr[i]) % p;
    
    int res = 0;
    for(i=1;i<n;i++)
        res = max(res, sum[i] + ((sum[n] - sum[i]) % p + p) %p);
    
    printf("%d\n", res);
    return 0;
}