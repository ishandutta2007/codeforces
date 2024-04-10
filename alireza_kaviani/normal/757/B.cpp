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

const int MAXN = 1e5 + 10;
int pr[MAXN] , ok[MAXN];

int main()
{
    fast_io;

    int n , ans = 1;
    cin >> n;

    for(int i = 0 ; i < n ; i++)    { ok[input()]++;}

    for(int i = 2 ; i < MAXN ; i++)
    {
        if(1)
        {
            int cnt = 0;
            for(int j = i ; j < MAXN ; j += i)
            {
                pr[j] = 1;
                cnt += ok[j];
            }
            ans = max(ans , cnt);
        }
    }
    cout << ans << endl;

    return 0;
}