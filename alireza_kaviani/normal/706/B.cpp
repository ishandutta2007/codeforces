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
    int n,q;

    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }

    Sort(x);
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int m;
        cin >> m;
        cout << upper_bound(all(x),m)-x.begin() << endl;
    }

    return 0;
}