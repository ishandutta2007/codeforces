#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int m;

int count(int last)
{
    int cnt=0;
    for(int i=2;;i++)
    {
        int cur=1;
        for(int j=2;j<=4;j++)
        {
            cur*=i;
            if(cur>last)
                break;
        }  
        if(cur>last)
            break;
        cnt+=last/cur;
    }
    return cnt;
}

int check(int last)
{
    return (count(last)>=m);
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
    if(count(lo)==m)
        return lo;
    return -1;
}
int32_t main()
{
    IOS;
    cin>>m;
    int ans=binsearch(1, 1e18);
    cout<<ans;
    return 0;
}