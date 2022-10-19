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

    ll n , k , sum = 0 , t = 0;
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)    sum += input();

    while(1)
    {
        if(sum >= k * n - n / 2)
        {
            cout << t << endl;
            return 0;
        }
        sum += k;
        t++; n++;
    }

    return 0;
}