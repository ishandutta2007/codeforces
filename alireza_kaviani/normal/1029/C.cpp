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

map<pii , bool> mp;

int main()
{
    fast_io;

    int n;
    cin >> n;

    int l[n] , r[n];
    pii seg[n];
    for(int i = 0 ; i < n ; i++)    cin >> l[i] >> r[i] , seg[i] = {l[i] , r[i]} , mp[seg[i]]++ ;

    sort(l , l + n , greater<int> ());
    sort(r , r + n);

    int ans = r[0] - l[0];
    for(int i = 0 ; i < n ; i++)
    {
        int x = 0 , y = 0;
        if(seg[i].X == l[0])    x++;
        if(seg[i].Y == r[0])    y++;
        ans = max(ans , r[y] - l[x]);
    }
    cout << max(0 , ans) << endl;

    return 0;
}