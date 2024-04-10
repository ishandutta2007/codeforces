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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

queue<ll> q1 , q2;
ll n , k1 , k2;

int main()
{
    fast_io;

    cin >> n >> k1;
    for(ll i = 0 ; i < k1 ; i++)   q1.push(input());
    cin >> k2;
    for(ll i = 0 ; i < k2 ; i++)   q2.push(input());

    for(ll i = 0 ; i <= 1e5 ; i++)
    {
        if(q1.size() == 0)  return cout << i << sep << 2 << endl , 0;
        if(q2.size() == 0)  return cout << i << sep << 1 << endl , 0;
        ll x = q1.front() , y = q2.front();
        q1.pop();
        q2.pop();
        if(x > y)
        {
            q1.push(min(x , y));
            q1.push(max(x , y));
        }
        else
        {
            q2.push(min(x , y));
            q2.push(max(x , y));
        }
    }
    cout << -1 << endl;

    return 0;
}