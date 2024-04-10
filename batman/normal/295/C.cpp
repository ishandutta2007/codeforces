#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int maxix = 1000;
const int inf = 1000000007;
int n50 = 0, n100 = 0;
int nn = 0;
int k;
int ans = 0;
int index = 1;
int mark[60][60];
int mark2[60][60];
vector <pair <int,int> > a[maxix];
vector <int> parent[2550];
int fact[60][60];
int num[60][60];
int dis[60][60];
int dis2[60][60];
int num2[60][60];
void factor (int x, int y)
{
    for (int i=0 ; i<=x ; i++)
        fact[i][0] = 1;
    for (int i=1 ; i<=x ; i++)
    {
        for (int j=1 ; j<=y ; j++)
        {
            if (j == i)
            {
                fact[i][j] = 1;
            }
            if (j < i)
            {
                fact[i][j] = (fact[i-1][j-1] % inf + fact[i-1][j] % inf) % inf;
            }
        }
 
    }
}
int bfs()
{
    a[1].push_back({n50,n100});
    num[n50][n100] = 1;
    num2[n50][n100] = 1;
    while (ans == 0)
    {
        for (auto u : a[index])
        {
            if (u.first == 0)
            {
                if (u.second == 0)
                {
                    ans = index;
                }
            }
            if (index % 2 == 1)
            {
                for (int i=0 ; i<=u.first ; i++)
                {
                    for (int j=0 ; j<=u.second ; j++)
                    {
                        if (i * 50 + j * 100 <= k && i * 50 + j * 100 != 0 && mark[u.first-i][u.second-j] == 0)
                        {
                            a[index+1].push_back({u.first - i,u.second - j});
                            dis[u.first-i][u.second-j] = index + 1;
                            mark[u.first-i][u.second-j] = 1;
                        }
                        if (i * 50 + j * 100 <= k && i * 50 + j * 100 != 0 && dis2[u.first][u.second] < dis[u.first-i][u.second-j])
                            num[u.first-i][u.second-j] = (num[u.first-i][u.second-j] % inf + (((num2[u.first][u.second] % inf) * (fact[u.first][i]) % inf) % inf * (fact[u.second][j]) % inf) % inf) % inf;
 
                    }
                }
            }
            if (index % 2 == 0)
            {
                int a1 = n50 - u.first;
                int a2 = n100 - u.second;
                for (int i=0 ; i<=a1 ; i++)
                {
                    for (int j=0 ; j<=a2 ; j++)
                    {
                        if (i * 50 + j * 100 <= k && i * 50 + j * 100 != 0 && mark2[u.first+i][u.second+j] == 0)
                        {
                            a[index+1].push_back({u.first + i,u.second + j});
                            dis2[u.first+i][u.second+j] = index + 1;
                            mark2[u.first+i][u.second+j] = 1;
                        }
                        if (i * 50 + j * 100 <= k && i * 50 + j * 100 != 0 && dis[u.first][u.second] < dis2[u.first+i][u.second+j])
                            num2[u.first+i][u.second+j] = (num2[u.first+i][u.second+j] % inf + (((num[u.first][u.second] % inf) * (fact[a1][i]) % inf) % inf * (fact[a2][j]) % inf) % inf) % inf;
 
                    }
                }
 
            }
        }
        index++;
    }
}
int arr[55];
main()
{
    int n;
    cin >> n >> k;
    int x;
    for (int i=0 ; i<n ; i++)
    {
        cin >> x;
        if (x == 50)
            n50++;
        else
            n100++;
        arr[i] = x;
    }
    factor(55,55);
    mark[n50][n100] = 1;
    sort(arr,arr+n);
    arr[n] = 0;
    if (arr[n-1] <= k && (arr[0] + arr[1] <= k))
    {
        bfs();
        cout << ans - 1 << "\n";
        int finalans = 1;
        cout << num[0][0] + num2[0][0];
    }
    else
    {
        cout << -1 << "\n" << 0;
    }
}