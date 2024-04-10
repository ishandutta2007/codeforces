#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

void solve(ll l , ll r , ll z = 1)
{
    if(r - l <= 2)
    {
        for(ll i = 0 ; i < r - l ; i++) cout << z << ends;
        cout << z * (r - l + 1) << ends;
        return;
    }
    for(ll i = 0 ; i < (r + 1) / 2 ; i++)   cout << z << ends;
    solve(1 , r / 2 , z * 2);
}

int main()
{
    fast_io;

    ll n;
    cin >> n;
    solve(1 , n);

    return 0;
}