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
inline pll input(){ll x , y ; cin >> x >> y ; return {y , x};}

int main()
{
    fast_io;

    ll n , r , avg , sum = 0 , i = 0 , ans = 0;
    cin >> n >> r >> avg;

    vector<pll> vec(n);
    for(i = 0 ; i < n ; i++)    { vec[i] = input(); sum += vec[i].Y;}
    Sort(vec);

    avg = n * avg - sum;    i = 0;
    while(avg > 0)
    {
        ll k = min(avg , r - vec[i].Y);
        avg -= k;
        ans += k * vec[i].X;
        i++;
    }
    cout << ans << endl;

    return 0;
}