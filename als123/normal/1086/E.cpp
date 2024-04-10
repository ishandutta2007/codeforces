#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2005;
const int MOD=998244353;
int add (int x,int y)
{
    x=x+y;
    return x>=MOD?x-MOD:x;
}
int mul (int x,int y)
{
    return (LL)x*y%MOD;
}
int dec (int x,int y)
{
    x=x-y;
    return x<0?x+MOD:x;
}
int Pow (int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    int lalal=Pow(x,y>>1);
    lalal=mul(lalal,lalal);
    if (y&1) lalal=mul(lalal,x);
    return lalal;
}
int n;
int a[N][N];
int f[N][N];
int JC[N];
bitset<2001> h,h1,h2;
int main()
{
    scanf("%d",&n);
    JC[0]=1;
    for (int u=1; u<=n; u++) JC[u]=mul(JC[u-1],u);
    for (int u=0; u<=n; u++)
    {
        for (int i=0; i<=u; i++) f[u][i]=JC[i];
        f[u][u+1]=mul(u,JC[u]);
        f[u][u+2]=add(mul(u+1,f[u][u+1]),f[u][u]); 
        for (int i=u+3; i<=n; i++)
        {
            int t=i-u-1;
            f[u][i]=mul(t,add(f[u][i-1],f[u][i-2]));
            f[u][i]=add(f[u][i],mul(u,f[u][i-1]));
        }
    }
    //printf("%d %d\n",f[0][2],f[0][1]);
    for (int u=1; u<=n; u++)
        for (int i=1; i<=n; i++)
            scanf("%d",&a[u][i]);
    int ans=0;
    for (int u=1; u<=n; u++)
    {
        for (int i=1; i<=n; i++) h1[i]=1,h[i]=1;
        if (u==1) h.reset();
        int sum=0;
        for (int i=1; i<=n; i++)
        {
            if (u!=1) h[a[u-1][i]]=0;
            int t1,t2,t3;
            h2=(h&h1);
            t1=h2.count();
            h1[a[u][i]]=0;
            h2=h1;
            //for (int j=a[u][i]; j<=n; j++) h2[j]=0;
            h2=(h2^((h2>>(a[u][i]+1))<<(a[u][i]+1)));
            if (u!=1) h2[a[u-1][i]]=0;
            t2=h2.count();
            h2=(h2&h);
            t3=h2.count();
            t2=t2-t3;
            int j=n-i;
            if (t3!=0) sum=add(sum,mul(t3,f[j-t1+1][j]));
            sum=add(sum,mul(t2,f[j-t1][j]));
            //printf("%d sum:%d t1:%d t2:%d t3:%d %d\n",u,sum,t1,t2,t3,j-t1+1);
        }
       // printf("%d %d %d\n",u,sum,f[0][n]);
        ans=add(ans,mul(sum,Pow(f[0][n],n-u)));
    }
    printf("%d\n",ans);
    return 0;
}