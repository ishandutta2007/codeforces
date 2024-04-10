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

int main()
{
    fast_io;

    int h1 , a1 , c1 , h2 , a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;

    vector<string> ans;
    while(h2 > 0)
    {
        if(h1 > a2 || (h2 - a1 <= 0)) { h2 -= a1; ans.push_back("STRIKE") ;}
        else    { h1 += c1; ans.push_back("HEAL"); }
        h1 -= a2;
    }

    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++)   cout << ans[i] << endl;

    return 0;
}