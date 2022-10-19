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

bool good(ll n)
{
    while(n != 0ll)
    {
        if(n % 10ll == 8ll)
        {
            return true;
        }
        n /= 10ll;
    }
    return false;
}

int main()
{
    fast_io;

    ll n , ans = 0ll;
    cin >> n;

    while(ans == 0ll || good(abs(n + ans)) == false)
    {
        ans++;
    }
    cout << ans << endl;


    return 0;
}