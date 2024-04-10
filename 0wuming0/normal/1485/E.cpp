#include"bits/stdc++.h"
using namespace std;
#define ll long long
vector<int>dis[200005];
vector<int>v[200005];
ll dp[200005];
int pr[200005];
int val[200005];
int num[200005];
int maxdis;
void getnum(int i)
{
    if(num[i])return;
    getnum(pr[i]);//cout<<"<<<<"<<i<<"<<<"<<pr[i]<<"<<<<<"<<num[pr[i]]<<endl;
    maxdis=max((num[i]=num[pr[i]]+1),maxdis);
}
int save[200005],nn;
int savel[200005],saver[200005];
bool cmp(int x,int y)
{
    return dp[x]<dp[y];
}
vector<int>::iterator it;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",pr+i);
            v[pr[i]].push_back(i);
        }
        for(int i=2;i<=n;i++)scanf("%d",val+i);
        num[1]=1;
        maxdis=1;
        for(int i=2;i<=n;i++)getnum(i);//for(int i=1;i<=n;i++)printf("%d%c",num[i]," \n"[i==n]);
        //cout<<">>>>>>"<<maxdis<<endl;
        for(int i=1;i<=n;i++)
        {
            dis[num[i]].push_back(i);
        }
        for(int i=maxdis;i>=1;i--)
        {
            ll lnum=1e16,rnum=-1e16;
            nn=0;
            sort(dis[i].begin(),dis[i].end(),cmp);
            for(it=dis[i].begin();it!=dis[i].end();++it)
            {
                save[nn++]=*it;
            }
            savel[0]=saver[0]=val[save[0]];
            for(int i=1;i<nn;i++)
            {
                savel[i]=min(savel[i-1],val[save[i]]);
                saver[i]=max(saver[i-1],val[save[i]]);
            }
            for(int i=nn-1;i>=0;i--)
            {//cout<<"??"<<save[i]<<"<<<<"<<dp[save[i]]<<"<<<<"<<val[save[i]]<<endl;
                dp[pr[save[i]]]=max(dp[pr[save[i]]],dp[save[i]]+val[save[i]]-savel[i]);
                dp[pr[save[i]]]=max(dp[pr[save[i]]],dp[save[i]]+saver[i]-val[save[i]]);
                dp[pr[save[i]]]=max(dp[pr[save[i]]],rnum-val[save[i]]);
                dp[pr[save[i]]]=max(dp[pr[save[i]]],val[save[i]]-lnum);
                //cout<<dp[save[i]]+val[save[i]]-savel[i]<<">>>>"<<dp[save[i]]+saver[i]-val[save[i]]<<">>>>"<<rnum-val[save[i]]<<">>>>"<<val[save[i]]-lnum<<">>>>"<<endl;
                rnum=max(val[save[i]]+dp[save[i]],rnum);
                lnum=min(val[save[i]]-dp[save[i]],lnum);
            }
        }
        //cout<<"!!";
        //for(int i=1;i<=n;i++)printf("%lld%c",dp[i]," \n"[i==n]);
        cout<<dp[1]<<endl;
        for(int i=0;i<=n;i++)
        {
            dis[i].clear();
            dp[i]=0;
            v[i].clear();
            num[i]=0;
        }
    }
    return 0;
}