#include"bits/stdc++.h"
#define ll unsigned long long
using namespace std;
#define mmm 21000000000000000ll
ll x,y,xa,ya,xb,yb,t;
struct _
{
    ll x;
    ll y;
} p[1000];
ll ab(ll a,ll b){return max(a,b)-min(a,b);}
int main()
{
    cin>>x>>y>>xa>>ya>>xb>>yb;
    p[0].x=x;
    p[0].y=y;
    int flag=0;
    int n;
    for(int i=1;i<1000;i++)
    {
        if((mmm-xb)/xa<p[i-1].x||(mmm-yb)/ya<p[i-1].y)
        {
            flag=1;n=i;
        }
        p[i].x=p[i-1].x*xa+xb;
        p[i].y=p[i-1].y*ya+yb;
        if(flag)p[i].x=p[i].y=-1;
    }
    ll m=0;
    cin>>x>>y>>t;
    for(int i=0;i<n;i++)
    {
        ll nowm=0,nowt=t;
        for(int j=i;j>=0;j--)
        {
            if(j==i)
            {
                if(ab(x,p[j].x)+ab(y,p[j].y)>t)break;
                else
                {nowm++;nowt-=ab(x,p[j].x)+ab(y,p[j].y);continue;}
            }
            if(ab(p[j+1].x,p[j].x)+ab(p[j+1].y,p[j].y)>nowt)break;
            else nowt-=ab(p[j+1].x,p[j].x)+ab(p[j+1].y,p[j].y),nowm++;
        }
        m=max(m,nowm);
        nowm=0,nowt=t;
        for(int j=i;j<n;j++)
        {
            if(j==i)
            {
                if(ab(x,p[j].x)+ab(y,p[j].y)>t)break;
                else
                {nowm++;nowt-=ab(x,p[j].x)+ab(y,p[j].y);continue;}
            }
            if(ab(p[j-1].x,p[j].x)+ab(p[j-1].y,p[j].y)>nowt)break;
            else nowt-=ab(p[j-1].x,p[j].x)+ab(p[j-1].y,p[j].y),nowm++;
        }m=max(m,nowm);
    }
    cout<<m<<endl;
    return 0;
}