#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[305][305];
struct peo
{
    int inx;
    int k;
    int x,y;
}p[100005];
bool cmp(peo x,peo y)
{
    if(x.k==y.k)return x.inx<y.inx;
    else return x.k<y.k;
}
bool cmp2(peo x,peo y)
{
    return x.inx<y.inx;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int cnt=0;
        for(int i=0;i<n*m;i++)
        {
            scanf("%d",&p[i].k);
            p[i].inx=i;
        }
        sort(p,p+n*m,cmp);
        int ans=0;
        for(int i=0,nowk,now;i<n*m;i++)
        {
            if(i%m==0)
            {
                now=1;
                nowk=p[i].k;
            }
            else
            {
                if(p[i].k==nowk)
                {
                    ans-=now++;
                }
                else
                {
                    now=1;
                    nowk=p[i].k;
                }
            }
            p[i].x=i/m;
            p[i].y=i%m;
        }
        sort(p,p+n*m,cmp2);
        for(int i=0;i<n*m;i++)
        {
            int x=p[i].x,y=p[i].y;
            a[x][y]=1;
            for(int j=0;j<y;j++)if(a[x][j])ans++;
        }
        printf("%d\n",ans);
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)a[i][j]=0;
    }
    return 0;
}