#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<bool>> a;
vector<int> sz(1000001,-1);
vector<int> szt(1000001,-1);

void ini()
{
    sz[1000000]=21;
    for(int i=0;i<19;i++) sz[1<<i]=i+1;
    for(int i=999999;i>=0;i--) if(sz[i]==-1) sz[i]=sz[i+1];
    for(int i=0;i<19;i++) szt[1<<i]=i;
    for(int i=1;i<=1000000;i++) if(szt[i]==-1) szt[i]=szt[i-1];
}

bool solve(vector<pair<int,int>> v,int t)
{
    bool b[n][m];
    bool src[n][m];
    bool down[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) b[o][i]=src[o][i]=down[o][i]=0;
    for(pair<int,int> p:v) src[p.first][p.second]=1;
    for(int o=0;o<n;o++)
    {
        int l=-1000000000;
        for(int i=0;i<m;i++)
        {
            if(src[o][i]) l=i;
            if(i-l<=t) down[o][i]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        int d=-1000000000;
        for(int o=0;o<n;o++)
        {
            if(down[o][i]) d=o;
            if(o-d<=t) b[o][i]=1;
        }
    }
    bool ok=1;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(a[o][i]!=b[o][i]) ok=0;
        }
    }
    return ok;
}

int main()
{
    ini();
    scanf("%d%d",&n,&m);
    a.resize(n);
    char s[n][m+1];
    for(int o=0;o<n;o++)
    {
        scanf("%s",s[o]);
        vector<bool> t(m);
        for(int i=0;i<m;i++) t[i]=(s[o][i]=='X');
        a[o]=t;
    }
    bool sp[n][m][sz[n]][sz[m]];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) for(int j=0;j<sz[n];j++) for(int k=0;k<sz[m];k++) sp[o][i][j][k]=1;
    //Build sparse table
    for(int o=n-1;o>=0;o--)
    {
        for(int i=m-1;i>=0;i--) sp[o][i][0][0]=a[o][i];
        for(int i=m-1;i>=0;i--) for(int k=1;i+(1<<k)<=m;k++) sp[o][i][0][k]=min(sp[o][i][0][k-1],sp[o][i+(1<<(k-1))][0][k-1]);
        for(int i=m-1;i>=0;i--) for(int j=1;o+(1<<j)<=n;j++) sp[o][i][j][0]=min(sp[o][i][j-1][0],sp[o+(1<<(j-1))][i][j-1][0]);
        for(int i=m-1;i>=0;i--)
        {
            for(int j=1;o+(1<<j)<=n;j++)
            {
                for(int k=1;i+(1<<k)<=m;k++)
                {
                    int t=1;
                    t=min(t,(int)sp[o][i][j-1][k-1]);
                    t=min(t,(int)sp[o+(1<<(j-1))][i][j-1][k-1]);
                    t=min(t,(int)sp[o][i+(1<<(k-1))][j-1][k-1]);
                    t=min(t,(int)sp[o+(1<<(j-1))][i+(1<<(k-1))][j-1][k-1]);
                    sp[o][i][j][k]=t;
                }
            }
        }
    }
    vector<pair<int,int>> res;
    int l=-1,r=max(n,m)+1;
    while(l<r-1)
    {
        int t=(l+r)/2;
        vector<pair<int,int>> src;
        for(int o=t;o+t<n;o++)
        {
            for(int i=t;i+t<m;i++)
            {
                int ar,ac,br,bc;
                tie(ar,ac,br,bc)=make_tuple(o-t,i-t,o+t,i+t);
                int j=szt[br-ar+1];
                int k=szt[bc-ac+1];
                int f=1;
                f=min(f,(int)sp[ar][ac][j][k]);
                f=min(f,(int)sp[br-(1<<j)+1][ac][j][k]);
                f=min(f,(int)sp[ar][bc-(1<<k)+1][j][k]);
                f=min(f,(int)sp[br-(1<<j)+1][bc-(1<<k)+1][j][k]);
                if(f==1) src.push_back({o-t,i-t});
            }
        }
        if(solve(src,2*t))
        {
            l=t;
            res=src;
        }
        else r=t;
    }
    printf("%d\n",l);
    char fin[n][m+1];
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++) fin[o][i]='.';
        fin[o][m]='\0';
    }
    for(pair<int,int> p:res)
    {
        fin[p.first+l][p.second+l]='X';
    }
    for(int o=0;o<n;o++) printf("%s\n",fin[o]);
    return 0;
}