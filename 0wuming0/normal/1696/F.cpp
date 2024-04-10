#include"bits/stdc++.h"
using namespace std;
char op[105][105][105];
int edge[105];
int dis[105][105];
vector<int>v[105];
bool vis[105];
int stk[105],ll,rr;
int n;
void bfs(int bg)
{
    for(int i=1;i<=n;i++)vis[i]=0;
    ll=rr=0;
    dis[bg][bg]=0;
    stk[rr++]=bg;
    vis[bg]=1;
    int num=0;
    while(ll!=rr)
    {
        num++;
        int m=rr;
        for(int i=ll;i<m;i++)
        {
            for(auto &j:v[stk[i]])
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    dis[bg][j]=num;
                    stk[rr++]=j;
                }
            }
        }
        ll=m;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        {
            scanf("%s",op[i][j]+1);
            strcpy(op[j][i]+1,op[i][j]+1);
        }
        for(int i=2;i<=n;i++)
        {//cout<<"<<"<<i<<endl;
            for(int j=1;j<=n;j++)v[j].clear();
            {
                vector<int>v;
                for(int i=1;i<=n;i++)edge[i]=0;
                edge[1]=i;
                edge[i]=1;
                v.push_back(i);
                v.push_back(1);
                while(v.size())
                {
                    int k=v[v.size()-1];
                    v.pop_back();
                    int l=edge[k];
                    for(int j=1;j<=n;j++)if(edge[j]==0)
                    {
                        if(op[j][l][k]=='1')
                        {
                            edge[j]=k;
                            v.push_back(j);
                        }
                    }
                }
            }
            for(int j=1;j<=n;j++)if(edge[j]==0)goto pe;
            for(int j=2;j<=n;j++)
            {
                v[j].push_back(edge[j]);
                v[edge[j]].push_back(j);//cout<<"??"<<j<<" "<<(int)edge[j]<<endl;
            }/*
            {
                for(int i=1;i<=n;i++)
                {
                    for(auto j:v[i])cout<<j;
                    cout<<endl;
                }
            }//*/
            for(int j=1;j<=n;j++)
            {
                bfs(j);//cout<<"!!ok"<<j<<endl;
                for(int k=1;k<=n;k++)if(vis[k]==0)goto pe;//cout<<"!!ok"<<j<<endl;
            }//cout<<"<<<"<<i<<" "<<"ok"<<endl;
            {
                for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=1;k<=n;k++)
                {
                    if(op[i][j][k]=='1')
                    {
                        if(dis[i][k]!=dis[j][k])goto pe;
                    }
                    else
                    {
                        if(dis[i][k]==dis[j][k])goto pe;
                    }
                }
                cout<<"yes"<<endl;
                for(int i=1;i<=n;i++)
                {
                    for(auto &j:v[i])
                    {
                        if(i<j)
                        {
                            printf("%d %d\n",i,j);
                        }
                    }
                }
                goto ne;
            }
            pe:;
        }
        cout<<"no"<<endl;
        ne:;
    }
    return 0;
}