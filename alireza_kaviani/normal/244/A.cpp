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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e4;
vector<ll> ans[MAXN];
ll n , k , cnt , p[MAXN] , mark[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    for(ll i = 0 ; i < k ; i++)
    {
        cin >> p[i];
        ans[i].push_back(p[i]);
        mark[p[i]] = 1;
    }

    for(ll i = 1 ; i <= n * k ; i++)
    {
        if(!mark[i])
        {
            ans[cnt / (n - 1)].push_back(i);
            cnt++;
        }
    }

    for(ll i = 0 ; i < k ; i++ , cout << endl)
    {
        for(ll j : ans[i])  cout << j << ends;
    }

    return 0;
}