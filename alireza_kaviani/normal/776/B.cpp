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

    int n;
    cin >> n;

    vector<bool> ok(n + 2 , 0);
    for(int i = 2 ; i <= n + 1 ; i++)
    {
        if(!ok[i])
        {
            for(int j = i * 2 ; j <= n + 1 ; j += i)
            {
                ok[j] = 1;
            }
        }
    }

    if(n < 3)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }

    for(int i = 2 ; i <= n + 1 ; i++)
    {
        cout << (ok[i] == 1? 2 : 1) << ends;
    }

    return 0;
}