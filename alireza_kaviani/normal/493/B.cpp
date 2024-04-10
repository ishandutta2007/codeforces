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

int main()
{
    fast_io;

    int n;
    cin >> n;

    vector<int> f , s;
    ll a[n] , sf = 0 , ss = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(a[i] > 0)    f.push_back(a[i]) , sf += a[i];
        if(a[i] < 0)    s.push_back(abs(a[i])) , ss += abs(a[i]);
    }
    cout << (ss < sf || (ss == sf && s < f) || (ss == sf && s == f && a[n - 1] > 0) ? "first" : "second") << endl;
    return 0;
}