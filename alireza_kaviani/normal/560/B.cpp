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

bool ok(int a , int b , int c , int d , int e , int f)
{
    return (a >= c + e) && (b >= max(d , f));
}

int main()
{
    fast_io;

    int a , b , c , d , e , f;
    cin >> a >> b >> c >> d >> e >> f;
    if(ok(a , b , c , d , e , f) || ok(a , b , d , c , e , f ) || ok(a , b , c , d , f , e) || ok(a , b , d , c , f , e) || ok(b , a , c , d , e , f) || ok(b , a , d , c , e , f ) || ok(b , a , c , d , f , e) || ok(b , a , d , c , f , e))  cout << "YES" << endl;
    else    cout << "NO" << endl;

    return 0;
}