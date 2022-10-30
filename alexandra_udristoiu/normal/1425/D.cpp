#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7, l=1000;

struct str
{
    int x,y,b;
};

int comb[2010][2010],aib[2010][2010],r,cnt[2010];
str v[2010];

void add(int &a, int b)
{
    a+=b;
    if(a>=mod) a-=mod;
}

void update(int x,int y,int val)
{
    if(x==0 or y==0) return;
    for(int i=x;i<=l;i+= i&(-i))
        for(int j=y;j<=l;j+= j&(-j)) aib[i][j]+=val;
}

int query(int x,int y)
{
    int s=0;
    for(int i=x;i>0;i-=i&(-i))
        for(int j=y;j>0;j-=j&(-j))
            s+=aib[i][j];
    return s;
}

void updSquare(str p, int sgn)
{
    int x=max(p.x-r,1), x1=min(p.x+r,l);
    int y=max(p.y-r,1), y1=min(p.y+r,l);
    update(x,y,sgn);
    update(x,y1+1,-sgn);
    update(x1+1,y,-sgn);
    update(x1+1,y1+1,sgn);
}

//p1 inclus in p2 ?
int inclus(str p1,str p2)
{
    int x=max(p2.x-r,1), x1=min(p2.x+r,l);
    int y=max(p2.y-r,1), y1=min(p2.y+r,l);
    if(p1.x>=x && p1.x<=x1 && p1.y>=y && p1.y<=y1) return 1;
    return 0;
}

int main()
{
    int n,m,ans=0;
    scanf("%d%d%d",&n,&m,&r);
    comb[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        comb[i][0]=1;
        for(int j=1;j<=i;j++)
            add(comb[i][j], comb[i-1][j]+comb[i-1][j-1]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].b);
        updSquare(v[i], 1);
    }
    for(int i=1;i<=n;i++)
    {
        cnt[i]=query(v[i].x,v[i].y);
        int nr=comb[n][m];
        if(n-cnt[i]>=m)
        {
            nr-=comb[n-cnt[i]][m];
            if(nr<0) nr+=mod;
        }
        add(ans, (1LL*nr*((1LL*v[i].b*v[i].b)%mod))%mod);
    }
    for(int i=1;i<=n;i++)
        updSquare(v[i], -1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(inclus(v[i],v[j])) updSquare(v[j],1);
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                int nr=comb[n][m];
                int ambele=query(v[j].x,v[j].y);
                if(n-cnt[j]>=m)
                {
                    nr-=comb[n-cnt[j]][m];
                    if(nr<0) nr+=mod;
                }
                if(n-cnt[i]>=m)
                {
                    nr-=comb[n-cnt[i]][m];
                    if(nr<0) nr+=mod;
                }
                if(n-cnt[i]-cnt[j]+ambele>=m) add(nr,comb[n-cnt[i]-cnt[j]+ambele][m]);
                add(ans, (1LL*nr*((1LL*v[i].b*v[j].b)%mod))%mod);
            }
        for(int j=1;j<=n;j++)
            if(inclus(v[i],v[j])) updSquare(v[j],-1);
    }
    printf("%d",ans);
    return 0;
}