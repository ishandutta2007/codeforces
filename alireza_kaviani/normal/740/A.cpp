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

    ll n , a , b , c;
    cin >> n >> a >> b >> c;
    cout << (n % 4 == 0 ? 0 : (n % 4 == 3 ? min({a , b + c , 3LL * c}) : (n % 4 == 2 ? min({2LL * a , b , 2LL * c}) : min({3LL * a , b + a , c})))) << endl;

    return 0;
}