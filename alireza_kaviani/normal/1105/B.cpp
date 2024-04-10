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

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , cnt = 1 , ans , mx , k;
string s;

int main()
{
    fast_io;

    cin >> n >> k >> s;
    for(ll j = 0 ; j < 26 ; j++)
    {
        ans = 0 , cnt = 1;
        if(s[0] == (char)(97 + j) && k == 1)
        {
            cnt = 0;
            ans = 1;
        }
        for(ll i = 1 ; i < n ; i++)
        {
            if(s[i] == s[i - 1])    cnt++;
            else                    cnt = 1;
            if(cnt == k && s[i] == (char)(97 + j))
            {
                cnt = 0;
                ans++;
            }
        }
        mx = max(mx , ans);
    }
    cout << mx << endl;

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