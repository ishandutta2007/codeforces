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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n;
    cin >> n;

    int a[n] , b[n];
    for(int i = 0 ; i < n ; i++)    a[i] = b[i] = input();
    sort(b , b + n);

    for(int i = 0 ; i < n ; i++)
    {
        int ind = 0;
        for(int j = i ; j < n ; j++)
        {
            if(a[j] == b[i])
            {
                ind = j;
                break;
            }
        }

        for(int j = ind ; j > i ; j--)
        {
            cout << j << ends << j + 1 << endl;
            swap(a[j] , a[j - 1]);
        }
    }

    return 0;
}