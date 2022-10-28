#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int a[N], ans[N];
set<int> active;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        active.insert(i);
    }
    cin>>m;
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int p, x;
            cin>>p>>x;
            auto it=active.lower_bound(p);
            if(it!=active.end())
            {
                int idx=*it;
                ans[idx]+=x;
                int diff=0;
                while(idx<=n && ans[idx]>=a[idx])
                {   
                    diff=ans[idx]-a[idx];
                    ans[idx+1]+=diff;
                    ans[idx]=a[idx];
                    active.erase(idx);
                    idx++;
                }
            }
        }
        else
        {
            int k;
            cin>>k;
            cout<<ans[k]<<endl;
        }
    }
    return 0;   
}