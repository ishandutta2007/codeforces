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

const int MAXN = 1e5 + 5;
ll ps[MAXN][2];

int main()
{
    fast_io;

    ll n , q;
    cin >> n;

    vector<int> vec(n) , sec(n);
    for(int i = 0 ;i < n ; i++)
    {
        cin >> vec[i];
        sec[i] = vec[i];
    }

    Sort(sec);
    for(int i = 0 ;i < n ; i++)
    {
        ps[i][0] = (i == 0 ? vec[i] : ps[i - 1][0] + vec[i]);
        ps[i][1] = (i == 0 ? sec[i] : ps[i - 1][1] + sec[i]);
    }

    cin >> q;
    for(int i = 0 ; i < q ;i++)
    {
        int x , l , r;
        cin >> x >> l >> r;
        x--; l--; r--;
        cout << (l == 0 ? ps[r][x] : ps[r][x] - ps[l - 1][x]) << endl;
    }

    return 0;
}