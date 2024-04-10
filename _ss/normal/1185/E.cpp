#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e3+5;
char a[maxn][maxn],b[maxn][maxn];
int n,m,visit[maxn][maxn];
vector<pii> p[27];
pii di[5],col[27],ror[27];
stack<pii> st;
void dfs(int x,int y)
{
    st.push({x,y});
    while (!st.empty())
    {
        while (!st.empty() && !visit[st.top().fi][st.top().se]) st.pop();
        if (st.empty()) break;
        pii u=st.top();
        st.pop();
        visit[u.fi][u.se]=0;
        p[(int)(a[u.fi][u.se])-96].pb({u.fi,u.se});
        for (int i=1;i<=4;i++)
        {
            int t1=u.fi+di[i].fi,t2=u.se+di[i].se;
            if (a[t1][t2]==a[x][y] && visit[t1][t2]) st.push({t1,t2});
        }
    }
}

/*void dfs(int x,int y)
{
    visit[x][y]=0;
    p[(int)(a[x][y])-96].pb({x,y});
    for (int i=1;i<=4;i++)
    {
        int t1=x+di[i].fi,t2=y+di[i].se;
        if (visit[t1][t2] && a[t1][t2]==a[x][y]) dfs(t1,t2);
    }
}*/

bool process(int t)
{
    int kt=1;
    for (int i=0;i<p[t].size()-1;i++)
        if (p[t][i].fi!=p[t][i+1].fi) kt=0;
    if (kt)
    {
        col[t].fi=p[t][0].fi;
        ror[t].fi=col[t].fi;
        col[t].se=1e9;
        ror[t].se=-1e9;
        for (int i=0;i<p[t].size();i++)
        {
            col[t].se=min(col[t].se,p[t][i].se);
            ror[t].se=max(ror[t].se,p[t][i].se);
        }
        return true;
    }
    kt=1;
    for (int i=0;i<p[t].size()-1;i++)
        if (p[t][i].se!=p[t][i+1].se) kt=0;
    if (!kt) return false;
        col[t].se=p[t][0].se;
        ror[t].se=col[t].se;
        col[t].fi=1e9;
        ror[t].fi=-1e9;
        for (int i=0;i<p[t].size();i++)
        {
            col[t].fi=min(col[t].fi,p[t][i].fi);
            ror[t].fi=max(ror[t].fi,p[t][i].fi);
        }
    return true;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    di[1]={0,1};
    di[2]={0,-1};
    di[3]={1,0};
    di[4]={-1,0};
    int t;
    cin>>t;
    char ch;
    for (int o=1;o<=t;o++)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            ch=getchar();
            for (int j=1;j<=m;j++) a[i][j]=getchar(),visit[i][j]=1;
        }
        for (int i=1;i<=26;i++) p[i].clear();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (visit[i][j] && a[i][j]!='.') dfs(i,j);
        int k=0,kt=1;
        for (int i=1;i<=26;i++)
            if (!p[i].empty()) k=i;
        for (int i=1;i<=k;i++)
            if (!p[i].empty())
            {
                if (!process(i)) kt=0;
            }
        for (int i=1;i<=k;i++)
            if (p[i].empty())
            {
                col[i]=col[k];
                ror[i]=ror[k];
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) b[i][j]='.';
        for (int i=1;i<=k;i++)
            if (!p[i].empty())
            {
                for (int u=col[i].fi;u<=ror[i].fi;u++)
                    for (int v=col[i].se;v<=ror[i].se;v++) b[u][v]=(char)(i+96);
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]!=b[i][j]) kt=0;
        if (kt)
        {
            cout<<"YES"<<endl;
            cout<<k<<endl;
            for (int i=1;i<=k;i++) cout<<col[i].fi<<" "<<col[i].se<<" "<<ror[i].fi<<" "<<ror[i].se<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}