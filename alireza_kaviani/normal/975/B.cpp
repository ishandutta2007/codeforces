#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll solve(ll t , ll b[])
{
    ll a[14];
    for(int i = 0; i < 14 ; i++)
    {
        a[i] = b[i];
    }
    ll cnt = a[t] , st = t + 1 , ans = 0 , i = 0, div = cnt / 14 , mod = cnt % 14;
    a[t] = 0;
    while(1)
    {
        if(cnt == 0)
        {
            break;
        }
        if(i < mod)
        {
            a[st % 14] += div + 1;
            cnt -= div + 1;
        }
        else
        {
            a[st % 14] += div;
            cnt -= div;
        }
        st++;
        i++;
    }

    for(int i = 0; i < 14 ; i++)
    {
        if(a[i] % 2 == 0 && a[i] != 0)
        {
            ans+= a[i];
        }
    }
    return ans;
}

int main()
{
    fast_io;

    ll a[14] , ans = 0;
    for(ll i = 0; i < 14 ; i++)
    {
        cin >> a[i];
    }

    for(ll i = 0 ;i < 14 ; i++)
    {
        ans = max(ans , solve(i , a));
    }
    cout << ans << endl;

    return 0;
}