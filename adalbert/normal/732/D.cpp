#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
ll n,m,a[1000000],day[1000000],last[1000000],use[1000000];
///----------------procedures_and_functions------------///
bool check(ll t)
{
    //cout<<t<<'\n';
    for (int i=1;i<=m;i++)
    {
        last[i]=0;
        use[i]=0;
    }
    for (int i=1;i<=t;i++)
        last[a[i]]=i;
    ll kilk=0;
    for (int i=1;i<=t;i++)
    {
        //cout<<kilk<<' '<<a[i]<<'\n';
        if (i!=last[a[i]] || a[i]==0) kilk++; else
        {

            if (day[a[i]]>kilk) return(0); else
            {
                kilk-=day[a[i]];
                use[a[i]]=1;
            }
        }
    }

    //cout<<'\n';
    for (int i=1;i<=m;i++) if (!use[i]) return(0);
    return(1);
}
///---------------------program_start-------------------///
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>day[i];
    ll l=0;
    ll r=n+1;
    while (r-l>1)
    {
        ll d=(l+r)/2;
        if (check(d)) r=d; else l=d;
   //     cout<<l<<' '<<r<<'\n';
    }
    if (check(l)) cout<<l; else
        if (r<=n) cout<<r; else cout<<-1;
}