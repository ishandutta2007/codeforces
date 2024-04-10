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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    ll n , k , ans = 0 , ans2 = 0;
    cin >> n >> k;

    vector<ll> a(k);
    for(ll i=0;i<k;i++)
    {
        ll t;
        cin >> t;
        a[i] = n%t;
        if(a[i] <= a[ans])
        {
            ans = i;
            ans2 = t;
        }
    }

    cout << ans + 1 << ends << n / ans2 << endl;

    return 0;
}