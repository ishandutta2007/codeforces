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

    int c , v0 , v1 , a , l , vnow , ans = 0;
    cin >> c >> v0 >> v1 >> a >> l;

    vnow = v0;
    while(c > 0)
    {
        if(ans > 0) c += l;
        c -= vnow;
        vnow = min(v1 , vnow + a);
        ans++;
    }

    cout << ans << endl;

    return 0;
}