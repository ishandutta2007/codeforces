#include"bits/stdc++.h"
using namespace std;
int a[100005];
int pos[100005],nn;
int p;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
        if(a[i])
        {
            pos[nn]=i;
            nn++;
        }
    }
    if(sum==1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        long long ans0=1e18;
        for(p=2;p<=sum;p++)
        {
            if(sum%p==0)
            {
                long long ans=0;
                for(int i=0;i!=sum;i+=p)
                {//cout<<"ok"<<endl;
                    int l=i;
                    int r=l+p-1;
                    int m=(l+r)/2;
                    for(int j=l;j<=r;j++)
                    {
                        ans=ans+abs(pos[j]-pos[m]);
                    }
                }
                ans0=min(ans0,ans);//break;
            }
        }
        cout<<ans0<<endl;
    }
    return 0;
}
/*
8
1 1 1 0 0 1 1 1
*/