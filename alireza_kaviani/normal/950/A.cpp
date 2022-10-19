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
    int l,r,a;
    cin >> l  >> r >> a;
    if(l>r)
    {
        r+=a;
        if(r>l)
        {
            a=r-l;
            r=l;
        }
        else
        {
            a=0;
        }
    }
    if(r>l)
    {
        l+=a;
        if(l>r)
        {
            a=l-r;
            l=r;
        }
        else
        {
            a=0;
        }
    }

    int t=min(r,l)*2;
    t+=a/2*2;
    cout << t << endl;

    return 0;
}