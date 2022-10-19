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

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    int a[n][m] , ans[n][m];
    set<int> x , y;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
            if(!a[i][j])
            {
                x.insert(i);
                y.insert(j);
            }
            ans[i][j] = 1;
        }
    }

    for(auto &i : x)
    {
        for(int j = 0 ; j < m ; j++)
        {
            ans[i][j] = 0;
        }
    }
    for(auto &i : y)
    {
        for(int j = 0 ; j < n ; j++)
        {
            ans[j][i] = 0;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(a[i][j])
            {
                int res = 0;
                for(int k = 0 ; k < m ; k++)
                {
                    res |= ans[i][k];
                }
                for(int k = 0 ; k < n ; k++)
                {
                    res |= ans[k][j];
                }
                if(!res)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
    for(int i = 0 ; i < n ; i++ , cout << endl)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout << ans[i][j] << ends;
        }
    }


    return 0;
}