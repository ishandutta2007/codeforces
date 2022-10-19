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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}

int main()
{
    fast_io;

    int n , sum = 0 , ind = 0;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        sum += a[i];
        if(a[i] < a[ind])
        {
            ind = i;
        }
    }
    Sort(a);

    if(a[0] == (sum - a[0]) || n == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << endl << ind + 1 << endl;

    return 0;
}