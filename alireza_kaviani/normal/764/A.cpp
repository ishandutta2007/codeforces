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

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return(gcd(b,a%b));
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    int t=n*m/gcd(n,m);
    cout << k/t;

    return 0;
}