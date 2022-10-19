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

int f(int n)
{
    return (min(abs(1-n),abs(1000*1000-n))==abs(1-n)? 0 : 1);
}

int a[2],b[2];

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;

        int af=f(t);
        if(af==0 && 1>=t)
        {
            a[af]=max(a[af],1-t);
        }
        else if(af==0)
        {
            b[af]=max(b[af],t-1);
        }
        else if(af==1 && 1000*1000>=t)
        {
            a[af]=max(a[af],1000*1000-t);
        }
        else
        {
            b[af]=max(b[af],t-1000*1000);
        }
    }

    int t=a[0]+b[0] , t2=a[1]+b[1];

    cout << max(t,t2) << endl;

    return 0;
}