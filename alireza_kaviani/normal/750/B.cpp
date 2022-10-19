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

    int n , pos = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int t;
        string dir;
        cin >> t >> dir;

        if(dir == "North")
        {
            if(pos - t < 0)
            {
                cout << "NO" << endl;
                return 0;
            }
            pos -= t;
        }
        else if(dir == "South")
        {
            if(pos + t > 20000)
            {
                cout << "NO" << endl;
                return 0;
            }
            pos += t;
        }
        else if(pos % 20000 == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if(pos == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}