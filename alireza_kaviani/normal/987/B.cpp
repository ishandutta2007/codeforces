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

    int x , y;
    cin >> x >> y;

    if(x == y || (x == 2 && y == 4) || (x == 4 && y == 2))
    {
        cout << "=" << endl;
    }
    else if((x == 2 && y == 3) || (x == 1 && y != 1))
    {
        cout << "<" << endl;
    }
    else if((x == 3 && y == 2) || (x != 1 && y == 1))
    {
        cout << ">" << endl;
    }
    else if(x < y)
    {
        cout << ">" << endl;
    }
    else
    {
        cout << "<" << endl;
    }

    return 0;
}