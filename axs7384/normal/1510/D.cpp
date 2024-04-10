#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const double inf=1e9;
const double eps=1e-9;
int n,m,a[N],g[N][10];
vector<int> v;
double f[N][10];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=0;i<=9;++i)
        f[0][i]=-inf;
    f[0][1]=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<=9;++j)
        {
            f[i][j]=f[i-1][j];
            g[i][j]=-1;
        }
        double p=log2((double)a[i]);
        for (int j=0;j<=9;++j)
        {
            int u=(j*a[i])%10;
            if (f[i][u]<f[i-1][j]+p+eps)
            {
                g[i][u]=j;
                f[i][u]=f[i-1][j]+p;
            }
        }
    }
  //  for (int i=0;i<=9;++i)
   //     printf("%lf ",pow(2,f[n][i]));
   // puts("");
    int now=m;
    for (int i=n;i;--i)
    {
       // cout<<i<<' '<<now<<' '<<g[i][now]<<endl;
        if (g[i][now]!=-1)
        {
            v.push_back(i);
            now=g[i][now];
        }
    }
    if (f[n][m]<-inf/2||v.size()==0)
        puts("-1");
    else
    {
        printf("%d\n",(int)v.size());
        for (int i=0;i<(int)v.size();++i)
            printf("%d ",a[v[i]]);
    }
    return 0;
}