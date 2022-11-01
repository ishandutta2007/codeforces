#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)

ll n,a[N];
ld ans[3];
map <ll,bool> mp;

bool check(ld x)
{
    ll i=0;
    ans[0]=(ld)a[0]+x;
    while(a[i]<=a[0]+(ll)(2*x) && i<n)i++;
    ll now=a[i];
    ans[1]=(ld)now+x;
    while(a[i]<=now+(ll)(2*x) && i<n)i++;
    now=a[i];
    ans[2]=(ld)now+x;
    while(a[i]<=now+(ll)(2*x) && i<n)i++;
    return i>=n;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {    
        cin>>a[i];
        if(mp[a[i]]==1)
            n--,i--;
        else 
            mp[a[i]]=1;    
    }
    sort(a,a+n);
    if(n<4)
        return cout<<0<<"\n"<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n",0;
    ld l=-1,r=1e9;
    for(int i=0;i<100;i++)
    {
        ld mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(10)<<r<<"\n"<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
    return 0;
}