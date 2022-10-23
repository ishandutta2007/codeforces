#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+10;
ll n,m,k,q,b[maxn],maxy[maxn],miny[maxn],vt[maxn][5],dp[maxn][5],maxx=0;

void read()
{
    ll x,y;
    cin>>n>>m>>k>>q;
    for (int i=1;i<=n;i++) miny[i]=1e9;
    for (int i=1;i<=k;i++) scanf("%I64d %I64d",&x,&y),maxy[x]=max(maxy[x],y),miny[x]=min(miny[x],y),maxx=max(x,maxx);
    for (int i=1;i<=q;i++) scanf("%I64d",&b[i]);
}

ll dis(ll x,ll y)
{
    if (x>y) return x-y; else return y-x;
}

void process()
{
    sort(b+1,b+q+1);
    if (maxy[1]==0)
    {
        ll tmp=lower_bound(b+1,b+q+1,1)-b;
        if (tmp>q) tmp--;
        vt[1][1]=vt[1][2]=vt[1][3]=vt[1][4]=b[tmp];
        dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=b[tmp]-1;
    }
    else
    {
        ll tmp=lower_bound(b+1,b+q+1,maxy[1])-b,check=0;
        if (tmp>q) tmp--,check=1;
        vt[1][2]=vt[1][4]=b[tmp];
        int ht=b[tmp]-1;
        if (b[tmp]<maxy[1]) ht=maxy[1]-1+maxy[1]-b[tmp];
        dp[1][2]=dp[1][4]=ht;
        if (tmp>1 && !check)
        {
            vt[1][1]=vt[1][3]=b[tmp-1];
            dp[1][1]=dp[1][3]=maxy[1]-1+maxy[1]-b[tmp-1];
        }
        else
        {
            vt[1][1]=vt[1][3]=b[tmp];
            dp[1][1]=dp[1][3]=ht;
        }
    }
    for (int i=2;i<=n;i++)
        if (maxy[i])
        {
            ll tmp=lower_bound(b+1,b+q+1,miny[i])-b,check=1;
            if (tmp>q) tmp--,check=0;
            if (tmp>1 && check) vt[i][1]=b[tmp-1]; else vt[i][1]=b[tmp];
            vt[i][2]=b[tmp];
            check=1;
            tmp=lower_bound(b+1,b+q+1,maxy[i])-b;
            if (tmp>q) tmp--,check=0;
            if (tmp>1 && check) vt[i][3]=b[tmp-1]; else vt[i][3]=b[tmp];
            vt[i][4]=b[tmp];
        }
    for (int i=2;i<maxx;i++)
        if (!maxy[i])
        {
            for (int j=1;j<=4;j++)
            {
                vt[i][j]=vt[i-1][j];
                dp[i][j]=dp[i-1][j]+1;
            }
        }
        else
        {
            for (int j=1;j<=4;j++)
            {
                dp[i][j]=1e18;
                for (int t=1;t<=4;t++)
                {
                    ll tmp=min(dis(vt[i-1][t],maxy[i])+dis(maxy[i],miny[i])+dis(miny[i],vt[i][j]),dis(vt[i-1][t],miny[i])+dis(maxy[i],miny[i])+dis(maxy[i],vt[i][j]));
                    dp[i][j]=min(dp[i][j],dp[i-1][t]+tmp+1);
                }
            }
        }
    ll ans=1e18;
    for (int i=1;i<=4;i++)
    {
        ll tmp=min(dis(vt[maxx-1][i],maxy[maxx]),dis(vt[maxx-1][i],miny[maxx]))+dis(miny[maxx],maxy[maxx])+1+dp[maxx-1][i];
        ans=min(tmp,ans);
        //cout<<tmp<<endl;
    }
    /*for (int i=1;i<maxx;i++)
    {
        for (int j=1;j<=4;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    if (maxx>1) process();
    else cout<<maxy[1]-1;
    return 0;
}