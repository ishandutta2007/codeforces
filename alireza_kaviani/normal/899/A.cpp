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

int cnt[3];

int main()
{
    fast_io;

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)    cnt[input()]++;
    if(cnt[1] < cnt[2])
    {
        cout << cnt[1] << endl;
    }
    else
    {
        cout << cnt[2] + (cnt[1] - cnt[2]) / 3 << endl;
    }

    return 0;
}