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

string s[4];

int cnt(vector<char> c , char key)
{
    int ans = 0;
    for(int i = 0 ; i < 4 ; i++)    ans += (c[i] == key);
    return ans;
}

bool ok(int x , int y)
{
    return cnt({s[x][y] , s[x + 1][y] , s[x][y + 1] , s[x + 1][y + 1]} , '#') != 2;
}

int main()
{
    fast_io;

    cin >> s[0] >> s[1] >> s[2] >> s[3];

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(ok(i , j))
            {
                return cout << "YES" << endl , 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}