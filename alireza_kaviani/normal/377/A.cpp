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

const int MAXN = 510;
bool visited[MAXN][MAXN];
int t , dx[] = {1 , -1 , 0 , 0} , dy[] = {0 , 0 , 1 , -1};
string s[MAXN];

void dfs(int x , int y)
{
    if(t == 0)
    {
        return;
    }
    s[x][y] = '.';
    t--;
    visited[x][y] = true;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(!visited[x + dx[i]][y + dy[i]] && s[x + dx[i]][y + dy[i]] == 'X')
        {
            dfs(x + dx[i] , y + dy[i]);
        }
    }
}

int main()
{
    fast_io;

    int n , m , cnt = 0;
    cin >> n >> m >> t;

    for(int i = 0 ; i < 2 ; i++)     for(int j = 0 ; j < m + 2 ; j++)   s[i * (n + 1)] += "#";
    for(int i = 1 ; i <= n ;i ++)
    {
            cin >> s[i];
            s[i] = "#" + s[i] + "#";

            for(int j = 0 ; j < s[i].size() ; j++)
            {
                if(s[i][j] == '.')
                {
                    cnt++;
                }
                s[i][j] = (s[i][j] == '.' ? 'X' : s[i][j]);
            }
    }
    t = cnt - t;

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ;j <= m ;j++)
        {
            if(!visited[i][j] && s[i][j] == 'X')
            {
                dfs(i , j);
            }
        }
    }

    for(int i = 1 ; i <= n ;i++ , cout << endl)
    {
        for(int j = 1 ; j <= m; j++)
        {
            cout << s[i][j];
        }
    }

    return 0;
}