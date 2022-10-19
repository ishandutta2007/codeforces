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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

map<int , int> cnt;

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)    cnt[input()]++;

    for(int i = m ; i >= 1 ; i--)
    {
        int t = 0;
        for(map<int , int>::iterator it = cnt.begin() ; it != cnt.end() ; it++)
        {
            t += (it -> Y) / i;
        }
        if(t >= n)  return cout << i << endl , 0;
    }
    cout << 0 << endl;

    return 0;
}