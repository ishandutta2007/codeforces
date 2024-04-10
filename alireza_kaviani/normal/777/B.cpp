#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , fl1 = 0 , fl2 = 0;
    cin >> n;

    int a[n] , b[n];
    for(int i = 0 ; i < n ; i++)    a[i] = input();
    for(int i = 0 ; i < n ; i++)    b[i] = input();

    sort(a , a + n);
    sort(b , b + n);

    for(int i = 0 , j = 0 ; i < n && j < n ; i++ , j++)
    {
        while(j < n && a[i] > b[j]) j++ , fl1++;
    }
    for(int i = 0 , j = 0 ; i < n && j < n ; i++ , j++)
    {
        while(j < n && a[i] >= b[j]) j++ , fl2++;
    }
    cout << fl1 << endl << n - fl2 << endl;

    return 0;
}