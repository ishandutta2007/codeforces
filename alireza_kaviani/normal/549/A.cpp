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

bool ok(vector<char> s)
{
    map<char , int> mp;
    for(int i = 0 ;i < 4 ; i++)
    {
        mp[s[i]] ++;
    }
    return mp['f'] & mp['a'] & mp['c'] & mp['e'];
}

int main()
{
    fast_io;

    int n , m , ans = 0;
    cin >> n >> m;

    string s[n];
    for(int i = 0 ;i < n ;i++)
    {
        cin >> s[i];
    }

    for(int i = 0 ;i < n - 1 ; i++)
    {
        for(int j = 0 ;j < m - 1 ; j++)
        {
            if(ok({s[i][j] , s[i + 1][j] , s[i][j + 1] , s[i + 1][j + 1]}))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}