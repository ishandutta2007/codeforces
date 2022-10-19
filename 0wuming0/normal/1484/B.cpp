#include"bits/stdc++.h"
using namespace std;
int a[100006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        if(n<=2)cout<<0<<endl;
        else if(2*a[1]==a[0]+a[2])
        {
            int c=a[2]-a[1];
            int now=a[1];
            int mod;
            for(int i=2;i<n;now+=c,i++)
            {
                if(a[i]!=now+c)
                {
                    mod=a[i]-(now+c);
                    if(mod<0)mod=-mod;
                    break;
                }
                if(i==n-1)
                {
                    cout<<0<<endl;
                    goto ne;
                }
            }
            if(c<0)c+=mod;
            for(int i=1;i<n;i++)
            {
                if((a[i-1]+(long long)c)%mod!=a[i])
                {
                    cout<<-1<<endl;
                    goto ne;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(a[i]>=mod)
                {
                    cout<<-1<<endl;
                    goto ne;
                }
            }
            cout<<mod<<" "<<c<<endl;
        }
        else
        {
            int mod=2*a[1]-a[0]-a[2];
            if(mod<0)mod=-mod;
            int c=a[1]-a[0];
            if(c<0)c+=mod;
            for(int i=1;i<n;i++)
            {
                if((a[i-1]+(long long)c)%mod!=a[i])
                {
                    cout<<-1<<endl;
                    goto ne;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(a[i]>=mod)
                {
                    cout<<-1<<endl;
                    goto ne;
                }
            }
            cout<<mod<<" "<<c<<endl;
        }
        ne:;
    }
    return 0;
}