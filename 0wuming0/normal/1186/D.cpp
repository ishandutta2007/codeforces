#include"bits/stdc++.h"
using namespace std;
#define ll long long
double a[100005];
ll b[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",a+i);
        a[i]=a[i]+100000;
    }
    ll ans=0,num=0;
    for(int i=0;i<n;i++)ans+=(b[i]=(ll)a[i]);
    num=n*100000ll-ans;//cout<<num<<endl;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=a[i]&&num>0)
        {
            num--;
            b[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld\n",b[i]-100000);
    }
    return 0;
}