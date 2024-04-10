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

    int n , m , ans , k;
    cin >> n >> m;
    ans = n - m + n - 1;

    for(int i = 0 ; i < m ; i++)
    {
        cin >> k;
        int a[k];
        for(int j = 0 ; j < k ; j++)    cin >> a[j];
        if(a[0] == 1)
        {
            int j = 1;
            while(a[j] == a[j - 1] + 1 && j < k)    j++;
            ans -= j * 2 - 2;
        }
    }
    cout << ans << endl;

    return 0;
}