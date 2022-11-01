#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> res;

void solve(ll cnt,ll m,ll x)
{
    if(cnt==1)
    {
        res.push_back((n-m)-x);
        return;
    }
    ll l=x-1,r=2*x+1;
    while(l<r-2)
    {
        ll mid=(l+r)/2;
        ll xx=mid;
        ll mm=m+xx;
        if(mm+(cnt-1)*xx>n) r=mid;
        else if(n>mm+((1ll<<(cnt))-2)*xx) l=mid;
        else r=mid+1;
    }
    ll mid=r-1;
    res.push_back(mid-x);
    solve(cnt-1,m+mid,mid);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(ll i=1;;i++)
        {
            if(1+((1ll)<<(i+1))-2>=n)
            {
                printf("%I64d\n",i);
                solve(i,1,1);
                break;
            }
        }
        for(ll y:res) printf("%I64d ",y);
        printf("\n");
        res.clear();
    }
    return 0;
}