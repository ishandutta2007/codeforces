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

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0;i < n ; i++)
    {
        cin >> vec[i];
    }

    Sort(vec);

    for(int i = 0; i < n / 2 ; i++)
    {
        if(vec[i] != vec[0])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i = n / 2; i < n ; i++)
    {
        if(vec[i] != vec[n / 2])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if(vec[0] == vec[n - 1])
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl << vec[0] << ends << vec[n - 1] << endl;

    return 0;
}