#include"bits/stdc++.h"
using namespace std;
int vis[100005];
//int get[100005][105];
struct _
{
    int city;
    int now;
};
vector<int> ans[100005];
_ st[100005][105];int nn[105];
vector<int>road[100005];
void add(_ &a,int t)
{
    st[nn[t]++][t]=a;
}
int main()
{
    int n,m,s,k;
    cin>>n>>m>>s>>k;
    for(int i=0;i<n;i++)
    {
        _ a;int t;
        scanf("%d",&t);
        a.city=i+1;
        a.now=0;
        add(a,t);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        road[a].push_back(b);
        road[b].push_back(a);
    }
    for(int t=1;t<=s;t++)
    {
        for(int i=0;i<nn[t];i++)
        {
            vis[st[i][t].city]=t;
        }
        for(int i=0;i<nn[t];i++)
        {
            for(vector<int>::iterator it=road[st[i][t].city].begin();it!=road[st[i][t].city].end();++it)
            {
                if(vis[*it]!=t)
                {
                    vis[*it]=t;
                    _ save;
                    save.city=*it;
                    save.now=st[i][t].now+1;
                    add(save,t);
                }//return 0;
            }
        }
        for(int i=0;i<nn[t];i++)
        {
            //get[st[i][t].city][t]=st[i][t].now;
            ans[st[i][t].city].push_back(st[i][t].now);
        }
    }//cout<<"ok"<<endl;
    for(int i=1;i<=n;i++)
    {
        sort(ans[i].begin(),ans[i].end());
        vector<int>::iterator it=ans[i].begin();
        int t=k;
        int anss=0;
        while(t--)
        {
            anss+=*it;
            ++it;
        }
        printf("%d%c",anss," \n"[i==n]);
    }
    return 0;
}