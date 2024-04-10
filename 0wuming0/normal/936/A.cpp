#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    ll k,d,t;
    cin>>k>>d>>t;
    if(k%d==0)printf("%lld.0\n",t);
    else
    {
        ll c=d-k%d;
        t*=2;
        ll ans=k*2+c;
        ll num=t/ans;
        t%=ans;
        //num*(k+c)
        ll sum=num*(k+c)*2;//cout<<ans<<" "<<k<<endl;
        if(t<=k*2)sum+=t;
        else
        {
            t-=k*2;
            sum+=k*2;
            sum+=t*2;
        }
        printf("%lld",sum/2);
        if(sum%2)printf(".5\n");
        else printf(".0\n");
    }
    return 0;
}