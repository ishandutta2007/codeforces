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

const int MAXN = 1e5 ;
int mp1[MAXN] , mp2[MAXN];

int main()
{
    fast_io;

    int n , x , ans = 10;
    cin >> n >> x;

    for(int i = 0 ; i < n ; i++)
    {
        int a;
        cin >> a;
        mp1[a]++;
        mp2[a & x]++;
    }
    for(int i = 0 ; i <= MAXN ; i++)
    {
        if(mp1[i] >= 2) ans = min(ans , 0);
        else if(mp1[i] >= 1 && mp2[i] >= 1 && (!(mp1[i] == 1 && mp2[i] == 1 && i == (i & x))))    ans = min(ans , 1);
        else if(mp2[i] >= 2)    ans = min(ans , 2);
    }
    cout << (ans == 10 ? -1 : ans) << endl;

    return 0;
}