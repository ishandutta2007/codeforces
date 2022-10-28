#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];

int check(int cur)
{
    int moves=0;
    for(int i=1;i<=n;i++)
        moves+=min(a[i], cur);
    if(moves<=k)
        return 1;
    return 0;
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
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<k)
    {
        cout<<"-1";
        return 0;
    }
    int turn=binsearch(0, 1e9+1);
    int done=0;
    for(int i=1;i<=n;i++)
    {
        done+=min(turn, a[i]);
        a[i]=max(0LL, a[i]-turn);
    }
    k-=done;
    vector<int> start, end;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            if(k>0)
            {
                k--;
                if(a[i]>1)
                    end.push_back(i);
            }
            else
            {
                start.push_back(i);
            }
        }
    }
    for(auto it:start)
        cout<<it<<" ";
    for(auto it:end)
        cout<<it<<" ";
    return 0;
}