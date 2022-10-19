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
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    ll n,m;
    cin >> n >> m;

    ll maxn=n-(m-1);
    maxn=maxn*(maxn-1)/2;

    ll div=n/m;
    ll minn=(m*div*(div-1)/2);
    minn+=(n%m)*div;

    cout << minn << ends << maxn;

    return 0;
}