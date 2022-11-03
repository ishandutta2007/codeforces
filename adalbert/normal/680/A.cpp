#include <bits/stdc++.h>;
#define fin freopen("cakes.in","r",stdin)
#define fout freopen("cakes.out","w",stdout)
using namespace std;
long long t1,t2,t3,t4,t5,mx,a[1000],k;

int main()
{
   // fin;
    //fout;
    cin>>t1>>t2>>t3>>t4>>t5;
    for (int i=1; i<=101 ;i++)
    {
        k=0;
        if (t1==i) k++;
        if (t2==i) k++;
        if (t3==i) k++;
        if (t4==i) k++;
        if (t5==i) k++;
        if (k==2) a[i]=2*i; else
            if (k>2) a[i]=3*i;
    }
    for (int i=1;i<=101;i++)
        if (a[i]>mx)
        {
            mx=a[i];
         //   cout<<i<<' '<<a[i];
        }
    cout<<t1+t2+t3+t4+t5-mx;
}