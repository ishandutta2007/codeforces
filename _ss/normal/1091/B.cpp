#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const int maxn=int(10e3)+1;
struct toado
{
    long long x,y;
};

int n;
long long p[maxn];
toado a[maxn],b[maxn];

long long filter(long long kx, long long ky)
{
    long long t=abs(ky);
    if (ky>=0) t=t+100000000;
    t=t+abs(kx)*1000000000;
    if (kx<0) t=-t;
    return t;
}

bool bs(long long k)
{
    long long r=n,l=1,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (k==p[mid]) return false;
        else if (k<p[mid]) r=mid-1;
        else l=mid+1;
    }
    return true;
}

bool check(long long tx, long long ty)
{
    for (int i=2;i<=n;i++)
        if (bs(filter(tx-a[i].x,ty-a[i].y))) return false;
    return true;
}

int main()
{
    //freopen("s.inp","r",stdin);
    //freopen("s.out","w",stdout);
    cin>>n;
    long long r;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    for (int i=1;i<=n;i++) cin>>b[i].x>>b[i].y;
    for (int i=1;i<=n;i++)  p[i]=filter(b[i].x,b[i].y);
    //for (int i=1;i<=n;i++) cout<<p[i]<<endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (p[i]>p[j])
            {
                r=p[i];
                p[i]=p[j];
                p[j]=r;
            }
    //for (int i=1;i<=n;i++) cout<<p[i]<<endl;
    for (int i=1;i<=n;i++) if (check(a[1].x+b[i].x,a[1].y+b[i].y))
    {
        cout<<a[1].x+b[i].x<<" "<<a[1].y+b[i].y;
        break;
    }
    return 0;
}