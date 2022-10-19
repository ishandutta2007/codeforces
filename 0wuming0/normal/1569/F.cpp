#include"bits/stdc++.h"
using namespace std;
#define ll long long
int mp[13][13];
vector<pair<int,int> >save;
int vis[13];
struct _
{
    int a[7];
}null;
vector<_>v[7];
int n,m,k;
vector<pair<int,int> >check[105];
vector<pair<int,int> >sorts[105];
int cl[105];
int sv[105],nn;
set<ll>st[105];
int cg[1005][6],nown,lastn;
int stute[105][1005];
bool flag;
void add()
{
    int cnt=0;
    ll hnum;
    if(flag==0)
    {
        for(auto a:v[n/2])
        {
            for(int k=0;k<nown;k++)
            {
                nn=0;
                for(int p=0;p<(n>>1);p++)
                {
                    sv[nn++]=save[cg[k][p]-1].first;
                    sv[nn++]=save[cg[k][p]-1].second;
                }
                for(auto pr:sorts[cnt])
                {
                    for(int l=pr.first;l<pr.second;l+=2)for(int r=l+2;r<pr.second;r+=2)if(sv[l]>sv[r])
                    {
                        stute[cnt][k]=1;
                        goto nexts;
                    }
                    sort(sv+pr.first,sv+pr.second);
                }
                for(auto pr:check[cnt])
                {
                    if(sv[pr.first]>sv[pr.second])
                    {
                        stute[cnt][k]=1;
                        goto nexts;
                    }
                }
                hnum=0;
                for(int i=0;i<nn;i++)hnum+=(((ll)sv[i])<<(i<<2));
                st[cnt].insert(hnum);
                nexts:;
            }
            cnt++;
        }
        flag=1;
    }
    for(auto a:v[n/2])
    {
        for(int k=0;k<nown;k++)if(stute[cnt][k]==0)
        {
            nn=0;
            for(int p=0;p<(n>>1);p++)
            {
                sv[nn++]=save[cg[k][p]-1].first;
                sv[nn++]=save[cg[k][p]-1].second;
            }
            for(auto pr:sorts[cnt])
            {
                sort(sv+pr.first,sv+pr.second);
            }
            for(auto pr:check[cnt])
            {
                if(sv[pr.first]>sv[pr.second])goto ne;
            }
            hnum=0;
            for(int i=0;i<nn;i++)hnum+=(((ll)sv[i])<<(i<<2));
            st[cnt].insert(hnum);
            ne:;
        }
        cnt++;
    }
}
int dp[6][6][64];
void dfs(int bg,int j,int k)
{
    dp[bg][j][k]=1;
    for(int i=0;i<(n>>1);i++)if((k&(1<<i))==0&&((mp[save[i].first][save[j].first]==1&&mp[save[i].second][save[j].second]==1)||(mp[save[i].first][save[j].second]==1&&mp[save[i].second][save[j].first]==1)))
    {
        dfs(bg,i,k^(1<<i));
    }
}
void solve()
{
    for(int i=0;i<6;i++)for(int j=0;j<6;j++)for(int k=0;k<64;k++)dp[i][j][k]=0;
    for(int i=0;i<n/2;i++)if(mp[save[i].first][save[i].second])
    {
        dfs(i,i,1<<i);
    }
    for(int i=0;i<6;i++)for(int j=0;j<6;j++)
    {
        if(dp[i][j][(1<<(n/2))-1])
        {
            add();
            return;
        }
    }
}
int main()
{
    v[0].push_back(null);
    for(int i=1;i<=6;i++)
    {
        for(int j=6;j>=0;j--)
        {
            for(int num=1;i*num<=6;num++)
            {
                if(j+i*num>6)continue;
                for(auto a:v[j])
                {
                    a.a[i]=num;
                    v[j+i*num].push_back(a);
                }
            }
        }
    }
    cin>>n>>m>>k;
    for(int i=1;i<=6;i++)
    {
        cg[0][i-1]=i;
    }
    nown++;
    for(int i=0;i<n/2;i++)
    {
        lastn=nown;
        for(int num=0;num<lastn;num++)for(int j=i+1;j<n/2;j++)
        {
            for(int k=0;k<6;k++)
            {
                cg[nown][k]=cg[num][k];
            }
            swap(cg[nown][i],cg[nown][j]);
            nown++;
        }
    }
    //for(int i=0;i<nown;i++)for(int j=0;j<6;j++)printf("%d%c",cg[i][j]," \n"[j==5]);
    int cnt=0;
    for(auto a:v[n/2])
    {
        int now=0;//cout<<endl;for(int i=1;i<=6;i++)printf("%d%c",a.a[i]," \n"[i==6]);
        for(int k=1;k<=6;k++)if(a.a[k])
        {
            for(int i=0;i<a.a[k];i++)for(int j=i+1;j<a.a[k];j++)
            {//cout<<"<<"<<now+i*k*2<<" "<<now+j*k*2<<endl;
                check[cnt].push_back(make_pair(now+i*k*2,now+j*k*2));
            }
            for(int i=0;i<a.a[k];i++)
            {//cout<<">>"<<now<<" "<<now+k*2<<endl;
                sorts[cnt].push_back(make_pair(now,now+k*2));
                now+=k*2;
                cl[cnt]++;
            }
        }
        cnt++;
    }
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        mp[a][b]=mp[b][a]=1;
    }
    int cs[6],now=n-1,nn=0;
    while(now!=-1)
    {
        cs[nn++]=now;
        now-=2;
    }
    for(int p[6]={0};;p[0]++)
    {
        now=0;
        while(now<nn&&p[now]>=cs[now])
        {
            p[now]-=cs[now];
            p[++now]++;
        }
        if(now==nn)break;
        int l=1,r;
        now=0;
        while(1)
        {
            if(now==nn)break;
            while(1)
            {
                if(vis[l]==0)break;
                l++;
            }
            r=l+1;
            int num=p[now];
            while(1)
            {
                if(vis[r]==0)
                {
                    if(num==0)break;
                    else num--;
                }
                r++;
            }
            now++;
            vis[l]=vis[r]=1;
            save.push_back(make_pair(l,r));
        }
        solve();
        for(int i=0;i<=n;i++)vis[i]=0;
        save.clear();
    }
    ll sans[15]={0};
    sans[1]=k;
    for(int i=2;i<=k;i++)
    {
        sans[i]=sans[i-1]*(k-i+1);
    }
    ll ans=0;
    cnt=0;
    for(auto a:v[n/2])
    {
        ans+=sans[cl[cnt]]*st[cnt].size();
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}