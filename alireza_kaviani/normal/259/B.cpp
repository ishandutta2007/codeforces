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

    int sum , a[3][3];
    for(int i = 0 ; i < 3 ; i++)    cin >> a[i][0] >> a[i][1] >> a[i][2];

    sum = (a[0][1] + a[0][2] + a[1][0] + a[1][2] + a[2][0] + a[2][1]) / 2;
    a[0][0] = sum - (a[0][1] + a[0][2]);
    a[1][1] = sum - (a[1][0] + a[1][2]);
    a[2][2] = sum - (a[2][0] + a[2][1]);

    for(int i = 0 ; i < 3 ; i++ , cout << endl)
    {
        for(int j = 0 ; j < 3 ; j++)    cout << a[i][j] << ends;
    }

    return 0;
}