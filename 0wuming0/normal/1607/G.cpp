#include"bits/stdc++.h"
using namespace std;
int a[200005],b[200005];
int na[200005],nb[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
        for(int i=0;i<n;i++)
        {
            na[i]=min(m,a[i]);
            nb[i]=m-na[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i]-b[i]-na[i]+nb[i];
        }
        if(ans<0)
        {
            for(int i=0;i<n;i++)
            {
                int bb=min(m,b[i]);
                int aa=m-bb;
                if(ans+na[i]-nb[i]-aa+bb<0)
                {
                    ans=ans+na[i]-nb[i]-aa+bb;
                    na[i]=aa;
                    nb[i]=bb;
                }
                else
                {
                    if(ans%2==0)
                    {
                        na[i]+=ans/2;
                        nb[i]-=ans/2;
                        ans=0;
                    }
                    else
                    {
                        ans++;
                        na[i]+=ans/2;
                        nb[i]-=ans/2;
                        ans=-1;
                    }
                    break;
                }
            }
        }
        cout<<abs(ans)<<endl;
        for(int i=0;i<n;i++)printf("%d %d\n",na[i],nb[i]);
    }
    return 0;
}