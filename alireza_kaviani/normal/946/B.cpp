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

int main()
{
    ll n,m;
    cin >> n >> m;
    while(n!=0 && m!=0)
    {
        if(n>=2*m)
        {

            n%=2*m;
        }
        else if(m>=2*n)
        {
            m%=2*n;
        }
        else
        {
            break;
        }
    }

    cout << n << ends << m << endl;
    return 0;
}