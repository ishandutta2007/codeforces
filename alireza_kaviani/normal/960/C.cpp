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
inline int input(){int n; cin >> n ; return n;}

int main()
{
    fast_io;

    ll x , d;
    cin >> x >> d;

    vector<ll> ans;
    ll t = 1;
    while(x)
    {
        ll p = 1;
        while((1LL << p+1)-1 <= x)    p++;
        x -= (1LL << p)-1;
        while(p--)  ans.push_back(t);
        t += d+1;
    }
    cout << ans.size() << endl;
    for(ll i : ans)
    {
        cout << i << ends;
    }

    return 0;
}