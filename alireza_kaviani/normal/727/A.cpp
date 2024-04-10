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

ll a , b;
vector<ll> vec;

int main()
{
    fast_io;

    cin >> a >> b;
    while(b > a)
    {
        vec.push_back(b);
        if(b % 2 == 0)   b /= 2;
        else
        {
            if(b % 10 != 1)  return cout << "NO" << endl , 0;
            b /= 10;
        }
    }
    if(a != b)  return cout << "NO" << endl , 0;
    vec.push_back(a);
    cout << "YES" << endl << vec.size() << endl;;
    for(ll i = vec.size() - 1 ; i >= 0 ; i--)   cout << vec[i] << sep;


    return 0;
}