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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , x , y , nx , ny , l , r , l1 , r1 , mid;
string s;

void st(char c , ll add)
{
    if(c == 'R')    nx += add;
    if(c == 'L')    nx -= add;
    if(c == 'U')    ny += add;
    if(c == 'D')    ny -= add;
}

ll check(ll m)
{
    l1 = 0 , r1 = m - 1 , nx = 0 , ny = 0;
    for(ll i = r1 + 1 ; i < n ; i++)    st(s[i] , 1);

    while(r1 < n)
    {
        if(abs(nx - x) + abs(ny - y) <= m && m % 2 == (abs(nx - x) + abs(ny - y)) % 2)  return 1;
        st(s[l1++] , 1);
        st(s[++r1] , -1);
    }
    return 0;
}

int main()
{
    fast_io;

    cin >> n >> s >> x >> y;

    if(!check(n))   return cout << -1 << endl , 0;

    l = -1 , r = n;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(check(mid))  r = mid;
        else            l = mid;
    }
    cout << r << endl;

    return 0;
}
/*
todo :
    1- set consants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea
    5- don't forget printf and scanf can help you in your code speed
*/