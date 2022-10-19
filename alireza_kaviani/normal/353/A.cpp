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

    int n , sl = 0 , sr = 0 , rot = 0;
    cin >> n;

    for(int i = 0 ; i < n; i++)
    {
        int l , r;
        cin >> l >> r;
        sl += l;
        sr += r;

        if(l % 2 != r % 2)
        {
            rot = 1;
        }
    }

    if(((sl + sr) % 2 == 1) || (sl % 2 == 1 && rot == 0))
    {
        cout << -1 << endl;
    }
    else if((sl + sr) % 2 == 0 && sl % 2 == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }


    return 0;
}