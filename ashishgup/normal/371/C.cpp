#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int nb, ns, nc, pb, ps, pc, r, reqdb, reqds, reqdc;
string s;

int check(int k)
{
    int b=max(0LL, k*reqdb-nb);
    int s=max(0LL, k*reqds-ns);
    int c=max(0LL, k*reqdc-nc);
    int reqd=b*pb + s*ps + c*pc;
    return reqd<=r;
}

int binsearch(int lo, int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi+1)>>1;
        if(check(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int32_t main()
{
    IOS;
    cin>>s;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
    for(auto it:s)
    {
        if(it=='B')
            reqdb++;
        if(it=='S')
            reqds++;
        if(it=='C')
            reqdc++;
    }
    int ans=binsearch(0, 1e15);
    cout<<ans;
    return 0;   
}