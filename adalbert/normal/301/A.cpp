#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///------------------------------------------------------------///
ll a[100000];
///------------------------------------------------------------///

///------------------------------------------------------------///
int main()
{
    ll n;
    cin>>n;
    ll k=0,sum=0;
    for (int i=1;i<=n*2-1;i++)
    {
        cin>>a[i];
        if (a[i]<0) k++;
        a[i]=abs(a[i]);
    }
    sort(a+1,a+(2*n-1)+1);
    if ((n%2==0 && k%2==0)|| n%2)
    {
        sum=0;
        for (int i=1;i<=n*2-1;i++) sum+=a[i];
        cout<<sum;
    } else
    {
        sum=0;
        sum-=a[1];
        for (int i=2;i<=n*2-1;i++) sum+=a[i];
        cout<<sum;
    }
}