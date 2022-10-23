#include <iostream>
#include <fstream>
using namespace std;

long long bs(long long t,long long l,long long r,long long h,long long x,long long n)
{
    long long mid,tp=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (mid<(t-mid*x) || (t-mid*x)>h) l=mid+1; else
        if (mid-(t-mid*x)<=n-h && (t-mid*x)<=h)
        {
            l=mid+1;
            tp=mid;
        } else r=mid-1;
    }
    return tp;
}

int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    long long n,l,r,k,h,t,m2=-1,j;
    cin>>n>>l>>r>>k;
    if (r>=l) h=r-l+1; else h=n-l+1+r;
    if (k<h)
    {
        cout<<-1;
        return 0;
    }
    if (n<=1000000)
    {
        for (int m=n;m>=0;m--)
        {
            t=k%(n+m);
            if ((t>=max(h,m-n+2*h) && t<=min(m+h,2*h)) || (t==0 && ((l==1 && r==n) || (l-1==r))))
            {
                m2=m;
                break;
            }
        }
        k=k+1;
        for (int m=n;m>=1;m--)
        {
            t=k%(n+m);
            if ((t>=max(h+1,m-n+2*h) && t<=min(m+h,2*h)) || (t==0 && ((l==1 && r==n) || (l-1==r))))
            {
                if (m>m2) m2=m;
                break;
            }
        }
        cout<<m2;
    }
    else
    {
        long long m3;
        if (k<=2*h) m2=k-h+(n-h);
        for (int i=1;i<=k/n;i++)
        {
            t=k-n*i-h;
            m3=bs(t,0,n,h,i,n);
            if (m3!=-1)
            {
                if (m3>m2) m2=m3;
                break;
            }
        }
        k=k+1;
        if (k<=2*h) m2=k-h+(n-h);
        for (int i=1;i<=k/n;i++)
        {
            t=k-n*i-h;
            m3=bs(t,0,n,h,i,n);
            if (m3>0)
            {
                j=t%m3;
                if (t%m3==0)
                {
                    m3--;
                    j=i;
                }
                if (m3-j<=n-h && j<=h)
                {
                    if (m3>m2) m2=m3;
                    break;
                }
            }
        }
        cout<<m2;
    }
    return 0;
}