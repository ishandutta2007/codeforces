#include"bits/stdc++.h"
using namespace std;
int a[100005],b[100005],an,bn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        an=0;
        bn=0;
        for(int i=0;i<2*n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==0)a[an++]=abs(y);
            else b[bn++]=abs(x);
        }
        sort(a,a+an);
        sort(b,b+an);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=sqrt(a[i]*(double)a[i]+b[i]*(double)b[i]);
        }
        printf("%.15lf\n",ans);
    }
    return 0;
}