#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll l[200005],r[200005],b[200005],pos[200005];
ll mo(ll pp)
{
    if(pp>0)return pp;
    else return -pp;
}
ll so(ll s,ll x,ll i,ll op)
{
    switch(op)
    {
        case 1:return mo(x-r[i])+mo(r[i]-l[i])+mo(l[i]-b[pos[l[i]]])+1+s;
        case 2:return mo(x-r[i])+mo(r[i]-l[i])+mo(l[i]-b[pos[l[i]]+1])+1+s;
        case 3:return mo(x-l[i])+mo(r[i]-l[i])+mo(r[i]-b[pos[r[i]]])+1+s;
        case 4:return mo(x-l[i])+mo(r[i]-l[i])+mo(r[i]-b[pos[r[i]]+1])+1+s;
    }
}
ll pa(ll x,ll s,ll i)
{
    return min(mo(x-r[i]),mo(x-l[i]))+mo(r[i]-l[i])+s;
}
int main()
{
    ll i,j;
    ll n,m,k,q,e,f;
    scanf("%lld%lld%lld%lld",&n,&m,&k,&q);
    for(i=1;i<=n;i++)r[i]=10000000;
    for(i=0;i<k;i++)
    {
        scanf("%lld%lld",&e,&f);
        l[e]=max(f,l[e]);r[e]=min(f,r[e]);
    }
    for(i=0;i<q;i++)scanf("%lld",b+i);
    sort(b,b+q);
    ll t=n;
    while(!l[t])t--;n=t;


    for(i=0;i<q;i++)
    {
        pos[b[i]]=i;
    }
    for(i=pos[b[0]];i<=m;i++)
    {
        if(!pos[i])pos[i]=pos[i-1];
    }


    b[q]=b[q-1];

/*
for(i=0;i<=n;i++)cout<<i<<':'<<l[i]<<endl;
for(i=0;i<=n;i++)cout<<i<<':'<<r[i]<<endl;i=1;
cout<<i<<'-'<<l[i]<<'-'<<pos[l[i]]<<'-'<<b[pos[l[i]]]<<endl;
for(i=0;i<=m;i++)cout<<i<<':'<<pos[i]<<endl;
//*/
    ll x1=1,x2=1,x3=1,x4=1,s1=0,s2=0,s3=0,s4=0;

    for(i=1;i<n;i++)//i F
    {
        if(l[i]==0)
        {
            if(i==1)
            {
                s1+=b[0];s2+=b[0];s3+=b[0];s4+=b[0];
                x1=x2=x3=x4=b[0];
            }
            else{s1++;s2++;s3++;s4++;}
            continue;
        }
        //l[i]

        ll p1,p2,p3,p4;
        p1=min(so(s1,x1,i,1),so(s2,x2,i,1));p1=min(p1,so(s3,x3,i,1));p1=min(p1,so(s4,x4,i,1));
#define p1 p2
        p1=min(so(s1,x1,i,2),so(s2,x2,i,2));p1=min(p1,so(s3,x3,i,2));p1=min(p1,so(s4,x4,i,2));
#undef p1
#define p1 p3
        p1=min(so(s1,x1,i,3),so(s2,x2,i,3));p1=min(p1,so(s3,x3,i,3));p1=min(p1,so(s4,x4,i,3));
#undef p1
#define p1 p4
        p1=min(so(s1,x1,i,4),so(s2,x2,i,4));p1=min(p1,so(s3,x3,i,4));p1=min(p1,so(s4,x4,i,4));
#undef p1
        s1=p1;
        s2=p2;
        s3=p3;
        s4=p4;
        x1=b[pos[l[i]]];
        x2=b[pos[l[i]]+1];
        x3=b[pos[r[i]]];
        x4=b[pos[r[i]]+1];
        /*
        printf("%lld:%lld\t%lld\t%lld\t%lld\n",i,x1,x2,x3,x4);
        printf("%lld:%lld\t%lld\t%lld\t%lld\n",i,s1,s2,s3,s4);
        cout<<mo(x1-r[i])<<mo(r[i]-l[i])<<mo(l[i]-b[pos[l[i]]])<<1<<s1<<endl;
        //printf("%lld\n",b[pos[l[i]]]);printf("%lld\n",x1);
        //b[pos[l[i]]],b[pos[l[i]]+1]*/
    }
    ll ans;
    ans=min(pa(x1,s1,n),pa(x2,s2,n));
    ans=min(ans,pa(x3,s3,n));
    ans=min(ans,pa(x4,s4,n));
    printf("%lld\n",ans);
    return 0;
}
/*
3 3 3 2
1 1
2 1
3 1
2 3

1221 432 2 4
2 1
2 1
3 4 5 6
*/