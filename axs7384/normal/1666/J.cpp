#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205;
int c[N][N],rt[N][N];
ll f[N][N],g[N][N];
int n;
int ans[N];
void work(int l,int r,int fa)
{
    if (l>r)
        return;
    //cout<<l<<' '<<r<<' '<<fa<<endl;
    ans[rt[l][r]]=fa;
    work(l,rt[l][r]-1,rt[l][r]);
    work(rt[l][r]+1,r,rt[l][r]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            scanf("%d",&c[i][j]);
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
        {
            g[i][j]=g[i][j-1];
            for (int k=1;k<=n;++k)
                if (k<i||k>j)
                    g[i][j]+=c[j][k];
                else
                    g[i][j]-=c[j][k];
            //cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
        }
    for (int i=1;i<=n;++i)
    {
        f[i][i]=g[i][i];
        rt[i][i]=i;
    }
    for (int i=n-1;i>=1;--i)
        for (int j=i+1;j<=n;++j)
        {
            f[i][j]=f[i+1][j];
            rt[i][j]=i;
            for (int k=i+1;k<j;++k)
                if (f[i][j]>f[i][k-1]+f[k+1][j])
                {
                    f[i][j]=f[i][k-1]+f[k+1][j];
                    rt[i][j]=k;
                }
            if (f[i][j]>f[i][j-1])
            {
                f[i][j]=f[i][j-1];
                rt[i][j]=j;
            }
            f[i][j]+=g[i][j];
            //cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<rt[i][j]<<endl;
        }
    work(1,n,0);
    for (int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}