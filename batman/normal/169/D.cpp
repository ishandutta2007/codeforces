#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define ld long double

ll n,k,h;
pair <ll,pair<ll,ll> > a[N];
ll ans[N],ans2[N];

bool check(ld t)
{
     ll p=0;
     for(int i=0;i<n && p!=k;i++)
     {       
             //cout<<(p+1)*h<<" "<<a[i].second.second*t<<"\n";
             if((p+1)*h<=a[i].second.first*t)
                 ans[p++]=a[i].second.second;   
     }
     //cout<<p<<endl;
     if(p==k)
     {
             for(int i=0;i<k;i++)ans2[i]=ans[i];
             return 1;
     }
     return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>h;
    for(int i=0;i<n;i++)cin>>a[i].first;
    for(int i=0;i<n;i++)cin>>a[i].second.first,a[i].second.second=i+1;
    sort(a,a+n);
    
    ld l=0,r=(ld)1e12;
    for(int i=0;i<200;i++)
    {
            ld mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid;
    }           
    //cout<<r<<endl;
    for(int i=0;i<k;i++)cout<<ans2[i]<<" ";
    cout<<endl;
    return 0;
}