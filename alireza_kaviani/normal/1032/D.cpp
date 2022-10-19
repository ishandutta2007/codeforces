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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

double a , b , c , x1 , y1 , x2 , y2 , ans = 1e14;
pdd p1[2] , p2[2];

double dist(pdd x , pdd y)
{
    return sqrt((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y));
}

int main()
{
    fast_io;

    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    p1[0] = {-(b * y1 + c) / a , y1};
    p1[1] = {x1 , -(a * x1 + c) / b};
    p2[0] = {-(b * y2 + c) / a , y2};
    p2[1] = {x2 , -(a * x2 + c) / b};

    for(ll i = 0 ; i < 2 ; i++)
    {
        for(ll j = 0 ; j < 2 ; j++)
        {
            ans = min(ans , dist({x1 , y1} , p1[i]) + dist(p1[i] , p2[j]) + dist({x2 , y2} , p2[j]));
        }
    }
    printf("%.10f" , min(ans , abs(x1 - x2) + abs(y1 - y2)));

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