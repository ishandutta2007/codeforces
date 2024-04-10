#include"bits/stdc++.h"
using namespace std;
int t[100005];
int main()
{
    int y0,m0,d0;
    scanf("%d:%d:%d",&y0,&m0,&d0);
    int i,y,m,d;
    int mou[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    y=1900;m=1;d=1;
    for(i=0;;i++)
    {
        if(y==y0&&m==m0&&d==d0)break;
        d++;
        int md=mou[m];
        if(m==2&&y%4==0&&y!=1900)md++;
        if(d>md)m++,d=1;
        if(m>12)m=1,y++;
    }
    int ans=i;
    y=1900;m=1;d=1;//cout<<i<<endl;
    scanf("%d:%d:%d",&y0,&m0,&d0);
    for(i=0;;i++)
    {
        if(y==y0&&m==m0&&d==d0)break;
        d++;
        int md=mou[m];
        if(m==2&&y%4==0&&y!=1900)md++;
        if(d>md)m++,d=1;
        if(m>12)m=1,y++;
    }
    cout<<abs(i-ans)<<endl;
    return 0;
}