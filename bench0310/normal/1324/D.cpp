#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v[i]+=a;
    }
    for(int i=0;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        v[i]-=b;
    }
    sort(v.begin(),v.end());
    long long res=0;
    for(int i=0;i<n;i++)
    {
        int x=-v[i]+1;
        int l=-1,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(v[m]>=x) r=m;
            else l=m;
        }
        if(r<=i) res--;
        res+=(n-r);
    }
    printf("%I64d\n",res/2);
    return 0;
}