#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=3e5+1;
int a[maxn][20],n,f[20][20],q;

void pt(int x,int i)
{
    int d=0;
    while (x)
    {
        if (x&1) a[i][d]=i;
        x/=2;
        d++;
    }
}

void update(int t)
{
    for (int i=0;i<=18;i++)
        if (a[t][i]==t)
            for (int j=0;j<=18;j++) f[i][j]=max(f[i][j],a[t][j]);
}

void findmax(int t)
{
    for (int i=0;i<=18;i++)
        if (a[t][i]<t)
            for (int j=0;j<=18;j++)
                if (a[t][j]==t) a[t][i]=max(a[t][i],f[j][i]);
}

void dp()
{
    for (int i=1;i<=n;i++)
    {
        findmax(i);
        update(i);
    }
}

int main()
{
    int x,y;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pt(x,i);
    }
    dp();
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);
        int k=0;
        for (int j=0;j<=18;j++)
            if (a[x][j]==x) k=max(k,a[y][j]);
        if (k>=x) printf("Shi\n"); else printf("Fou\n");
    }
    return 0;
}