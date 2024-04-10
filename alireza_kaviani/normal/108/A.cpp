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

string s;
vector<string> vec;

int main()
{
    fast_io;

    for(ll i = 0 ; i < 24 ; i++)
    {
        if(i % 10 >= 6) continue;
        string x = string(1 , i / 10 + 48) + string(1 , i % 10 + 48) , y = string(1 , i % 10 + 48) + string(1 , i / 10 + 48);
        vec.push_back(x + ":" + y);
    }

    cin >> s;
    if(upper_bound(all(vec) , s) == vec.end())  return cout << "00:00" << endl , 0;
    cout << *upper_bound(all(vec) , s);

    return 0;
}