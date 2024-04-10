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

int main()
{
    fast_io;

    ll l , r , a = -1 , b = -1 , c = -1;
    cin >> l >> r;

    for(ll i = l ; i <= r ; i++)
    {
        for(ll j = i + 1ll ; j <= r ; j++)
        {
            for(ll k = j + 1ll ; k <= r; k++)
            {
                if(__gcd(i , j) == 1ll && __gcd(j , k) == 1ll && __gcd(i , k) != 1ll && a == -1ll && b == -1ll && c == -1ll)
                {
                    a = i;
                    b = j;
                    c = k;
                }
            }
        }
    }

    if(a == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a << ends << b << ends << c << endl;
    }

    return 0;
}