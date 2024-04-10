#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
ll n,m,a[N],b[N];

bool check(ll x)
{
    for(int i=0;i<n;i++)b[i]=a[i];
    int j=0;
    for(int i=0;i<m && j<n;i++)
    {
        ll x2=x-j;
        while(x2)
        {
            x2--;
            if(x2>=b[j])
            {
                x2-=b[j++];
                if(j==n)
                    return 1;
                continue;
            }
            b[j]-=x2;
            break;
        }
    }
    while(b[j]==0 && j<n)j++;
    //cout<<j<<endl;
    if(j==n)return 1;
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    ll l=-1,r=1e18;
    //cout<<check(3)<<endl;
    
    while(l<r-1)
    {
        ll mid=l+r>>1;
        //cout<<check(mid)<<endl;
        if(check(mid))
            r=mid;
        else
            l=mid;      
    }   
    cout<<r;
    
    
    return 0;
}