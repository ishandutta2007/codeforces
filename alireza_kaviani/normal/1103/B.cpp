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
//#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 random(chrono::steady_clock::now().time_since_epoch().count());
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 30;
const ll MOD = 1e9 + 7; // 998244353;

ll x , l , r , mid;
string s;

ll check(ll x , ll y)
{
    cout << "? " << x << sep << y << endl;
    cin >> s;
    return (s == "x");
}

void MAIN()
{
    cin >> s;
    if(s != "start")    exit(0);

    cout << "? " << 0 << sep << 1 << endl;
    cin >> s;
    if(s == "x")
    {
        cout << "! 1" << endl;
        MAIN();
    }

    x = 1;
    while(!check(x , x * 2))    x *= 2;

    l = x , r = x * 2;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(check(l , mid))  r = mid;
        else                l = mid;
    }
    cout << "! " << r << endl;
    MAIN();
}

int main()
{
    fast_io;
    set_random;

    MAIN();

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/