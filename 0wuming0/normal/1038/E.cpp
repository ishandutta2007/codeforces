#include"bits/stdc++.h"
using namespace std;
int m2[5][5];
int m[5];
int best[5][5];
int val[5];
int vis[5];
int sum[5][5];
int ssum;
void add(vector<int>&v,int j)
{
    vis[j]=1;
    v.push_back(j);
    for(int i=1;i<5;i++)
        if(m2[i][j]>0&&vis[i]==0)
            add(v,i);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)best[i][j]=1e9;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==c)
        {
            val[a]+=b;
            ssum+=b;
        }
        else
        {
            m2[a][c]++;
            m2[c][a]++;
            ssum+=b;
            m[a]++;
            m[c]++;
            best[a][c]=min(best[a][c],b);
            best[c][a]=best[a][c];
            sum[a][c]+=b;
            sum[c][a]+=b;
        }
    }//cout<<ssum<<endl;
    int ans=0;
    for(int i=1;i<5;i++)if(!vis[i])
    {
        vector<int>v;
        add(v,i);
        if(v.size()!=4||m[1]%2==0||m[2]%2==0||m[3]%2==0||m[4]%2==0)
        {
            int anss=0;
            for(int j=0;j<v.size();j++)
            {
                anss+=val[v[j]];
            }
            for(int j=0;j<v.size();j++)for(int k=j+1;k<v.size();k++)
            {
                anss+=sum[v[j]][v[k]];
            }
            ans=max(ans,anss);
        }
        else
        {
            ans=1e9;
            for(int j=1;j<=4;j++)for(int k=j+1;k<=4;k++)if(m2[j][k])
            {
                int anss=0;
                anss+=best[j][k];
                if(m[j]==1)anss+=val[j];
                if(m[k]==1)anss+=val[k];
                ans=min(ans,anss);
            }
            ans=ssum-ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}