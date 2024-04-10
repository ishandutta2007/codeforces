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

    vector<pii> vec;
    set<int> xs , ys;
    for(int i = 0 ; i < n ; i++)
    {
        xs.insert(input());
        ys.insert(input());
    }
    if(xs.size() != 2 || ys.size() != 2)    return cout << -1 << endl , 0;

    for(auto &x : xs)
    {
        for(auto &y : ys)
        {
            vec.push_back({x , y});
        }
    }
    cout << (vec[3].X - vec[0].X) * (vec[3].Y  - vec[0].Y) << endl;

    return 0;
}