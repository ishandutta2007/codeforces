#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;
const LL inf=(LL)2e18;

int sz,last,ch[N*2][4],fa[N*2],mx[N*2],r[N*2],deg[N*2];
LL n,f[N*2];
char str[N];
struct Matrix {LL a[4][4];}a;

void ins(int x)
{
    int p,q,np,nq;
    p=last;last=np=++sz;mx[np]=mx[p]+1;
    for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
    if (!p) fa[np]=1;
    else
    {
        q=ch[p][x];
        if (mx[q]==mx[p]+1) fa[np]=q;
        else
        {
            nq=++sz;mx[nq]=mx[p]+1;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
        }
    }
}

void topusort()
{
    for (int i=1;i<=sz;i++)
        for (int j=0;j<4;j++)
            if (ch[i][j]) deg[ch[i][j]]++;
    int tot=0;
    for (int i=1;i<=sz;i++) if (!deg[i]) r[++tot]=i;
    for (int i=1;i<=tot;i++)
        for (int j=0;j<4;j++)
        {
            deg[ch[r[i]][j]]--;
            if (!deg[ch[r[i]][j]]) r[++tot]=ch[r[i]][j];
        }
}

void pre(int now)
{
    for (int i=1;i<=sz;i++) f[i]=inf;
    f[ch[1][now]]=1;
    for (int i=1;i<=sz;i++)
    {
        int x=r[i];
        for (int j=0;j<4;j++)
            if (!ch[x][j]) a.a[now][j]=min(a.a[now][j],f[x]);
            else f[ch[x][j]]=min(f[ch[x][j]],f[x]+1);
    }
}

void mul(Matrix a,Matrix b,Matrix &c)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            c.a[i][j]=inf;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
                c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
}

bool check(LL y)
{
    Matrix ans=a,x=a;y--;
    while (y)
    {
        if (y&1) mul(ans,x,ans);
        mul(x,x,x);y>>=1;
    }
    LL mn=inf;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            mn=min(mn,ans.a[i][j]);
    return mn+1<=n;
}

int main()
{
    scanf("%I64d%s",&n,str);
    int len=strlen(str);
    sz=last=1;
    for (int i=0;i<len;i++) ins(str[i]-'A');
    topusort();
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) a.a[i][j]=inf;
        pre(i);
    }
    LL l=1,r=n;
    while (l<=r)
    {
        LL mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%I64d",l);
    return 0;
}