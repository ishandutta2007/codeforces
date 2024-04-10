#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
ll n,k,a[100000];
///----------------procedures_and_functions------------///

///---------------------program_start-------------------///
int main()
{
    ll ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=2;i<=n;i++)
    {
        ans+=max((ll)0,k-(a[i]+a[i-1]));
        a[i]+=max((ll)0,k-(a[i]+a[i-1]));
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}