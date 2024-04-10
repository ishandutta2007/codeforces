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
inline int input(){char n; cin >> n ; return n - 48;}

int main()
{
    fast_io;

    int n , cnt = 2;
    cin >> n;

    vector<int> a(n) , b(n);
    for(int i = 0 ; i < n ; i++)    a[i] = input();
    for(int i = 0 ; i < n ; i++)    b[i] = input();
    Sort(a);
    Sort(b);

    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] <= b[i])
        {
            cnt = 1;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] >= b[i])
        {
            cnt --;
            break;
        }
    }
    cout << (cnt == 0 ? "NO" : "YES") << endl;

    return 0;
}