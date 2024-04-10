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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e3 + 10;
ll n , cnt = 0;
pll h[MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++) h[i] = {input() , i + 1};
    sort(h , h + n);

    for(ll i = 1 ; i < n ; i++)
    {
        if(h[i].X == h[i - 1].X)    cnt++;
    }
    if(cnt < 2) return cout << "NO" << endl , 0;

    cnt = 0;
    cout << "YES" << endl;
    for(ll i = 0 ; i < n ; i++) cout << h[i].Y << ends;
    cout << endl;
    for(ll i = 0 ; i < n - 1 ; i++)
    {
        if(h[i].X == h[i + 1].X && cnt != 2)
        {
            swap(h[i] , h[i + 1]);
            for(ll j = 0 ; j < n ; j++) cout << h[j].Y << ends;
            cout << endl;
            swap(h[i] , h[i + 1]);
            cnt++;
        }
    }

    return 0;
}