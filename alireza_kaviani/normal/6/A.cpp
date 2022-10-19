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

bool tr(int x , int y , int z)
{
    return (x + y > z && x + z > y && y + z > x);
}

bool se(int x , int y , int z)
{
    return (x + y == z || x + z == y || y + z == x);
}

int main()
{
    fast_io;

    int a , b , c , d;
    cin >> a >> b >> c >> d;

    if(tr(a , b , c) || tr(a , b , d) || tr(a , c , d) || tr(b , c , d))
    {
        cout << "TRIANGLE" << endl;
    }
    else if(se(a , b , c) || se(a , b , d) || se(a , c , d) || se(b , c , d))
    {
        cout << "SEGMENT" << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}