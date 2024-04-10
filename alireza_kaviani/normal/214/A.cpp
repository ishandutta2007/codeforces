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
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    int n,m;
    cin >> n >> m;

    int ans=0;
    for(int a=0;a*a<=n;a++)
    {
        int b=n-a*a;
        if(b*b+a==m)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}