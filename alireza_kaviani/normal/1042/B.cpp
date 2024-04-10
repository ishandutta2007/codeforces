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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

map<string , ll> mn;

int main()
{
    fast_io;

    mn["A"] = mn["B"] = mn["C"] = mn["AB"] = mn["AC"] = mn["BC"] = mn["ABC"] = 1e9;
    ll n;
    cin >> n;

    for(ll i = 0 ; i < n ; i++)
    {
        ll c;
        string s;
        cin >> c >> s;
        sort(all(s));
        mn[s] = min(mn[s] , c);
    }

    mn["A"] = min({mn["A"] , mn["AB"] , mn["AC"] , mn["ABC"]});
    mn["B"] = min({mn["B"] , mn["AB"] , mn["BC"] , mn["ABC"]});
    mn["C"] = min({mn["C"] , mn["BC"] , mn["AC"] , mn["ABC"]});
    mn["AB"] = min(mn["AB"] , mn["ABC"]);
    mn["BC"] = min(mn["BC"] , mn["ABC"]);
    mn["AC"] = min(mn["AC"] , mn["ABC"]);

    ll ans = 1e9;
    ans = min(ans , mn["A"] + mn["B"] + mn["C"]);
    ans = min(ans , mn["A"] + mn["BC"]);
    ans = min(ans , mn["AB"] + mn["C"]);
    ans = min(ans , mn["AC"] + mn["B"]);
    ans = min(ans , mn["ABC"]);
    cout << (ans == ll(1e9) ? -1 : ans) << endl;

    return 0;
}