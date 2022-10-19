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

ll n , m;
vector<ll> ans;

int main()
{
    fast_io;

    cin >> n;
    while(n)
    {
        string x , y;
        stringstream ss;
        ss << n;
        ss >> x;
        for(ll i = 0 ; i < x.size() ; i++)
        {
            if(x[i] != '0') y += "1";
            else    y += "0";
        }
        m = 0;
        for(ll i = 0 ; i < y.size() ; i++) m = m * 10 + y[i] - 48;
        ans.push_back(m);
        n -= m;
    }
    Sort(ans);
    cout << ans.size() << endl;
    for(ll i : ans) cout << i << sep;

    return 0;
}