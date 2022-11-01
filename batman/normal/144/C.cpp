#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define K (30)
#define N (101*1000)
#define INF ((ll)1e9)

ll nump[K],nums[N][K],q[N],ans;
string s,p;

bool check(ll x,ll y)
{
    
    ll need=0;
    for(int i=0;i<K;i++)
        if(nums[x][i]-((y)?nums[y-1][i]:0ll)<nump[i])
            need+=nump[i]-(nums[x][i]-((y)?nums[y-1][i]:0ll));
    return need<=q[x]-((y)?q[y-1]:0ll);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>p;
    for(int i=0;i<p.size();i++)
        nump[p[i]-'a']++;
    for(int i=0;i<s.size();i++)
    {
        if(i)
        {
            for(int j=0;j<K;j++)
                nums[i][j]=nums[i-1][j];
            q[i]=q[i-1];        
        }
        if(s[i]=='?')q[i]++;
        else nums[i][s[i]-'a']++;
    }
        
    for(int i=(ll)p.size()-1;i<s.size();i++)
    {
        ll l=-1,r=i+1;
        while(l<r-1)
        {
            ll mid=(l+r)/2;
            if(check(i,mid))l=mid;
            else r=mid;
        }
        if(i-l+1<=(ll)p.size())ans++;
    }
    cout<<ans;
    return 0;
}