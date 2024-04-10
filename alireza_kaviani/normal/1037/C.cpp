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

    ll n , ans = 0 , cnta = 0;
    string a , b;
    cin >> n >> a >> b;

    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == '1' && b[i] == '1')
        {
            a[i] = '0';
            b[i] = '0';
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        cnta += (a[i] == '1');
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(b[i] == '1')
        {
            if(i != 0 && a[i - 1] == '1')   {ans++ ; a[i - 1] = '0'; b[i] = '0'; cnta --;}
            else if(i != n - 1 && a[i + 1] == '1')  { ans++ ; a[i + 1] = '0'; b[i] = '0';cnta--;}
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(b[i] == '1')
        {
            if(cnta <= 0)   ans++;
            else    ans += 2;
            cnta--;
        }
    }

    cout << ans + max(0LL , cnta) << endl;

    return 0;
}