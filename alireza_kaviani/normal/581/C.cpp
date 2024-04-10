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

    int n , k , ans = 0;
    cin >> n >> k;

    vector<pii> vec(n);
    for(int i = 0 ; i < n ; i++)    { cin >> vec[i].Y; vec[i].X = vec[i].Y % 10 ;}
    sort(all(vec) , greater<pii>());

    for(int i = 0 ; i < n ; i++)
    {
        ans += vec[i].Y / 10;
        if(10 - vec[i].X <= k && vec[i].Y != 100)
        {
            ans++;
            k -= 10 - vec[i].X;
        }
    }
    cout << min(n * 10 , ans + k / 10);

    return 0;
}