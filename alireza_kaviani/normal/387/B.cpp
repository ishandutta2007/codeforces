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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2)));}

int main()
{
    fast_io;

    int n , m , i = 0 , j = 0 , ans = 0;
    cin >> n >> m;

    int a[n] , b[m];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < m ; i++)    cin >> b[i];

    sort(a , a + n);
    sort(b , b + m);

    while(i < n && j < m)
    {
        if(a[i] <= b[j])    {i++ ; j++ ;}
        else    j++;
    }
    cout << n - i;

    return 0;
}