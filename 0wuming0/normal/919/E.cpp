#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define P (p-1)
ll a,b,p,x;
ll dev[1000009];
int main()
{
    cin>>a>>b>>p>>x;
    dev[1]=b;
    for(int i=2;i<p;i++)dev[i]=(p-p/i)*dev[p%i]%p;
    ll mod=p*P,sum=(x-1)/mod*P,now=1,t=P*P;
    x=(x-1)%mod+1;
    for(int i=1;i<p;i++)
    {
        now=now*a%p;
        if((t*dev[now]+i*p)%mod<=x)sum++;
    }
    cout<<sum<<endl;
    return 0;
}