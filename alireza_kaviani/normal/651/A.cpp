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
int main()
{
    int ans=0 , a , b;
    cin >> a >> b;

    while(a>0 && b>0)
    {
        if(a<b)
        {
            b-=2;
            a++;
        }
        else
        {
            a-=2;
            b++;
        }
        if(min(a,b)<0)break;
        ans++;
    }
    cout << ans;
    return 0;
}