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

int f(int n , int m)
{
    int ans = 0;
    while(m % n == 0)
    {
        ans++;
        m /= n;
    }
    if(m != 1)
    {
        return -1;
    }
    return ans;
}

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    int t = f(n , m);
    if(t == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl << t - 1 << endl;
    }

    return 0;
}