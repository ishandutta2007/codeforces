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
    int n , b=0 , c=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        if(t<0)
        {
            c+=t;
        }
        else
        {
            b+=t;
        }
    }

    cout << b-c << endl;

    return 0;
}