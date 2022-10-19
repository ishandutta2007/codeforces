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
#define Mp                           make_pair
#define endt                        '\t'
#define ends

int main()
{
    int n,m;
    cin >> n >> m;

    double ans=1e8;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin >> a >> b;

        ans=min(ans,a/b);
    }

    printf("%.6f",ans*m);

    return 0;
}