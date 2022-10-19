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

    int cnt[3] , n;
    cin >> n >> cnt[1] >> cnt[2];

    for(int i = 0 ;i < n ; i++)
    {
        int x;
        cin >> x;
        if(cnt[x] > 0 || x == 1)
        {
            cnt[x]--;
        }
        else
        {
            cnt[1]--;
        }
    }

    cout << abs(min(cnt[1] , 0) + min(cnt[2] , 0)) << endl;


    return 0;
}