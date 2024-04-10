#include<bits/stdc++.h>
using namespace std;
int len,n;
const int N=100005;
int a[N];
bool check(int x)
{
    int now=0;
    for (int i=1;i<=n;++i)
    {
        if (now+x>a[i+1])
            return false;
        now+=x;
        if (now<a[i])
            now=a[i];
    }
    return true;
}
bool check2(int x)
{
    int now=0;
    for (int i=1;i<=n;++i)
    {
        if (now+x<a[i])
            return false;
        now+=x;
        if (now>a[i+1])
            now=a[i+1];
    }
    if (now<len)
        return false;
    return true;
}
//int pl[N],pr[N],ql[N],qr[N];
int f[N],g[N];
inline void work(int mn,int mx)
{
    //cout<<"?"<<mn<<' '<<mx<<endl;
    /*int l=0,r=0;
    for (int i=1;i<=n;++i)
    {
        int nl=l+mn,nr=r+mx;
        if (nl<a[i])
            nl=a[i];
        if (nr>a[i+1])
            nr=a[i+1];
        l=nl;
        r=nr;
        pl[i]=l;
        pr[i]=r;
    }*/
    int alllen=0;
    for (int i=1;i<=n;++i)
    {
        int det=(i==n?len:a[i])-alllen;
        if (det>=mn&&det<=mx)
        {
            f[i]=det;
            alllen+=det;
        }
        if (det<mn)
        {
            f[i]=mn;
            alllen+=mn;
        }
        if (det>mx)
        {
            alllen+=det;
            f[i]=mx;
            g[i]=det-mx;
        }
        //cout<<"!"<<i<<' '<<f[i]<<' '<<g[i]<<endl;
    }
    int sumg=0;
    for (int i=n;i;--i)
    {
        sumg+=g[i];
        int p=min(sumg,mx-f[i]);
        f[i]+=p;
        sumg-=p;
    }
    int now=0;
    for (int i=1;i<=n;++i)
    {
        printf("%d %d\n",now,now+f[i]);
        now+=f[i];
    }
}
int main()
{
    scanf("%d%d",&len,&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    a[n+1]=len;
    int l=1,r=len;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    int mn=r;
    l=1,r=len;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check2(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    int mx=l;
    work(mn,mx);
    //printf("%d\n",mx-mn);
    return 0;
}