#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,l,r,p,q,a[N],lft[N],ans=(ll)1e15;

int main()
{
    cin>>n>>l>>r>>p>>q;
    for(ll i=0;i<n;i++)
        cin>>a[i],lft[i]=((i)?lft[i-1]:0ll)+a[i];
    for(ll i=n,right=0;i>=0;i--)
        right+=a[i],ans=min(ans,right*r+((i)?lft[i-1]:0ll)*l+max(0ll,abs(i-(n-i))-1)*((i>n-i)?p:q));
    cout<<ans;
    return 0;
}