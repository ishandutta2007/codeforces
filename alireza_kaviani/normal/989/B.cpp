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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    ll n , p , t = 0;
    string s;
    cin >> n >> p >> s;

    for(ll i = p ; i < n ; i++)
    {
        if(s[i - p] == '.' && s[i] == '.')
        {
            s[i] = '0';
            s[i - p] = '1';
            t = 1;
        }
        else if(s[i] == '.')
        {
            s[i] = (s[i - p] == '1' ? '0' : '1');
            t = 1;
        }
        else if(s[i - p] == '.')
        {
            s[i - p] = (s[i] == '1' ? '0' : '1');
            t = 1;
        }
        else if(s[i] != s[i - p])
        {
            t = 1;
        }
    }
    if(!t)  return cout << "NO" << endl ,0;

    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '.')
        {
            s[i] = '0';
        }
    }
    cout << s << endl;

    return 0;
}