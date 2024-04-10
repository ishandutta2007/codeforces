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

const int inf = 1 << 30;
map<int , int> mp;

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(int i = 0 ; i < n ; i++)
    {
        bool can = 0;
        for(int j = 1 ; ; j *= 2)
        {
            int x = j - a[i];
            if(x == 0)  continue;
            if(x == a[i] && mp[a[i]] >= 2)  can = 1;
            else if(x != a[i] && mp[x] >= 1) can = 1;

            if(j == inf)    break;
        }
        if(can == 0)    ans++;
    }
    cout << ans << endl;

    return 0;
}