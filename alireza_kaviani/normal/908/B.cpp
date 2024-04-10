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

const int MAXN = 75;
int n , m , ans = 0 , sx , sy , ex , ey , p[] = {0 , 1 , 2 , 3} , dx[] = {1 , -1 , 0 , 0} , dy[] = {0 , 0 , 1 , -1};
string s[MAXN] , d;

int check()
{
    int nx = sx , ny = sy;

    for(int i = 0 ; i < d.size() ; i++)
    {
        nx += dx[p[d[i] - 48]];
        ny += dy[p[d[i] - 48]];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#')
        {
            return 0;
        }
        if(s[nx][ny] == 'E')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(int j = 0 ; j < m ; j++)
        {
            if(s[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if(s[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }
    cin >> d;

    do
    {
        ans += check();
    }while(next_permutation(p , p + 4));

    cout << ans << endl;

    return 0;
}