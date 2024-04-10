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
    int a,b;
    cin >> a >> b;

    int t=(a+b)/2;
    int ta=abs(a-t) , tb = abs(b-t);
    ta=ta*(ta+1)/2;
    tb=tb*(tb+1)/2;
    cout << ta+tb << endl;


    return 0;
}