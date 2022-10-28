#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2010;
const int off=1005;

int n;
pair<int, int> a[N];
vector<pair<int, int> > x[N], y[N];
set<int> valid;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        valid.insert(i);
        cin>>a[i].first>>a[i].second;
        x[a[i].first+off].push_back({a[i].second, i});
        y[a[i].second+off].push_back({a[i].first, i});
    }
    int ans=0;
    for(auto &it:x)
    {
        if(it.size())
        {
            sort(it.begin(), it.end());
            if(valid.find(it[0].second)!=valid.end())
                valid.erase(it[0].second);
            if(valid.find(it.back().second)!=valid.end())
                valid.erase(it.back().second);
        }
    }
     for(auto &it:y)
    {
        if(it.size())
        {
            sort(it.begin(), it.end());
            if(valid.find(it[0].second)!=valid.end())
                valid.erase(it[0].second);
            if(valid.find(it.back().second)!=valid.end())
                valid.erase(it.back().second);
        }
    }
    cout<<valid.size();
    return 0;
}