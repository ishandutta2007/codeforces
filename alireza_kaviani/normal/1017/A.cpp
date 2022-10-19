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

bool cmp(pii a , pii b)
{
    if(a.X == b.X)  return a.Y < b.Y;
    return a.X > b.X;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    vector<pii> vec;
    for(int i = 0 ; i < n ; i++)
    {
        int a , b , c , d;
        cin >> a >> b >> c >> d;
        vec.push_back({a + b + c + d , i});
    }
    sort(all(vec) , cmp);

    for(int i = 0 ; i < n ; i++)
    {
        if(vec[i].Y == 0)  return cout << i + 1 << endl , 0;
    }

    return 0;
}