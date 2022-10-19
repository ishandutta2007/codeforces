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

map<int , pii> mp;

int main()
{
    fast_io;

    int k;
    cin >> k;
    vector<int> a[k] , b[k];
    vector<int> sum(k , 0);
    for(int i = 0 ; i < k ; i++)
    {
        int n;
        cin >> n;
        a[i].resize(n);
        for(int j = 0 ;j < n ; j++)
        {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }

        for(int j = 0 ;j < n; j++)
        {
            int t = sum[i] - a[i][j];
            if(mp[t].X == 0 && mp[t].Y == 0 || mp[t].X == i + 1)
            {
                mp[t] = {i + 1 , j + 1};
            }
            else
            {
                cout << "YES" << endl << mp[t].X << ends << mp[t].Y << endl << i + 1 << ends << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}