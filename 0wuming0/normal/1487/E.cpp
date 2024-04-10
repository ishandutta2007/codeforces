#include"bits/stdc++.h"
using namespace std;
int a[150005];
int b[150005];
int c[150005];
int d[150005];
int dp[150005][4];
int now;
vector<int>v[150005][4];
bool cmp(int x,int y)
{
    if(dp[x][now]==dp[y][now])return x<y;
    return dp[x][now]<dp[y][now];
}
vector<int>sum;
int main()
{
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    for(int i=1;i<=n1;i++)scanf("%d",a+i);
    for(int i=1;i<=n2;i++)scanf("%d",b+i);
    for(int i=1;i<=n3;i++)scanf("%d",c+i);
    for(int i=1;i<=n4;i++)scanf("%d",d+i);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y][1].push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y][2].push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y][3].push_back(x);
    }
    for(int i=1;i<=n1;i++)dp[i][0]=a[i];
    //0-1 n2
    now=0;sum.clear();for(int i=1;i<=n1;i++)sum.push_back(i);
    for(int i=1;i<=n2;i++)
    {
        sort(v[i][now+1].begin(),v[i][now+1].end(),cmp);
    }
    sort(sum.begin(),sum.end(),cmp);now=1;
    for(int i=1;i<=n2;i++)
    {//cout<<"ok"<<i<<endl;
        dp[i][now]=b[i];
        if(sum.size()==v[i][now].size())
        {
            dp[i][now]=1e9;
        }
        else
        {
            for(vector<int>::iterator it1=sum.begin(),it2=v[i][now].begin();;++it1,++it2)
            {
                if(it2==v[i][now].end()||*it2!=*it1)
                {
                    //cout<<"???"<<dp[*it1][now-1]<<endl;
                    dp[i][now]+=dp[*it1][now-1];
                    break;
                }
            }
        }
    }
    ////1-2 n3
    now=1;sum.clear();for(int i=1;i<=n2;i++)sum.push_back(i);
    for(int i=1;i<=n3;i++)
    {
        sort(v[i][now+1].begin(),v[i][now+1].end(),cmp);
    }
    sort(sum.begin(),sum.end(),cmp);now=2;
    for(int i=1;i<=n3;i++)
    {
        dp[i][now]=c[i];
        if(sum.size()==v[i][now].size())
        {
            dp[i][now]=1e9;
        }
        else
        {
            for(vector<int>::iterator it1=sum.begin(),it2=v[i][now].begin();;++it1,++it2)
            {
                if(it2==v[i][now].end()||*it2!=*it1)
                {
                    dp[i][now]+=dp[*it1][now-1];
                    break;
                }
            }
        }
    }
    ////2-3 n4
    now=2;sum.clear();for(int i=1;i<=n3;i++)sum.push_back(i);
    for(int i=1;i<=n4;i++)
    {
        sort(v[i][now+1].begin(),v[i][now+1].end(),cmp);
    }
    sort(sum.begin(),sum.end(),cmp);now=3;
    for(int i=1;i<=n4;i++)
    {
        dp[i][now]=d[i];
        if(sum.size()==v[i][now].size())
        {
            dp[i][now]=1e9;
        }
        else
        {
            for(vector<int>::iterator it1=sum.begin(),it2=v[i][now].begin();;++it1,++it2)
            {
                if(it2==v[i][now].end()||*it2!=*it1)
                {
                    dp[i][now]+=dp[*it1][now-1];
                    break;
                }
            }
        }
    }
    int ans=1e9;
    for(int i=1;i<=n4;i++)ans=min(dp[i][3],ans);
    if(ans==1e9)ans=-1;
    //for(int i=1;i<=n2;i++)printf("%d%c",dp[i][1]," \n"[i==n2]);
    //for(int i=1;i<=n3;i++)printf("%d%c",dp[i][2]," \n"[i==n3]);
    //for(int i=1;i<=n4;i++)printf("%d%c",dp[i][3]," \n"[i==n4]);
    cout<<ans<<endl;
    return 0;
}