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
inline char input(){char n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1000;
ll n , ps[MAXN];
string s;

int main()
{
    fast_io;

    cin >> n >> s;
    for(ll i = 0 ; i < n ; i++) ps[i] = s[i] - 48;
    partial_sum(ps , ps + n , ps);

    if(ps[n - 1] == 0)  return cout << "YES" << endl , 0;

    for(ll i = 1 ; i <= 1e4 ; i++)
    {
        ll cnt = 0 , last = 0;
        for(ll j = 0 ; j < n ; j++)
        {
            if(ps[j] / i == cnt + 1 && (ps[j] - last) % i == 0)
            {
                cnt ++;
                last = ps[j];
            }
        }
        if(ps[n - 1] == last && cnt >= 2)
        {
            return cout << "YES" << endl , 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}