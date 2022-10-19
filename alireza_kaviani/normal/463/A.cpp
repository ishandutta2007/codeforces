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

bool check(pii p , int k)
{
    return p.X > k || (p.X == k && p.Y != 0);
}

int main()
{
    fast_io;

    int n , k , ans = 0;
    cin >> n >> k;
    vector<pii> vec;
    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
    }
    Sort(vec);
    if(check(vec[0] , k))
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!check(vec[i] , k) && vec[i].Y != 0)
        {
            ans = max(ans , 100 - vec[i].Y);
        }
    }
    cout << ans << endl;

    return 0;
}