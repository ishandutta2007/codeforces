#include"bits/stdc++.h"
using namespace std;
#define ll long long
set<pair<int,int> >st;
vector<int>v[300005];
bool check(int a,int b)
{
    if(a==b)return 0;
    if(a<b)swap(a,b);
    if(st.find(pair<int,int>(a,b))==st.end())return 1;
    else return 0;
}
int stk[300005],nn;
ll solve(int a,int b)
{
    nn=0;
    stk[nn++]=0;
    multiset<pair<int,int> >mp;
    mp.insert(pair<int,int>(v[a][0]+v[b][0],0));
    while(mp.size())
    {
        auto it=mp.end();
        it--;
        int now=it->second;
        if(check(v[a][now],v[b][stk[now]]))return it->first;
        stk[now]++;
        mp.erase(it);
        if(stk[now]<v[b].size())
        {
            mp.insert(pair<int,int>(v[a][now]+v[b][stk[now]],now));
        }
        if(nn<v[a].size())
        {
            stk[nn++]=0;
            mp.insert(pair<int,int>(v[a][nn-1]+v[b][0],nn-1));
        }
    }
    return 0;
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)v[i].clear();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            mp[a]++;
        }
        for(auto pr:mp)
        {
            v[pr.second].push_back(pr.first);
        }
        vector<int>save;
        for(int i=0;i<=n;i++)if(v[i].size())save.push_back(i);
        for(auto i:save)sort(v[i].begin(),v[i].end(),cmp);
        st.clear();
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a<b)swap(a,b);
            st.insert(pair<int,int>(a,b));
        }
        ll ans=0;
        for(int i=0;i<save.size();i++)for(int j=i;j<save.size();j++)
        {
            //cout<<"<<<"<<i<<" "<<j<<" "<<save[i]<<" "<<save[j]<<" "<<solve(save[i],save[j])<<endl;
            ans=max(solve(save[i],save[j])*(save[i]+save[j]),ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
10000
7 0
1 1 1 1 2 2 3

6 1
1 1 1 2 2 3
1 3

7 2
1 1 1 1 2 2 3
2 3
1 3
*/