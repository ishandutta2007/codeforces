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

ll n , t , p , q , cnts[MAXN] , cntb[MAXN];
char d;
vector<pll> s , b , S;

int main()
{
    fast_io;

    cin >> n >> t;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> d >> p >> q;
        if(d == 'B')    cntb[p] += q;
        else            cnts[p] += q;
    }

    for(ll i = 0 ; i < MAXN ; i++)
    {
        if(cntb[i] != 0)    b.push_back({i , cntb[i]});
        if(cnts[i] != 0)    s.push_back({i , cnts[i]});
    }

    sort(all(b) , greater<pll>());
    sort(all(s));
    for(ll i = 0 ; i < min(t , ll(s.size())) ; i++)
    {
        S.push_back(s[i]);
    }
    sort(all(S) , greater<pll>());
    for(ll i = 0 ; i < min(t , ll(S.size())) ; i++)
    {
        cout << "S" << sep << S[i].X << sep << S[i].Y << endl;
    }
    for(ll i = 0 ; i < min(t , ll(b.size())) ; i++)
    {
        cout << "B" << sep << b[i].X << sep << b[i].Y << endl;
    }

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