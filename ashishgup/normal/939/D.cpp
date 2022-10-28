#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int vis[N];
string a, b;
vector<int> g[N];
set<int> curset;

void dfs(int k)
{
    if(vis[k])
        return;
    vis[k]=1;
    curset.insert(k);
    for(auto it:g[k])
        dfs(it);
}

int32_t main()
{
    IOS;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<pair<char, char> > ans;
    for(char ch='a';ch<='z';ch++)
    {
        int cur=ch;
        if(!vis[cur])
        {
            curset.clear();
            dfs(cur);
            vector<int> temp;
            for(auto it:curset)
                temp.push_back(it);
            for(int i=0;i<temp.size()-1;i++)
            {
                char ch1=(char)temp[i];
                char ch2=(char)temp[i+1];
                ans.push_back({ch1, ch2});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}