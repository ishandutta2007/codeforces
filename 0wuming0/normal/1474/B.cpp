#include"bits/stdc++.h"
using namespace std;
#define nnn 1000005
int prime[nnn];
int p[nnn],nn;
int main()
{
    for(int i=2;i<nnn;i++)
    {
        if(!prime[i])
        {
            for(int j=2;i*j<nnn;j++)prime[i*j]=i;
        }
    }
    for(int i=2;i<nnn;i++)
        if(!prime[i])
    {
        p[nn]=i;
        nn++;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        int i=0;
        int ans1,ans2;
        for(;;i++)
        {
            if(p[i]>=1+d)break;
        }
        ans1=p[i];
        for(;;i++)
        {
            if(p[i]>=ans1+d)break;
        }
        ans2=p[i];//cout<<ans1<<endl<<ans2<<endl;
        cout<<ans1*(long long)ans2<<endl;
    }
    return 0;
}