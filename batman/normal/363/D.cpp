#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define ll long long
ll n,m,a,b[N],p[N];

int main()
{
    cin>>n>>m>>a;
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<m;i++)cin>>p[i];
    sort(b,b+n);
    sort(p,p+m);
    ll l=0,r=min(n,m)+1;
    while(l<r-1)
    {
        ll mid=l+r>>1,need=0;
        
        for(int i=n-mid,j=0;j<mid;j++,i++)
            need+=max(0ll,p[j]-b[i]);
        if(need>a)
            r=mid;
        else
            l=mid;      
    } 
    cout<<l<<" ";
    ll all=0;
    for(int i=0;i<l;i++)
        all+=p[i];
    cout<<max(0ll,all-a);   
    return 0;
}