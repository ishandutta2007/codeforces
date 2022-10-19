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

    int n , x , y , z = 0, ans = 0;
    cin >> n >> x >> y;

    for(int i = 0 ; i < n ; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            if(x != 0)  x--;
            else if(y != 0) {y-- ; z++ ;}
            else if(z != 0) z--;
            else    ans++;
        }
        if(t == 2)
        {
            if(y != 0)  y--;
            else    ans += 2;
        }
    }
    cout << ans << endl;

    return 0;
}