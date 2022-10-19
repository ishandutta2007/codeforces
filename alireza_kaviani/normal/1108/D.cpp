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

const ll MAXN = 1e5,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , cnt;
string s , ans;
map<char , ll> ind;
map<ll , char> ind2;

int main()
{
    fast_io;
    ind['R'] = 1;
    ind['G'] = 2;
    ind['B'] = 3;

    ind2[1] = 'R';
    ind2[2] = 'G';
    ind2[3] = 'B';

    cin >> n >> s;
    ans = string(1 , s[0]);

    s += '.';
    for(ll i = 1 ; i < n ; i++)
    {
        if(s[i] == ans[ans.size() - 1])
        {
            cnt++;
            char t = 'R';
            for(ll j = 1 ; j <= 3 ; j++)
            {
                char c = ind2[j];
                if(c != s[i + 1] && c != ans[ans.size() - 1])   t = c;
            }
            ans += string(1 , t);
        }
        else    ans += string(1 , s[i]);
    }
    cout << cnt << sep << ans << endl;

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