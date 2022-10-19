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
    ll n,m;
    cin >> n >> m;

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        char c;
        ll t;
        cin >> c >> t;
        if(c=='-')
        {
            if(t>m)
            {
                ans++;
            }
            else
            {
                m-=t;
            }
        }
        else
        {
            m+=t;
        }
    }
    cout << m << ends << ans;

    return 0;
}