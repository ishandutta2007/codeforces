#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
ll a[200000];
///-----------------------------------------------------------------------///
int  main()
{
    ll n,n1,n2;
    ld sum1=0,sum2=0;
    cin>>n>>n1>>n2;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for (int i=1;i<=n1;i++)
        sum1+=a[i];
    for (int i=n1+1;i<=n1+n2;i++)
        sum2+=a[i];

    ld max1=(ld)sum1/(ld)n1+(ld)sum2/(ld)n2;
    swap(n1,n2);
    sum1=0;
    sum2=0;
    for (int i=1;i<=n1;i++)
        sum1+=a[i];
    for (int i=n1+1;i<=n1+n2;i++)
        sum2+=a[i];
    ld max2=(ld)sum1/(ld)n1+(ld)sum2/(ld)n2;
    cout<<fixed<<setprecision(9)<<max(max1,max2);
}