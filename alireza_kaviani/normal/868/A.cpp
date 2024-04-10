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

ll n , cnt[2][26];
string s;

int main()
{
    fast_io;

    cin >> s >> n;
    for(int i = 0 ; i < n ; i++)
    {
        string t;
        cin >> t;
        if(t == s)  return cout << "YES" << endl , 0;
        cnt[0][t[0] - 97]++;
        cnt[1][t[1] - 97]++;
    }
    if(cnt[0][s[1] - 97] && cnt[1][s[0] - 97])  return cout << "YES" << endl , 0;
    cout << "NO" << endl;

    return 0;
}