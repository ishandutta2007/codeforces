#include <iostream>
#include <fstream>
using namespace std;
const int maxl=int(1e6)+2;
long long tt=int(1e9);
long long n,b,a[maxl],c[maxl],d=0;
int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    cin>>n>>b;
    for (long long i=2;i*i<=b;i++)
        if (b%i==0)
        {
            d++;
            a[d]=i;
            while (b%i==0)
            {
                b=b/i;
                c[d]++;
            }
        }
    if (b>1)
    {
        d++;
        a[d]=b;
        c[d]=1;
    }
    long long x,d2,m=tt*tt*5;;
    for (long long i=1;i<=d;i++)
    {
        x=a[i];
        d2=n/x;
        while (x<=n/a[i])
        {
            x=x*a[i];
            d2=d2+n/x;
        }
        if (d2/c[i]<m) m=d2/c[i];
    }
    cout<<m;
    //for (int i=1;i<=d;i++) cout<<a[i]<<" "<<c[i]<<endl;
    return 0;
}