#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], v[N], t[N], ans[N];

int check(int off, int ind, int val)
{
    int store=t[ind]-t[off-1];
    return (store>=val);
}

int binsearch(int start, int hi, int val)
{
    int store=start;
    int lo=start-1;
    while(lo<hi)
    {
        int mid=(lo+hi+1)>>1;
        if(check(store, mid, val))
            hi=mid-1;
        else
            lo=mid;
    }
    return lo;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        t[i]+=t[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int l=i;
        int r=binsearch(i, n, v[i]);
        a[l]+=1;
        a[r+1]-=1;
        ans[r+1]+=(v[i] - (t[r] - t[l-1]));
    }
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
    {
        ans[i] += (a[i] * (t[i] - t[i-1]));
        cout<<ans[i]<<" ";
    }
    return 0;
}