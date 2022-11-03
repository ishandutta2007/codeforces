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
    ll x,y,ans=0;
    cin>>x>>y;
    if (x>y) swap(x,y);
    ll a=x,b=x,c=x;
    while (!(a==y && b==y && c==y))
    {
        //cout<<a<<' '<<b<<' '<<c<<'\n';
        if (a<=b && a<=c)
        {
            a=min(b+c-1,y);
        } else
        if (b<=a && b<=c)
        {
            b=min(a+c-1,y);
        } else
        if (c<=a && c<=b)
        {
            c=min(b+a-1,y);
        }
        ans++;
    }
    cout<<ans;

}