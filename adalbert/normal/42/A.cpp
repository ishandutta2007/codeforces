#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 dslfljldfjsgh
#define fin freopen("mantan.in","r",stdin)
#define fout freopen("mantan.out","w",stdout)
///-----------------------------------------------------------------------///

///-----------------------------------------------------------------------///
long double  a[10000],b[10000];
///-----------------------------------------------------------------------///
int main()
{
    ll n,v,mn;
    cin>>n>>v;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    long double l=0;
    long double r=100000000;
    for (int i=1;i<=10000;i++)
    {
        long long k=0;
        long double sum=0;
        long double d=(l+r)/2;
        for (int i=1;i<=n;i++)
        {
            if ((a[i]*d-b[i])>0.0000001) k++;
            sum+=a[i]*d;
        }
        if ((sum-v)>0.00000001 || k!=0) r=d; else l=d;
    }
    long double sum=0;
    for (int i=1;i<=n;i++)
        sum+=a[i]*l;
    cout<< fixed<< setprecision (9) <<sum;
}