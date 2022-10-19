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

    ll n , n2 , ans = 1;
    cin >> n;
    n2 = n;

    for(ll i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)
        {
            ans *= i;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    cout << ans * n << endl;

    return 0;
}