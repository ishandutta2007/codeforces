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
#define error(x)                    cerr << #x << " = " << x << endl;

int main()
{
    double x,y,n;
    cin >> x >> y >> n;

    double ans=1e9;
    for(int i=0;i<n;i++)
    {
        double x1,y1,t;
        cin >> x1 >> y1 >> t ;
        x1=abs(x-x1);
        y1=abs(y-y1);
        double s=sqrt(x1*x1+y1*y1)/t;
        ans=min(ans,s);
    }
    printf("%.10f",ans);



    return 0;
}