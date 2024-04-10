#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (101*1000)

ll n,m,a[N],b,ans=1,cnt;
map <ll,ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        mp[b]++;
        if(b==a[i])
            cnt++;
    }
    cin>>m;
    for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
    {
        for(int i=1;i<=it->second;i++)
        {
            ll ex=i;
            while(ex%2==0 && cnt)ex/=2,cnt--;
            ans*=ex;
            ans%=m;
        }   
    }
        
    cout<<ans;      
    
    return 0;
}