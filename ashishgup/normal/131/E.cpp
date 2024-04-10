#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int x[N], y[N], cnt[N], ans[N];
map<int, vector<pair<int, int> > > xcoord, ycoord, diag1, diag2;

void work(map<int, vector<pair<int, int> > > &cur)
{
    for(auto &it:cur)
    {
        int sz=it.second.size();
        sort(it.second.begin(), it.second.end());
        for(int j=0;j<sz-1;j++)
        {
            cnt[it.second[j].second]++;
            cnt[it.second[j+1].second]++;
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        xcoord[x[i]].push_back({y[i], i});
        ycoord[y[i]].push_back({x[i], i});
        diag1[x[i]-y[i]].push_back({x[i]+y[i], i});
        diag2[x[i]+y[i]].push_back({x[i]-y[i], i});
    }
    work(xcoord);
    work(ycoord);
    work(diag1);
    work(diag2);
    for(int i=1;i<=m;i++)
        ans[cnt[i]]++;
    for(int i=0;i<=8;i++)
        cout<<ans[i]<<" ";
    return 0;
}