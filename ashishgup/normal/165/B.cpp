#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;

int check(int v)
{
    int sum=0, curk=1;
    while(v>=curk)
    {
        sum+=v/curk;
        curk*=k;
    }
    return sum>=n;
}

int binsearch(int lo, int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(check(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    int ans=binsearch(0, 1e18);
    cout<<ans;    
    return 0;
}