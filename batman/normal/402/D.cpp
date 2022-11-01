#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (5100)
#define INF ((ll)1e9)

int n,m;
ll a[N],b[N],gcd[N];
set <ll> s;

int score(ll x)
{
    int ans=0;
    for(ll j=2;j*j<=x;j++)
        while(x%j==0)
            x/=j,ans+=((s.find(j)!=s.end())?-1:1); 
    if(x>1)
       ans+=((s.find(x)!=s.end())?-1:1);
    return ans;     
}

int main()
{
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]),s.insert(b[i]);
    for(int i=0;i<n;i++)gcd[i]=((i)?__gcd(gcd[i-1],a[i]):a[i]);
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=score(a[i]);
    ll last=1;
    for(int i=n-1;i>=0;i--)
    {
        ll ex=score(gcd[i]/last);
        if(ex<0)
            last=gcd[i],ans-=ex*(i+1);
    }
    
    printf("%d",ans);
    return 0;
}