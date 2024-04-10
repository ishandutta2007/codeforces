#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+10;
ll n,a[maxn],k;
int main()
{
    cin>>n>>k;
    for (ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    ll t=a[(n+1)/2],s=t,sl=1;
    for (ll i=(n+1)/2+1;i<=n;i++)
    {
        if (sl*a[i]-s<=k)
        {
            t=a[i];
            s+=a[i];
            sl++;
        }
        else
        {
            cout<<t+(k-(sl*t-s))/sl;
            return 0;
        }
    }
    cout<<t+(k-(sl*t-s))/sl;
    return 0;
}