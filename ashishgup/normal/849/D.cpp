#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int off=1e5;

int n, w, h;
vector<pair<int, pair<int, int> > > g[N];
pair<int, int> ans[N];

int32_t main()
{
    IOS;
    cin>>n>>w>>h;
    for(int i=1;i<=n;i++)
    {
        int type, p, t;
        cin>>type>>p>>t;
        g[p-t+off].push_back({type, {p, i}});
    }
    for(auto it:g)
    {
        vector<pair<int, int> > x, y;
        for(auto j:it)
        {
            if(j.first==1)
                x.push_back(j.second);
            else
                y.push_back(j.second);
        }
        if(x.size())
            sort(x.begin(), x.end());
        if(y.size())
            sort(y.begin(), y.end());
        vector<pair<int, int> > endx, endy;
        for(auto it:x)
            endx.push_back({it.first, h});
        for(auto it:y)
            endy.push_back({w, it.first});
        int szx=endx.size(), szy=endy.size();
        if(endx.size()>=endy.size())
        { 
            int idx=0;
            for(int i=szy-1;i>=0;i--)
            {
                ans[y[i].second]=endx[idx++];
            }
            int rem=szx - idx;
            for(int i=0;i<rem;i++)
            {
                ans[x[i].second]=endx[idx++];
            }
            idx=0;
            for(int i=szx-1;i>=rem;i--)
            {
                ans[x[i].second]=endy[idx++];
            }
        }
        else
        {
            int idx=0;
            for(int i=szx-1;i>=0;i--)
            {
                ans[x[i].second]=endy[idx++];
            }
            int rem=szy - idx;
            for(int i=0;i<rem;i++)
            {
                ans[y[i].second]=endy[idx++];
            }
            idx=0;
            for(int i=szy-1;i>=rem;i--)
            {
                ans[y[i].second]=endx[idx++];
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}