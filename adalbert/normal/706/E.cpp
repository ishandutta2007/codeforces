#include <bits/stdc++.h>
using namespace std;
long long n,m,q,s[2000][2000],id[2000][2000],jd[2000][2000],ir[2000][2000],jr[2000][2000],a,b,c,d,h,w,tepi1,tepi2,tepj1,tepj2,ti1,tj1,ti2,tj2,xi,xj;
int main()
{
        cin>>n>>m>>q;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
        {
            scanf("%d", & s[i][j]);
        }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
        {
            id[i][j]=i+1;
            jd[i][j]=j;
            ir[i][j]=i;
            jr[i][j]=j+1;
        }
        while (q--)
        {
            cin>>a>>b>>c>>d>>h>>w;
            tepi1=0;
            tepj1=0;
            tepi2=0;
            tepj2=0;
            for (int i=1;i<=a-1;i++)
            {
                xi=id[tepi1][tepj1];
                xj=jd[tepi1][tepj1];
                tepi1=xi;
                tepj1=xj;
            }
            for (int i=1;i<=b-1;i++)
            {
                xi=ir[tepi1][tepj1];
                xj=jr[tepi1][tepj1];
                tepi1=xi;
                tepj1=xj;
            }


            for (int i=1;i<=c-1;i++)
            {
                xi=id[tepi2][tepj2];
                xj=jd[tepi2][tepj2];
                tepi2=xi;
                tepj2=xj;
            }
            for (int i=1;i<=d-1;i++)
            {
                xi=ir[tepi2][tepj2];
                xj=jr[tepi2][tepj2];
                tepi2=xi;
                tepj2=xj;
            }
            //cout<<tepi1<<' '<<tepj1<<' '<<tepi2<<' '<<tepj2<<'\n';
            ti2=tepi2;
            ti1=tepi1;
            tj2=tepj2;
            tj1=tepj1;

            for (int i=1;i<=h;i++)
            {
                xi=id[ti1][tj1];
                xj=jd[ti1][tj1];
                ti1=xi;
                tj1=xj;
                xi=id[ti2][tj2];
                xj=jd[ti2][tj2];
                ti2=xi;
                tj2=xj;
                swap(ir[ti1][tj1],ir[ti2][tj2]);
                swap(jr[ti1][tj1],jr[ti2][tj2]);
            }
            for (int i=1;i<=w;i++)
            {
                xi=ir[ti1][tj1];
                xj=jr[ti1][tj1];
                ti1=xi;
                tj1=xj;
                xi=ir[ti2][tj2];
                xj=jr[ti2][tj2];
                ti2=xi;
                tj2=xj;
                swap(id[ti1][tj1],id[ti2][tj2]);
                swap(jd[ti1][tj1],jd[ti2][tj2]);
            }

            ti2=tepi2;
            ti1=tepi1;
            tj2=tepj2;
            tj1=tepj1;

            for (int i=1;i<=w;i++)
            {
                xi=ir[ti1][tj1];
                xj=jr[ti1][tj1];
                ti1=xi;
                tj1=xj;
                xi=ir[ti2][tj2];
                xj=jr[ti2][tj2];
                ti2=xi;
                tj2=xj;
                swap(id[ti1][tj1],id[ti2][tj2]);
                swap(jd[ti1][tj1],jd[ti2][tj2]);
            }
            for (int i=1;i<=h;i++)
            {
                xi=id[ti1][tj1];
                xj=jd[ti1][tj1];
                ti1=xi;
                tj1=xj;
                xi=id[ti2][tj2];
                xj=jd[ti2][tj2];
                ti2=xi;
                tj2=xj;
                swap(ir[ti1][tj1],ir[ti2][tj2]);
                swap(jr[ti1][tj1],jr[ti2][tj2]);
            }
        }




        for (int i=1;i<=n;i++)
        {
            tepi1=i;
            tepj1=0;
            for (int j=1;j<=m;j++)
            {
                xi=ir[tepi1][tepj1];
                xj=jr[tepi1][tepj1];
                tepi1=xi;
                tepj1=xj;
                cout<<s[tepi1][tepj1]<<' ';
            }
            cout<<'\n';
        }
}