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

mt19937 random(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353;

ll n , l = -1 , r = INF , cnt = 0 , GCD , mark[MAXN] , p[MAXN];
vector<ll> vec;

ll check(ll x)
{
    cnt++;
    cout << "> " << x << endl;
    return (input() == 0);
}

int main()
{
    fast_io;

    cin >> n;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(check(mid))  r = mid;
        else            l = mid;
    }

    mark[n] = 1;
    vec.push_back(r);

    for(ll i = 0 ; i < min(n - 1 , 60 - cnt) ; i++)
    {
        ll ind = random() % n + 1;
        while(mark[ind])
            ind = random() % n + 1;

        mark[ind] = 1;
        cout << "? " << ind << endl;
        vec.push_back(input());
    }

    GCD = abs(vec[0] - vec[1]);
    for(ll i = 0 ; i < vec.size() ; i++)
    {
        for(ll j = 0 ; j < vec.size() ; j++)
        {
            GCD = __gcd(GCD , abs(vec[i] - vec[j]));
        }
    }

    cout << "! " << r - GCD * (n - 1) << sep << GCD << endl;

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