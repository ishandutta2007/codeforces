#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,x[4],y[4];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    if(n==1)
        return cout<<-1,0;
    if(n==2)
    {
        if(x[0]==x[1] || y[0]==y[1])
            return cout<<-1,0;
        return cout<<abs(x[0]-x[1])*abs(y[0]-y[1]),0;       
    }   
    if(n==3 || n==4)
    {
        ll a,b;
        if(x[0]==x[1])
            b=abs(y[0]-y[1]);
        if(x[0]==x[2])
            b=abs(y[0]-y[2]);
        if(x[2]==x[1])
            b=abs(y[2]-y[1]);
        if(y[0]==y[1])
            return cout<<abs(x[1]-x[0])*b,0;
        if(y[2]==y[1])
            return cout<<abs(x[1]-x[2])*b,0;
        if(y[0]==y[2])
            return cout<<abs(x[2]-x[0])*b,0;            
    }
    return 0;
}