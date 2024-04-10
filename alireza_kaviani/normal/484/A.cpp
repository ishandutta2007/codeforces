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

ll get(ll l , ll r)
{
    ll ans = 0 , t = 0;
    for(int i = 63 ; i >= 0 ; i--)
    {
        if(t)   ans |= (1LL << i);
        else if(((1LL << i) & l) != ((1LL << i) & r))   t = 1;
        else    ans |= ((1LL << i) & l);
    }
    return (__builtin_popcountll(ans) >= __builtin_popcountll(r) ? ans : r);
}

int main()
{
    fast_io;

    int q;
    cin >> q;

    while(q--)
    {
        ll l , r;
        cin >> l >> r;
        cout << get(l , r) << endl;
    }

    return 0;
}