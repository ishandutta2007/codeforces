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

const int MAXN = 3e3 + 10;
bool prime[MAXN];

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    fill(prime , prime + MAXN , 1);
    for(int i = 2 ; i * i <= n ; i++)
    {
        if(prime[i])
        {
            for(int j = i * i ; j <= n ; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        int PD = 0;
        for(int j = 2 ; j <= i ; j++)
        {
            PD += (i % j == 0 && prime[j]);
        }
        ans += (PD == 2);
    }
    cout << ans << endl;

    return 0;
}