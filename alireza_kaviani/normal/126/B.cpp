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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e6 + 10;
ll n , k , ans = -1 , lps[MAXN] , mark[MAXN];
string s;

void FindLps()
{
    ll len;
    lps[0] = len = 0;

    for(int i = 1 ; i < n ; i++)
    {
        while(len > 0 && s[i] != s[len])    len = lps[len - 1];
        if(s[i] == s[len])  len++;
        lps[i] = len;
    }
    return;
}

int main()
{
    fast_io;

    cin >> s;
    n = s.size();

    FindLps();
    k = lps[n - 1];
    while(k)
    {
        mark[k] = 1;
        k = lps[k - 1];
    }
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(mark[lps[i]])    ans = max(ans , lps[i]);
    }
    if(ans == -1)   cout << "Just a legend" << endl;
    else    cout << s.substr(0 , ans) << endl;

    return 0;
}