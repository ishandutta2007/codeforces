#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n,m,a,b;
map <pair<ll,ll>,bool> mp;
string s;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>a>>b>>s;
    mp[{a,b}]=1;
    cout<<1<<" ";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='U')a=max(1ll,a-1);
        if(s[i]=='D')a=min(n,a+1);
        if(s[i]=='L')b=max(1ll,b-1);
        if(s[i]=='R')b=min(m,b+1);
        if(i==s.size()-1)
        {
            ll ans=n*m;
            for(map <pair<ll,ll>,bool>::iterator it=mp.begin();it!=mp.end();it++)
                if(it->second==1)
                    ans--;
            cout<<ans<<" "; 
        }
        else
        {
            if(mp[{a,b}]==1)cout<<0<<" ";
            else mp[{a,b}]=1,cout<<1<<" ";
        }
    }
    return 0;
}