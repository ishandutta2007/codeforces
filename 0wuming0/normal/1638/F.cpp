#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll h[10005];
int l[10005],r[10005];
ll dpl[10005],dpr[10005];
int stk[10005],nn;
int stk2[10005],nn2;
ll save[10005],save2[10005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        while(nn&&h[stk[nn-1]]>=h[i])nn--;
        if(nn)l[i]=stk[nn-1];
        else l[i]=0;
        dpl[i]=save[nn]=(i-l[i])*h[i];
        for(int j=0;j<nn;j++)
        {
            save[j]+=h[stk[j]];
            dpl[i]=max(dpl[i],save[j]);
        }
        stk[nn++]=i;
    }
    nn=0;
    for(int i=n;i;i--)
    {
        r[i]=i;
        while(nn&&h[stk[nn-1]]>=h[i])nn--;
        if(nn)r[i]=stk[nn-1];
        else r[i]=n+1;
        save[nn]=0;
        dpr[i]=save[nn]=(r[i]-i)*h[i];
        for(int j=0;j<nn;j++)
        {
            save[j]+=h[stk[j]];
            dpr[i]=max(dpr[i],save[j]);
        }
        stk[nn++]=i;
    }
    nn=0;
    //for(int i=1;i<=n;i++)printf("%lld%c",dpl[i]," \n"[i==n]);
    //for(int i=1;i<=n;i++)printf("%lld%c",dpr[i]," \n"[i==n]);
    for(int i=2;i<=n;i++)dpl[i]=max(dpl[i],dpl[i-1]);
    for(int i=n-1;i;i--)dpr[i]=max(dpr[i],dpr[i+1]);
    for(int i=1;i<=n;i++)ans=max(ans,dpl[i-1]+dpr[i]);
    for(int i=1;i<=n;i++)
    {//cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        int len=r[i]-l[i]-1;
        ll val,sq=len*h[i];
        for(int now=l[i];now;now=l[now])
        {
            val=(r[i]-l[now]-1)*h[now];
            while(nn&&save[nn-1]<=val)nn--;
            stk[nn]=now;
            save[nn++]=val;
        }
        for(int now=r[i],k;now!=n+1;now=r[now])
        {
            val=(r[now]-l[i]-1)*h[now];
            while(nn2&&save2[nn2-1]<=val)nn2--;
            stk2[nn2]=now;
            save2[nn2++]=val;
        }//cout<<"<<"<<nn<<endl;for(int i=0;i<nn;i++)printf("%d%c",stk[i]," \n"[i==nn-1]);
        //for(int i=0;i<nn;i++)printf("%lld%c",save[i]," \n"[i==nn-1]);
        //cout<<"<<"<<nn2<<endl;for(int i=0;i<nn2;i++)printf("%d%c",stk2[i]," \n"[i==nn2-1]);
        //for(int i=0;i<nn2;i++)printf("%lld%c",save2[i]," \n"[i==nn2-1]);
        for(int a=nn-1,b=0;a>=0;a--)
        {
            while(b<nn2&&h[stk[a]]+h[stk2[b]]>h[i])b++;//cout<<"<<"<<stk[a]<<" "<<stk2[b]<<"  "<<" "<<save[a]+save2[b]<<endl;
            if(b==nn2)break;
            ans=max(ans,save[a]+save2[b]);
        }
        nn=nn2=0;
        for(int now=l[i];now;now=l[now])
        {
            stk[nn++]=now;
        }
        for(int now=r[i];now!=n+1;now=r[now])
        {
            stk2[nn2++]=now;
        }
        for(int a=0,b=0;a<nn&&b<nn2;)
        {
            if(h[stk[a]]<h[stk2[b]])
            {//cout<<"<<"<<stk[a]<<" "<<stk2[b]<<"  "<<len*h[i]+(r[stk2[b]]-l[stk[a]]-1-len)*h[stk[a]]<<endl;
                ans=max(ans,sq+(r[stk2[b]]-l[stk[a]]-1-len)*h[stk[a]]);
                if(b==nn2-1)a++;
                else b++;
            }
            else
            {//cout<<"<<"<<stk[a]<<" "<<stk2[b]<<"  "<<len*h[i]+(r[stk2[b]]-l[stk[a]]-1-len)*h[stk2[b]]<<endl;
                ans=max(ans,sq+(r[stk2[b]]-l[stk[a]]-1-len)*h[stk2[b]]);
                if(a==nn-1)b++;
                else a++;
            }
            //while(b&&h[stk[a]]+h[stk2[b]]>h[i])b--;
            //if(!b)break;
            //ans=max(ans,save[a]+save2[b]);
        }
        for(int a=nn-1,b=0;a>=0;a--)
        {
            while(b<nn2&&h[stk[a]]+h[stk2[b]]>=h[i])b++;
            if(b)ans=max(ans,sq+h[stk[a]]*(l[i]-l[stk[a]])+(h[i]-h[stk[a]])*(r[stk2[b-1]]-r[i]));
        }
        for(int a=0,b=nn2-1;b>=0;b--)
        {
            while(a<nn&&h[stk[a]]+h[stk2[b]]>=h[i])a++;
            if(a)ans=max(ans,sq+(h[i]-h[stk2[b]])*(l[i]-l[stk[a-1]])+h[stk2[b]]*(r[stk2[b]]-r[i]));
        }
        nn=nn2=0;
    }
    cout<<ans<<endl;
    return 0;
}
/*
8
3 3 3 7 7 4 4 4

8
3 3 3 7 7 5 5 5

9
3 3 3 7 7 5 5 5 5

9
3 3 3 3 7 7 5 5 5

8
3 3 3 8 8 4 4 4

8
3 3 3 7 7 4 4 35

8
3 3 3 7 7 3 3 3

10
1 2 3 4 5 5 4 3 2 1

11
2 2 3 4 5 5 4 3 1 1 1

8
1 3 4 5 7 2 4 5

5
5 2 2 4 5

10
3 3 3 4 10 10 10 10 10 5
*/