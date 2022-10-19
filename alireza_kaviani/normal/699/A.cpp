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

    int n , ans = 2e9;
    string s;
    cin >> n >> s;

    int a[n];
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1 ; i < n ; i++)
    {
        int x = a[i - 1] , y = a[i];

        if(x <= y && s[i - 1] == 'R' && s[i] == 'L')
        {
            ans = min(ans , abs(x - y) / 2);
        }
        if(x >= y && s[i - 1] == 'L' && s[i] == 'R')
        {
            ans = min(ans , abs(x - y) / 2);
        }
    }
    cout << (ans == 2e9 ? -1 : ans) << endl;

    return 0;
}