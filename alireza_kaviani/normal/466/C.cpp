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
//#define local_i                     1

int main()
{
    #ifdef local_o
    out;
    #endif // local_o
    #ifdef local_i
    in;
    #endif // local_i

    ll n;
    ll sum=0;
    cin >> n;

    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    if(sum%3!=0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll mid=sum/3 , s=0 , ans=0 , ans2=0;
    for(int i=0;i<n-1;i++)
    {
        s+=a[i];
        if(s==mid*2)
        {
            ans2+=ans;
        }
        if(s==mid)
        {
            ans++;
        }
    }
    cout << ans2;

    return 0;
}