#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;
#define int long long
map<int,int> used;

int a,b;

void dfs(int x,map<int,vector<int>> &G,deque<int> &ret)
{
    used[x]=1;
    for(auto it:G[x])
        if(!used[it])
            dfs(it,G,ret);
    ret.push_back(x);
    if(x+x==a || x+x==b)
        ret.push_back(x);
}

main()
 {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>a>>b;
    vector<int> t(n);
    map<int,int> ex;
    map<int,int> ind;
    for(int i=0;i<n;i++) cin>>t[i],ex[t[i]]=1,ind[t[i]]=i;

    map<int,vector<int>> G;
    for(int i=0;i<n;i++)
    {
        if(2*t[i]!=a && ex[a-t[i]])
            G[t[i]].push_back(a-t[i]);
        if(2*t[i]!=b && a!=b && ex[b-t[i]])
            G[t[i]].push_back(b-t[i]);
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        if(used[t[i]] || G[t[i]].size()==2) continue;
        deque<int> tmp;
        dfs(t[i],G,tmp);
        if(tmp.size()%2)
        {
            if(tmp.size()>1)
            {
                if(tmp[0]==tmp[1])
                {
                    tmp.pop_front();
                    goto OK;
                }
                if(tmp[tmp.size()-2]==tmp[tmp.size()-1])
                {
                    tmp.pop_back();
                    goto OK;
                }
            }
            cout<<"NO"<<endl;
            return 0;
        }
        OK:
        int T=(tmp[1]+tmp[0])==b;
        for(int i=0;i<tmp.size();i++)
            ans[ind[tmp[i]]]=T;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
 }