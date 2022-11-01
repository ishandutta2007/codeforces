#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=((ll)1e9+7);
ll n,k,ans,all;
string s;

ll tavan(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1)
            ans=ans*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return ans;
}

int main()
{
    cin>>s>>k;
    ll ex=(tavan(2,k*s.size())-1+MOD)%MOD;
    ll ex2=(tavan(2,s.size())-1+MOD)%MOD;
    ex2=tavan(ex2,MOD-2);   
    //cout<<ex<<" "<<ex2<<"\n";
    for(int i=0;i<s.size();i++)
        if(s[i]=='0' || s[i]=='5')
            ans+=tavan(2,i)*ex%MOD*ex2%MOD,ans%=MOD;
    cout<<ans;      
    return 0;
}