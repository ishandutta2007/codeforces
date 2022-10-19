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

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;
    bool prime[m + 1];
    for(int i = 0; i <= m ; i++)
    {
        prime[i] = 0;
    }
    prime[1] = 1;
    for(int i = 2; i <= m ; i++)
    {
        if(prime[i] == 1)
        {
            continue;
        }
        for(int j = i * i ; j <= m ; j += i)
        {
            prime[j] = 1;
        }
    }

    if(prime[m] == 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = n + 1; i < m ;i++)
    {
        if(prime[i] != 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}