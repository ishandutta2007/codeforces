#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int inf=1e9+7;
int f[N][N][N],g[N];
char s[N],t[N],_t[N];
int n,m;
int bor;
inline void mn(int &x,int y)
{
    x>y?x=y:0;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for (int i=1;i<=m;++i)
    {
        for (int j=1;j<i;++j)
            _t[j]=t[j];
        _t[i]='0'+'1'-t[i];
        for (int j=i;j>=0;--j)
        {
            bool b=1;
            for (int k=1;k<=j;++k)
                if (t[k]!=_t[i-j+k])
                    b=0;
            if (b)
            {
                g[i]=j;
                break;
            }
        }
    }
    for (int i=m-1;i>=1;--i)
    {
        bool b=1;
        for (int j=1;j<=i;++j)
            if (t[j]!=t[m-i+j])
                b=0;
        if (b)
        {
            bor=i;
            break;
        }
    }
    //cout<<g[1]<<' '<<g[2]<<' '<<g[3]<<' '<<bor<<endl;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n-m+1;++j)
            for (int k=0;k<m;++k)
                f[i][j][k]=inf;
    f[0][0][0]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<=n-m+1;++j)
            for (int k=0;k<m;++k)
                if (f[i][j][k]!=inf)
                {
                    //cout<<i<<' '<<j<<' '<<k<<endl;
                    int cost=1;
                    if (s[i+1]==t[k+1])
                        cost=0;
                    if (k==m-1)
                        mn(f[i+1][j+1][bor],f[i][j][k]+cost);
                    else
                        mn(f[i+1][j][k+1],f[i][j][k]+cost);
                    mn(f[i+1][j][g[k+1]],f[i][j][k]+1-cost);
                }
    int ans;
    for (int i=0;i<=n-m+1;++i)
    {
        ans=inf;
        for (int j=0;j<m;++j)
            mn(ans,f[n][i][j]);
        if (ans==inf)
            ans=-1;
        printf("%d ",ans);
    }
    return 0;
}