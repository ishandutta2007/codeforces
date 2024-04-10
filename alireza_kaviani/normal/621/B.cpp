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

const int MAXN = 2500;
ll cnt1[MAXN] , cnt2[MAXN];

int main()
{
    fast_io;

    ll n , ans = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        cnt1[x + y]++;
        cnt2[(1000 - y + 1) + x]++;
    }

    for(int i = 0 ; i < MAXN ; i++)     ans += (cnt1[i] * (cnt1[i] - 1) / 2) + (cnt2[i] * (cnt2[i] - 1) / 2);
    cout << ans << endl;

    return 0;
}