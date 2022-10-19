#include"bits/stdc++.h"
using namespace std;
#define ll long long
int sum;
ll mod=1e9+7;
ll _2[200005];
ll a[200005];
ll save[200005],nn;
int main()
{
    vector<ll>zzz;
    _2[0]=1;
    for(int i=1;i<200005;i++)_2[i]=_2[i-1]*2%mod;
    int t;
    cin>>t;
    while(t--)
    {
        map<ll , ll>mp;
        int n;
        cin>>n;
        a[0]=0;
        ll cg=0;
        ll ans=1;
        mp[0]=1;
        for(int i=1;i<=n;i++)scanf("%lld",a+i);//*/
        for(int i=1;i<=n;i++)
        {
            ll num;
            if(mp.find(-cg)==mp.end())
            {
                num=ans;
                mp[-cg]=num;
            }
            else
            {
                num=ans-mp.find(-cg)->second;
                num%=mod;
                if(num<0)num+=mod;
                mp.find(-cg)->second+=num;
            }
            ans+=num;
            ans%=mod;
            cg+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}