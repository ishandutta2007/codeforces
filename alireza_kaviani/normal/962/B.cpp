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

    int n , a , b , sum;
    string s;
    cin >> n >> a >> b >> s;
    s = "*" + s;
    sum = a + b;
    for(int i = 1 ; i <= n ; i++)
    {
        if(s[i] == '.' && a + b != 0)
        {
            if(s[i - 1] == 'A' && b != 0)   s[i] = 'B' , b--;
            if(s[i - 1] == 'B' && a != 0)   s[i] = 'A' , a--;
            if(s[i - 1] == '*' || s[i - 1] == '.')
            {
                if(a >= b)  s[i] = 'A' , a--;
                else    s[i] = 'B' , b--;
            }
        }
    }
    cout << (sum - (a + b)) << endl;

    return 0;
}