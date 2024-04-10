#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define K (30)
#define N (1010)
#define INF ((ll)1e9)

ll n,x,y,x2,y2,ans;
pair <pair<ll,ll>,ll> a[N];

ld dis(ll a1,ll b1,ll a2,ll b2)
{
    return sqrt((ld)(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x>>y>>x2>>y2>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
    if(x>x2)swap(x,x2);
    if(y>y2)swap(y,y2); 
    for(int i=y;i<=y2;i++)
    {
        bool p1=1,p2=1;
        for(int j=0;j<n;j++)
        {
            if(dis(x,i,a[j].first.first,a[j].first.second)<=(ld)a[j].second)p1=0;
            if(dis(x2,i,a[j].first.first,a[j].first.second)<=(ld)a[j].second)p2=0;  
        }
        ans+=p1+p2;
    }
    for(int i=x+1;i<x2;i++)
    {
        bool p1=1,p2=1;
        for(int j=0;j<n;j++)
        {
            if(dis(i,y,a[j].first.first,a[j].first.second)<=(ld)a[j].second)p1=0;
            if(dis(i,y2,a[j].first.first,a[j].first.second)<=(ld)a[j].second)p2=0;  
        }
        
        ans+=p1+p2;
    }
    cout<<ans;
    return 0;
}