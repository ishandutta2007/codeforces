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

int main()
{
    fast_io;

    int r , d , n , ans = 0;
    cin >> r >> d >> n;

    for(int i = 0 ;i < n ; i++)
    {
        int x , y , z;
        cin >> x >> y >> z;

        int dis = x * x + y * y;
        if(dis <= (r - z) * (r - z) && z <= r)
        {
            if(dis >= (r - d + z) * (r - d + z))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}