#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

double dist(pair<int,int> a,pair<int,int> b)
{
    if(a.first<0 || b.first<0 || a.second<0 || b.second<0) return -1e7;
    return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)  );
}

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    pair<int,int> x[12]={{0,0},{1,0},{0,1},{n,0},{n,1},{n-1,0},{0,m},{1,m},{0,m-1},{n,m},{n-1,m},{n,m-1}};
    pair<int,int> ans[4];
    double cur=0;
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
            for(int k=0;k<12;k++)
                for(int l=0;l<12;l++)
                {
                    if(x[i].first>n || x[j].first>n || x[k].first>n || x[l].first>n) continue;
                    if(x[i].second>m || x[j].second>m || x[k].second>m || x[l].second>m) continue;
                    if(x[i]==x[j] || x[i]==x[k] || x[i]==x[l] || x[j]==x[k] || x[j]==x[l] || x[k]==x[l]) continue;
                    if(dist(x[i],x[j])+dist(x[j],x[k])+dist(x[k],x[l])>cur)
                    {
                        cur=dist(x[i],x[j])+dist(x[j],x[k])+dist(x[k],x[l]);
                        ans[0]=x[i];
                        ans[1]=x[j];
                        ans[2]=x[k];
                        ans[3]=x[l];
                    }
                }
    for(int i=0;i<4;i++)
        cout<<ans[i].first<<' '<<ans[i].second<<endl;

 }