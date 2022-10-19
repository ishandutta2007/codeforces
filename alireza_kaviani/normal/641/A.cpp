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

const ll MAXN = 1e5 + 10;
ll n , now , nxt , d[MAXN] , mark[MAXN];
string s;

int main()
{
    fast_io;

    cin >> n >> s;
    for(ll i = 0 ; i < n ; i++) cin >> d[i];

    while(!mark[now])
    {
        mark[now] = 1;
        nxt = now + d[now] * (s[now] == '>' ? 1 : -1);
        if(nxt < 0 || nxt >= n) return cout << "FINITE" << endl , 0;
        now = nxt;
    }
    cout << "INFINITE" << endl;

    return 0;
}