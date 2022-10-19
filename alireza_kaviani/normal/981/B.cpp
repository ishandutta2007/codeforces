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

map<string , ll> mp;

int main()
{
    fast_io;

    ll n , m , ans = 0;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        string s;
        ll x;
        cin >> s >> x;
        mp[s] = x;
    }

    cin >> m;
    for(int i = 0 ; i < m; i++)
    {
        string s;
        ll y;
        cin >> s >> y;
        mp[s] = max(mp[s] , y);
    }

    for(map<string , ll>::iterator it = mp.begin() ; it != mp.end() ; it++)
    {
        ans += it -> Y;
    }
    cout << ans << endl;

    return 0;
}