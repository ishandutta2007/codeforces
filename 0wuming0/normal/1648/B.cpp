#include"bits/stdc++.h"
using namespace std;
bool a[1000005];
int sum[1000005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        for(int i=0;i<=c;i++)a[i]=0;
        while(n--)
        {
            int k;
            scanf("%d",&k);
            a[k]=1;
        }
        bool flag=1;
        for(int i=1;i<=c;i++)sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=c;i++)if(a[i]==0)
        {
            for(int j=1;i*j<=c;j++)if(a[j])
            {
                int l=i*j;
                int r=(i+1)*j-1;
                if(l>c)break;
                if(r>c)r=c;
                if(sum[r]-sum[l-1])flag=0;
            }
        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}