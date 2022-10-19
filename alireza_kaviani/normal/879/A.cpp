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

int f(int x , int y)
{
    return (x == 0 ? x + y : x);
}

int main()
{
    fast_io;

    int n , now = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        now = max(x , now + f((x + y - now % y) % y , y));
    }
    cout << now << endl;

    return 0;
}