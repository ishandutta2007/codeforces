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

int cnt[200];

int main()
{
    fast_io;

    int n , x , ans = 0;
    cin >> n >> x;

    for(int i = 0 ; i < n ; i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
    }

    for(int i = 0 ; i < x ; i++)
    {
        ans += (cnt[i] == 0);
    }

    cout << ans + (cnt[x] != 0) << endl;

    return 0;
}