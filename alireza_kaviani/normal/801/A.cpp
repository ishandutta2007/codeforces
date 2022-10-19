#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

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

int cnt(string s)
{
    int ans = 0;
    for(int i = 0 ; i <= s.size() - 2 ; i++)
    {
        if(s.substr(i , 2) == "VK") ans++;
    }
    return ans;
}

int main()
{
    fast_io;

    int ans = 0;
    string s;
    cin >> s;
    if(s.size() == 1)   return cout << 0 << endl , 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        s[i] = (s[i] == 'V' ? 'K' : 'V');
        ans = max(ans , cnt(s));
        s[i] = (s[i] == 'V' ? 'K' : 'V');
    }
    ans = max(ans , cnt(s));
    cout << ans << endl;

    return 0;
}