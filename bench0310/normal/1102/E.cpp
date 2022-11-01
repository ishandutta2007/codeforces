#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mod=998244353;
    int n;
    scanf("%d",&n);
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]=i;
    }
    int b=1;
    int idx=m[a[0]];
    for(int i=1;i<n;i++)
    {
        if(i>idx)
        {
            b<<=1;
            if(b>=mod) b%=mod;
        }
        idx=max(idx,m[a[i]]);
    }
    printf("%d\n",b);
    return 0;
}