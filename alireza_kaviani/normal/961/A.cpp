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

const int MAXN = 2e3 + 10;
int cnt[MAXN];

int main()
{
    fast_io;

    int n , m , ans = 1e9;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ans = min(ans , cnt[i]);
    }
    cout << ans << endl;

    return 0;
}