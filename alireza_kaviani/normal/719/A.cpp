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
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    if(a[n-1]==0)
    {
        cout << "UP";
    }
    else if(a[n-1]==15)
    {
        cout << "DOWN";
    }
    else if(n==1)
    {
        cout << -1 << endl;
    }
    else if(a[n-1]>a[n-2] && a[n-1]!=15)
    {
        cout << "UP";
    }
    else
    {
        cout << "DOWN";
    }

    return 0;
}