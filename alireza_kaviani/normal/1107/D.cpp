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

const ll MAXN = 5410;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , ans , mx , mn , st = INF , c , a[MAXN][MAXN];
string s[MAXN];
map<string , string> mp;

void SET(ll ind , string s)
{
    for(ll i = 0 ; i < s.size() ; i++)
    {
        string t = mp[string(1 , s[i])];
        for(ll j = i * 4 ; j < (i + 1) * 4 ; j++)
        {
            a[ind][j] = t[j % 4] - 48;
        }
    }
}

int main()
{
    fast_io;
    mp["0"] = "0000";
    mp["1"] = "0001";
    mp["2"] = "0010";
    mp["3"] = "0011";
    mp["4"] = "0100";
    mp["5"] = "0101";
    mp["6"] = "0110";
    mp["7"] = "0111";
    mp["8"] = "1000";
    mp["9"] = "1001";
    mp["A"] = "1010";
    mp["B"] = "1011";
    mp["C"] = "1100";
    mp["D"] = "1101";
    mp["E"] = "1110";
    mp["F"] = "1111";

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        SET(i , s[i]);
    }
    st = n;

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            if(i + 1 < n && a[i][j] != a[i + 1][j]) st = __gcd(st , i + 1);
            if(j + 1 < n && a[i][j] != a[i][j + 1]) st = __gcd(st , j + 1);
        }
    }

    cout << st << endl;

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