#include"bits/stdc++.h"
using namespace std;
vector<int>v[100005];
vector<char>ans[100005];
map<int,pair<int,int> >mp;
map<pair<int,int>,pair<int,int> >save;
int now[100005];
void solve(int i,int j,int op)
{
    auto pr=save[make_pair(i,j)];
    ans[i][j]='L';
    ans[pr.first][pr.second]='R';
    if(op==-1)
    {
        if(i==pr.first)return;
        op=i;
    }
    else
    {
        if(op==pr.first)return;
    }
    i=pr.first;
    for(;now[i]<v[i].size();now[i]++)
    {
        if(ans[i][now[i]]=='?')
        {
            solve(i,now[i],op);
            return;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m,a;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a);
            v[i].push_back(a);
            auto it=mp.find(a);
            if(it==mp.end())mp[a]=make_pair(i,j);
            else
            {
                save[it->second]=make_pair(i,j);
                save[make_pair(i,j)]=it->second;
                mp.erase(it);
            }
            ans[i].push_back('?');
        }
    }
    if(mp.size())
    {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(;now[i]<v[i].size();now[i]++)
        {
            if(ans[i][now[i]]=='?')
            {
                solve(i,now[i],0);
            }
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        for(auto c:ans[i])putchar(c);
        putchar(10);
    }
    return 0;
}