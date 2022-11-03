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
    ll x=0,y=0;
    string st;
    cin>>st;
    for (int i=0;i<st.size();i++)
        if (st[i]=='L') x--; else
        if (st[i]=='R') x++; else
        if (st[i]=='U') y--; else
        if (st[i]=='D') y++;
    if ((st.size()%2==1)) cout<<-1; else
    {
        ll ans=0;
        x=abs(x);
        y=abs(y);
        ans+=x/2;
        x=x%2;
        ans+=y/2;
        y=y%2;
        if (x!=0 || y!=0) ans++;

        cout<<ans;
    }

}