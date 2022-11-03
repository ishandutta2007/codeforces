#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
///-------------------///
ll a[1000000];

///-------------------///
main()
{
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=2;i<=n;i++)
        cout<<a[i]+a[i-1]<<' ';
    cout<<a[n];

}