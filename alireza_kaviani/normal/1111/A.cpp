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

string s , t;
map<char , ll> mp;

int main()
{
    fast_io;

    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;

    cin >> s >> t;
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(mp[s[i]])    s[i] = 'a';
        else            s[i] = 'b';
    }
    for(ll i = 0 ; i < t.size() ; i++)
    {
        if(mp[t[i]])    t[i] = 'a';
        else            t[i] = 'b';
    }
    if(s == t)  cout << "Yes" << endl;
    else        cout << "No" << endl;

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