#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.iut","w",stdout);
    int n,d=0,a[101],t=1,kq,m=0;
    cin>>n;
    if (n==1)
    {
        cout<<1<<" "<<0;
        return 0;
    }
    int i=2;
    while (i<=n)
    {
        while (i<=n && n%i!=0) i++;
        d++;
        a[d]=0;
        t=t*i;
        while (n%i==0)
        {
            a[d]++;
            n=n/i;
        }
    }
    i=2;
    kq=0;
    for (i=1;i<=d;i++)
        for (int j=i+1;j<=d;j++)
            if (a[i]!=a[j])
    {
        kq=1;
        break;
    }
    for (int i=1;i<=d;i++) m=max(m,a[i]);
    d=0;
    n=1;
    while (n<m)
    {
        n=n*2;
        d++;
    }
    if (n>a[1]) kq=1;
    cout<<t<<" "<<kq+d;
    return 0;
}