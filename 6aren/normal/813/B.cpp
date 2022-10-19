#include <bits/stdc++.h>

using namespace std;

long long n, a[10010],b[10010],c[10010],d[10010],m,t,i,j,x,y,l,r,p;

int main()
{
 cin >>x>>y>>l>>r;
 a[0]=1;b[0]=1;
 for (i=1;;i++)
 {
     if (trunc(1e18-1)/x<a[i-1])
     {
         break;
     }
    else
    {
        a[i]=a[i-1]*x;

    }
 }
 for (i=1;;i++)
 {

     if (trunc(1e18-1)/y<b[i-1])
     {
         break;
     }
     else
     {
         b[i]=b[i-1]*y;
     }

 }

 t=0;
 for (i=0;i<=trunc(log((1e18))/log(x));i++)
 {


         p=trunc(log((1e18)-a[i])/log(y));
     for (j=0;j<=p;j++)
     {
         c[t]=a[i]+b[j];
         t++;
     }


 }
 sort(c+0,c+t);

m=t+1;
 for (i=0;i<=t-1;i++)
 {
     if (c[i]>=l && c[i]<=r)
     {
         m=i;
        break;
     }
 }

if (m==t+1)
{
    cout << r-l+1;
}
if (m<t+1)
{
    for (i=t-1;;i--)
    {
        if (c[i]>=l && c[i]<=r)
        {
            n=i; break;
        }
    }
    d[1]=c[m]-l;
d[n-m+2]=r-c[n];
for (i=2;i<=n-m+1;i++)
{
    d[i]=c[m+i-1]-c[m+i-2]-1;
}
    sort(d+1,d+n-m+3);
    cout << d[n-m+2];
}

}