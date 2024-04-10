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
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define out                         freopen("out.txt","w",stdout)
#define in                          freopen("in.txt","r",stdin)
//#define local                       1

int main()
{
    #ifdef local
    in;out;
    #endif // local
    int n;
    cin >> n;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<(n-i);j++)
        {
            cout << "  ";
        }

        for(int j=0;j<=i;j++)
        {
            cout << j << ((i!=0)?" ":"");
        }

        for(int j=i-1;j>=0;j--)
        {
            cout << j << ((j!=0)?" ":"");
        }
        cout << endl;
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<(n-i);j++)
        {
            cout << "  ";
        }

        for(int j=0;j<=i;j++)
        {
            cout << j << ((i!=0)?" ":"");
        }

        for(int j=i-1;j>=0;j--)
        {
            cout << j << ((j!=0)?" ":"");
        }
        cout << endl;
    }

    return 0;
}