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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    int n;
    cin >> n;

    vector<int> f(n);
    for(int i=0;i<n;i++)
    {
        cin >> f[i];
        f[i]--;
    }

    for(int i=0;i<n;i++)
    {
        int t = f[f[f[f[i]]]];
        if(t == f[i])
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;


    return 0;
}