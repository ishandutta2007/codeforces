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

    int n, s;
    cin >> n >> s;

    vector<int> t(n + 1);
    t[0] = 0;
    for(int i = 1; i <= n ; i++)
    {
        int h , m;
        cin >> h >> m;
        t[i] = h * 60 + m;
    }
    Sort(t);

    if(t[1] > s)
    {
        cout << 0 << ends << 0 << endl;
        return 0;
    }

    for(int i = 1; i < n ; i++)
    {
        if(t[i + 1] > t[i] + s * 2 + 1)
        {
            cout << (t[i] + s + 1) / 60 << ends << (t[i] + s + 1) % 60 << endl;
            return 0;
        }
    }

    cout << (t[n] + s + 1) / 60 << ends << (t[n] + s + 1) % 60 << endl;

    return 0;
}