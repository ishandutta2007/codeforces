#include"bits/stdc++.h"
using namespace std;
int ans[2005];
int now[2005];
int vis[2005];
int pr[2005];
int save[2005];
vector<int>v[2005];
vector<int>vsum[2005];
bool cmp(int x,int y)
{
    return ans[x]<ans[y];
}
int cc;
int solve(int i)
{
    for(auto j:v[i])
    {
        vsum[i].push_back(j);
        for(auto k:vsum[j])vsum[i].push_back(k);
    }
    if(now[i]>vsum[i].size())
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    cc-=10000;
    sort(vsum[i].begin(),vsum[i].end(),cmp);//cout<<">>"<<now[i]<<endl;
    if(vsum[i].size()==0)
    {
        ans[i]=cc;
    }
    else if(now[i]==0)
    {
        ans[i]=ans[vsum[i][0]]-2;
    }
    else
    {
        for(auto j:vsum[i])
        {
            ans[j]-=2;
            now[i]--;
            if(now[i]==0)
            {
                ans[i]=ans[j]+1;
                break;
            }
        }
    }
    //cout<<"<<<<"<<i<<" "<<ans[i]<<endl;
    vis[pr[i]]--;
    save[i]=1;
    if(vis[pr[i]]==0&&pr[i]!=0&&save[pr[i]]!=1)solve(pr[i]);
    //return nu;
}
int main()
{
    cc=1e9-7;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(i);
        now[i]+=b;
        //now[a]-=b;
        pr[i]=a;
        vis[a]++;
    }
    vis[0]=0;
    for(int i=1;i<=n;i++)if(vis[i]==0&&save[i]!=1)
    {
        //ans[i]=4000;
        solve(i);
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}
/*
3
0 2
1 1
2 0

10
0 9
1 8
2 7
3 6
4 5
5 4
6 3
7 2
8 1
9 0

10
0 0
1 0
1 0
1 0
1 0
1 0
1 0
1 0
1 0
1 0
*/