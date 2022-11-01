#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (301*1000)
#define ll long long
#define ld long double
#define PI ((ld)3.141592)
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n;
pair <ld,ll> a[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        /*if(x==0)
        {
            a[i].first=(ld)0;
            a[i].second=i+1;
            continue;
        }*/
        
        a[i].first=(ld)atan2((ld)x,(ld)y)*180/PI;
        if(a[i].first<0)a[i].first+=(ld)360;
        a[i].second=i+1;
        //cout<<a[i].first<<endl;
    }
    sort(a,a+n);
    
    ld mini=(ld)INF,ans1,ans2;
    for(int i=0;i<n-1;i++)
        if((ld)a[i+1].first-a[i].first<mini)
            mini=(ld)a[i+1].first-a[i].first,ans1=a[i].second,ans2=a[i+1].second;
    ld ex=(ld)360-a[n-1].first;
    if(ex+(ld)a[0].first<mini)
        return cout<<a[n-1].second<<" "<<a[0].second,0;
    cout<<ans1<<" "<<ans2;              
    return 0;
}