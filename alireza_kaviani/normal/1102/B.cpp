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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e5 + 10;
ll n , k , x , p[MAXN] , col[MAXN] , cnt[MAXN] , cnt2[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        col[i] = (++cnt[p[i]]);
        if(col[i] > k)   return cout << "NO" << endl , 0;
        x = max(x , col[i]);
        cnt2[col[i]]++;
    }
    cout << "YES" << endl;

    for(ll i = 0 ; i < n ; i++)
    {
        if(cnt2[col[i]] > 1 && x < k)
        {
            cnt2[col[i]]--;
            col[i] = (++x);
        }
    }

    for(ll i = 0 ; i < n ; i++) cout << col[i] << endl;

    return 0;
}