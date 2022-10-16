#include <bits/stdc++.h>

using namespace std;


int main()
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    long long k,sum=0;
    scanf("%d%I64d",&n,&k);
    int i=0;
    while(sum+i<=k && i<n)
    {
        sum+=i;
        i++;
    }
    if(sum==k)
    {
        for(int j=1;j<=i;j++) printf("(");
        for(int j=1;j<=i;j++) printf(")");
        for(int j=i+1;j<=n;j++) printf("()");
    }
    else if(i<n)
    {
        for(int j=1;j<=k-sum;j++) printf("(");
        printf("()");
        for(int j=k-sum+1;j<=i;j++) printf("(");
        for(int j=1;j<=i;j++) printf(")");
        for(int j=i+2;j<=n;j++) printf("()");
    }
    else printf("Impossible");
    return 0;
}