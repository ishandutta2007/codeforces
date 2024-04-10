#include <bits/stdc++.h>
using namespace std;
#define N (1001*1000)

int n,k,num[N],a,mini=1e9;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        mini=min(a,mini);
        num[max(1,a-k)]++;num[a+1]--;
    }
    for(int i=1;i<N;i++)num[i]+=num[i-1];
    for(int i=1;i<=mini;i++)
    {
        int sum=0;
        for(int j=i;j<N;j+=i)
            sum+=num[j];
        if(sum>=n)a=i; 
    }
    printf("%d",a);
    return 0;
}