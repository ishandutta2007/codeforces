#include <stdio.h>

long long arr[100000];
long long cnt[100000];
long long mem[100];

int main()
{
    int n,i,j;
    long long r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%I64d",&arr[i]);
    for(i=0;i<n;i++)
    {
        while(arr[i])
        {
            if(arr[i]&1)
                cnt[i]++;
            arr[i]>>=1;
        }
        mem[cnt[i]]++;
    }
    for(i=0;i<100;i++)
        r+=mem[i]*(mem[i]-1)/2;
    printf("%I64d",r);
    return 0;
}